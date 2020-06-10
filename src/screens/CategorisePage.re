let questions: Js.t('questions) = [%raw
  {| require("../categorisation.json") |}
];

let q =
  questions##questions
  ->Belt.Array.map(Shared.Question.question_decode)
  ->Belt.Array.keepMap(Belt.Result.mapWithDefault(_, None, q => Some(q)));

[@react.component]
let make = (~onNextQuestion=_ => ()) => {
  <Layout.Container
    spacing=`None classNames=[%tw "h-full relative chat-container-bg"]>
    <Layout.Column
      spacing=`Large classNames=[%tw "h-full-bottom-nav content-end pb-24"]>
      <Conversation questions={q->Belt.List.fromArray} onNextQuestion />
    </Layout.Column>
  </Layout.Container>;
};
