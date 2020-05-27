open TestFramework;

module Rtl = ReactTestingLibrary;
module Dtl = DomTestingLibrary;

describe("MyProfilePage", ({test}) => {
  test("renders", ({expect, _}) => {
    let element = Rtl.render(<MyProfilePage />);

    let result = element->Rtl.getByText(~matcher=`Str("Min profil"));

    expect.value(result).toMatchSnapshot();
  })
});
