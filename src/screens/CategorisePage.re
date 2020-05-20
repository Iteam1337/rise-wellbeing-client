let questions = [%raw {j| require("../categorisation.json") |j}];
let q =
  questions##questions
  ->Belt.Array.map(Shared.Question.question_decode)
  ->Belt.Array.keepMap(q =>
      q->Belt.Result.mapWithDefault(None, q => Some(q))
    );

[@react.component]
let make = () => {
  <Layout.Container
    spacing=`None classNames=[%tw "h-full relative chat-container-bg"]>
    <Layout.Column
      spacing=`Large classNames=[%tw "h-full-bottom-nav content-end pb-24"]>
      <Conversation questions={q->Belt.List.fromArray} />
    </Layout.Column>
  </Layout.Container>;
};
