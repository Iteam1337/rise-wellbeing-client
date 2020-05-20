open TestFramework;

module Rtl = ReactTestingLibrary;

describe("LandingPage", ({test}) => {
  test("renders", ({expect}) => {
    let element = Rtl.render(<LandingPage />);

    let result = element->Rtl.getByText(~matcher=`Str("Digital Plattform"));

    expect.value(result).toMatchSnapshot();
  })
});
