let questions = [%raw {j| require("../categorisation.json") |j}];
let q =
  questions##questions
  ->Belt.Array.map(Shared.Question.question_decode)
  ->Belt.Array.keepMap(x => {
      Js.log(x);
      x->Belt.Result.mapWithDefault(None, x => Some(x));
    });

let one =
  Shared.Question.Text({
    id: "1",
    messages: ["Hi there!", "What's your name?"],
    answer: None,
    answerPlaceholder: Some("e.g. Karen Elizabeth"),
  });

let two =
  Shared.Question.Text({
    id: "2",
    messages: ["And your favourite food?"],
    answer: None,
    answerPlaceholder: Some("e.g. Bananas, Yakiniku"),
  });

let three =
  Shared.Question.Select({
    id: "3",
    message: "Do you like bananas?",
    options: [{text: "Yes", value: "yes"}, {text: "No", value: "no"}],
    answer: None,
  });

[@react.component]
let make = () => {
  <Layout.Container spacing=`Small>
    <Layout.Column spacing=`Large>
      <Typography.H1> {React.string("Categorise")} </Typography.H1>
      <Conversation questions={q->Belt.List.fromArray} />
    </Layout.Column>
  </Layout.Container>;
};