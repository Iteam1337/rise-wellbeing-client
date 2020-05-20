open TestFramework;

module Rtl = ReactTestingLibrary;
module Dtl = DomTestingLibrary;

describe("CategorisePage", ({testAsync}) => {
  testAsync("renders", ({expect, callback}) => {
    let element = Rtl.render(<CategorisePage />);

    let run = () => {
      let%Async inputField =
        element->Rtl.findByPlaceholderText(~matcher=`Str("t.ex. Kim"));

      Rtl.FireEvent.change(
        inputField,
        ~eventInit={
          "target": {
            "value": "Kim",
          },
        },
      );

      Rtl.FireEvent.submit(inputField);

      let%Async wellbeingQuestion =
        element->Rtl.findByText(
          ~matcher=`Str({j|Hur har du mått den senaste veckan?|j}),
        );

      expect.value(wellbeingQuestion).toMatchSnapshot();

      callback();

      Js.Promise.resolve();
    };

    run()->ignore;

    ();
  })
});
