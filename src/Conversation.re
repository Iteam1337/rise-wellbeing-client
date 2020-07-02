open Bindings;

type answer =
  | Text(string)
  | SelectOption(Shared.Question.selectOption);

type action =
  | Answer(answer);

type state = {
  questionIndex: int,
  answeredQuestions: list(Shared.Question.question),
  questions: list(Shared.Question.question),
};

let initialState = questions => {
  answeredQuestions: [],
  questionIndex: 0,
  questions,
};

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

    let answeredQuestions =
      updatedQuestions
      ->List.splitAt(state.questionIndex + 1)
      ->Option.mapWithDefault([], ((previousQuestions, _remainingQuestions)) =>
          previousQuestions
        );

    {
      answeredQuestions,
      questions: updatedQuestions,
      questionIndex: state.questionIndex + 1,
    };
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

[@genType]
[@react.component]
let make =
    (~questions: list(Shared.Question.question), ~onNextQuestion=_ => ()) => {
  let sentryNodeRef = React.useRef(Js.Nullable.null);

  let (state, dispatch) =
    React.useReducer(reducer, initialState(questions));

  let questionToRender = state.questions->List.get(state.questionIndex);

  React.useEffect1(
    () => {
      sentryNodeRef.current
      ->Js.Nullable.toOption
      ->Option.mapWithDefault((), onNextQuestion);

      None;
    },
    [|state.questionIndex|],
  );

  <Layout.Container
    classNames={String.concat(
      " ",
      [[%tw "h-full overflow-y-scroll px-6"], ""],
    )}>
    <Layout.Column spacing=`Small classNames=[%tw "py-8 pb-16"]>
      <Framer.AnimatePresence initial=false>
        {state.answeredQuestions
         ->List.map(question => {
             let id =
               switch (question) {
               | Select({id, _}) => id
               | Text({id, _}) => id
               };
             <Framer.Motion.div
               key=id
               positionTransition=false
               initial={"opacity": 1, "y": 0, "scale": 1}
               animate={"opacity": 1, "y": 0, "scale": 1}
               exit={
                 "opacity": 1,
                 "scale": 1,
                 "transition": {
                   "duration": 0.5,
                 },
               }>
               {questionToReactElement(
                  question,
                  ~immediate=false,
                  ~delayed=false,
                )}
             </Framer.Motion.div>;
           })
         ->List.toArray
         ->React.array}
      </Framer.AnimatePresence>
      {questionToRender->Option.mapWithDefault(
         React.null,
         questionToReactElement(~immediate=false, ~delayed=true),
       )}
      <span
        className=[%tw "h-0"]
        ref={ReactDOMRe.Ref.domRef(sentryNodeRef)}
      />
    </Layout.Column>
    <div
      key={state.questionIndex->string_of_int}
      className={String.concat(
        " ",
        [
          [%tw
            "fixed bottom-0 pb-20 right-0 left-0 p-6 md:max-w-screen-lg mx-auto"
          ],
          "fade-in-delay-answer",
        ],
      )}>
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
