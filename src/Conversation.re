open Belt;

type answer =
  | Text(string)
  | SelectOption(Shared.Question.selectOption);

type action =
  | Answer(answer);

type state = {
  questionIndex: int,
  questions: list(Shared.Question.question),
};

let initialState = questions => {questionIndex: 0, questions};

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

    {questions: updatedQuestions, questionIndex: state.questionIndex + 1};
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
      key={state.questionIndex->string_of_int}
      className={
        [%tw "fixed bottom-0 right-0 left-0 p-6 md:max-w-screen-lg mx-auto"]
        ++ " fade-in-delay-answer"
      }>
      {switch (questionToRender) {
       | Some(Shared.Question.Text({answerPlaceholder, _})) =>
         <Elements.ChatFormAnswerInput
           placeholder=?answerPlaceholder
           onSubmit={answer => {dispatch(Answer(Text(answer)))}}
         />
       | Some(Select({options, _})) =>
         <Elements.ChatFormAnswerOptions
           options
           onSelect={selectOption =>
             SelectOption(selectOption)->Answer->dispatch
           }
         />
       | None => React.null
       }}
    </div>
  </Layout.Container>;
};
