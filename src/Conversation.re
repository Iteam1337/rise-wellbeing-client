open Belt;

type answer =
  | Text(string)
  | SelectOption(Shared.Question.selectOption);

type action =
  | Answer(answer)
  | UpdateInput(string);

type state = {
  questionIndex: int,
  inputValue: string,
  questions: list(Shared.Question.question),
};

let initialState = questions => {questionIndex: 0, inputValue: "", questions};

let reducer = (state, action) =>
  switch (action) {
  | Answer(answer) =>
    let updatedQuestions =
      switch (answer) {
      | SelectOption(selectOption) =>
        state.questions
        ->List.mapWithIndex((index, question) =>
            if (state.questionIndex == index) {
              switch (question) {
              | Select({id, answer, message, options}) =>
                Shared.Question.Select({
                  id,
                  message,
                  options,
                  answer: Some(answer->Option.getWithDefault(selectOption)),
                })
              | _ => assert(false)
              };
            } else {
              question;
            }
          )
      | Text(inputValue) =>
        state.questions
        ->List.mapWithIndex((index, question) =>
            if (state.questionIndex == index) {
              switch (question) {
              | Text({id, messages, answer, answerPlaceholder}) =>
                Shared.Question.Text({
                  id,
                  answerPlaceholder,
                  messages,
                  answer: Some(answer->Option.getWithDefault(inputValue)),
                })
              | _ => assert(false)
              };
            } else {
              question;
            }
          )
      };

    {
      questions: updatedQuestions,
      inputValue: "",
      questionIndex: state.questionIndex + 1,
    };
  | UpdateInput(newValue) => {...state, inputValue: newValue}
  };

let questionToReactElement = (~immediate, ~delayed, question) => {
  switch (question) {
  | Shared.Question.Text({id, messages, answer}) =>
    let questionToRender =
      <Layout.Column spacing=`None key=id>
        {messages
         ->List.map(message =>
             <Elements.MessageBubble
               key=message animate={!immediate} animationDelayed=delayed>
               {React.string(message)}
             </Elements.MessageBubble>
           )
         ->List.toArray
         ->React.array}
      </Layout.Column>;

    switch (answer) {
    | Some(answer) =>
      <Layout.Column spacing=`Small key=id>
        questionToRender
        <Elements.MessageBubble align=`Right color=`Contrast>
          {React.string(answer)}
        </Elements.MessageBubble>
      </Layout.Column>
    | None => questionToRender
    };
  | Select({id, message, answer, _}) =>
    let questionToRender =
      <Layout.Column spacing=`Small key=id>
        <Elements.MessageBubble
          key=message animate={!immediate} animationDelayed=delayed>
          {React.string(message)}
        </Elements.MessageBubble>
      </Layout.Column>;

    switch (answer) {
    | Some(answer) =>
      <Layout.Column spacing=`Small key=id>
        questionToRender
        <Elements.MessageBubble align=`Right color=`Contrast>
          {React.string(answer.text)}
        </Elements.MessageBubble>
      </Layout.Column>
    | None => questionToRender
    };
  };
};

[@react.component]
let make = (~questions: list(Shared.Question.question)) => {
  let (state, dispatch) =
    React.useReducer(reducer, initialState(questions));

  let questionToRender = state.questions->List.get(state.questionIndex);

  let answeredQuestions =
    state.questions
    ->List.splitAt(state.questionIndex)
    ->Option.mapWithDefault([], ((previousQuestions, _remainingQuestions)) =>
        previousQuestions
      );

  <Layout.Container>
    <Layout.Column spacing=`Small>
      {answeredQuestions
       ->List.map(questionToReactElement(~immediate=true, ~delayed=false))
       ->List.toArray
       ->React.array}
      {questionToRender->Option.mapWithDefault(
         React.null,
         questionToReactElement(~immediate=false, ~delayed=true),
       )}
    </Layout.Column>
    <div
      className=[%tw
        "fixed bottom-0 right-0 left-0 p-6 md:max-w-screen-lg mx-auto"
      ]>
      {switch (questionToRender) {
       | Some(Shared.Question.Text({answerPlaceholder, _})) =>
         <form
           onSubmit={event => {
             event->ReactEvent.Form.preventDefault;
             dispatch(Answer(Text(state.inputValue)));
           }}>
           <Elements.Input
             value={state.inputValue}
             label=""
             onBlur=ignore
             onChange={event =>
               dispatch(UpdateInput(event->ReactEvent.Form.target##value))
             }
             placeholder={answerPlaceholder->Option.getWithDefault("")}
           />
         </form>
       | Some(Select({options, _})) =>
         <Layout.Row spacing=`None classNames=[%tw " justify-center"]>
           {options
            ->List.map(selectOption =>
                <Elements.BubbleOption
                  key={selectOption.text}
                  onClick={_e => SelectOption(selectOption)->Answer->dispatch}>
                  {selectOption.text}
                </Elements.BubbleOption>
              )
            ->List.toArray
            ->React.array}
         </Layout.Row>
       | None => React.null
       }}
    </div>
  </Layout.Container>;
};
