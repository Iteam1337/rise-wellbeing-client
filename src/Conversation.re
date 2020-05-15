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

let questionToReactElement = (~immediate, question) => {
  switch (question) {
  | Shared.Question.Text({id, messages, answer}) =>
    let questionToRender =
      <Layout.Column spacing=`None key=id>
        {messages
         ->List.map(message =>
             <Elements.MessageBubble key=message animate={!immediate}>
               {React.string(message)}
             </Elements.MessageBubble>
           )
         ->List.toArray
         ->React.array}
      </Layout.Column>;

    /* switch (answer) { */
    /* | Some(answer) => */
    /*   <Layout.Column spacing=`Small key=id> */
    /*     questionToRender */
    /*     <Elements.MessageBubble */
    /*       align=`Right color=`Contrast animate={!immediate}> */
    /*       {React.string(answer)} */
    /*     </Elements.MessageBubble> */
    /*   </Layout.Column> */
    /* | None => questionToRender */
    /* }; */
    let answerStyling =
      answer->Option.isSome
        ? [%tw "justify-self-end self-end opacity-100"] ++ " fade-in"
        : [%tw "justify-self-end self-end opacity-0"];

    <Layout.Column spacing=`Small key=id>
      questionToRender
      <div className=answerStyling>
        <Elements.MessageBubble
          align=`Right color=`Contrast animate={!immediate}>
          {React.string("")}
        </Elements.MessageBubble>
      </div>
    </Layout.Column>;

  | Select({id, message, answer, _}) =>
    let questionToRender =
      <Layout.Column spacing=`Small key=id>
        <Elements.MessageBubble key=message animate={!immediate}>
          {React.string(message)}
        </Elements.MessageBubble>
      </Layout.Column>;

    let answerComponent =
      switch (answer) {
      | Some(answer) =>
        <div className=[%tw "hidden"]>
          <Elements.MessageBubble
            align=`Right color=`Contrast animate={!immediate}>
            {React.string(answer.text)}
          </Elements.MessageBubble>
        </div>
      | None => questionToRender
      };
    <Layout.Column spacing=`Small key=id>
      questionToRender
      answerComponent
    </Layout.Column>;
  };
};

[@react.component]
let make = (~questions: list(Shared.Question.question)) => {
  let (state, dispatch) =
    React.useReducer(reducer, initialState(questions));

  let questionToRender = state.questions->List.get(state.questionIndex);

  let formerQuestions =
    state.questions
    ->List.splitAt(state.questionIndex)
    ->Option.mapWithDefault([], ((previousQuestions, _remainingQuestions)) =>
        previousQuestions
      );

  <Layout.Container>
    <Layout.Column spacing=`Small>
      {formerQuestions
       ->List.map(questionToReactElement(~immediate=true))
       ->List.toArray
       ->React.array}
      {questionToRender->Option.mapWithDefault(
         React.null,
         questionToReactElement(~immediate=false),
       )}
    </Layout.Column>
    <div
      className=[%tw
        "fixed bottom-0 right-0 left-0 p-4 md:max-w-screen-lg mx-auto"
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
         <Layout.Row spacing=`None>
           {options
            ->List.map(selectOption =>
                <Elements.BubbleOption
                  key={selectOption.text}
                  onClick={_ => SelectOption(selectOption)->Answer->dispatch}>
                  {selectOption.text}
                </Elements.BubbleOption>
              )
            ->List.toArray
            ->React.array}
         </Layout.Row>

       | _ => React.null
       }}
    </div>
  </Layout.Container>;
};
