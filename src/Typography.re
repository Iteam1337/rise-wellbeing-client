module H1 = {
  [@genType]
  [@react.component]
  let make = (~children) => {
    <h1 className=[%tw "text-3xl md:text-3xl font-bold mb-2 md:mb-4"]>
      children
    </h1>;
  };
};

module H2 = {
  [@genType]
  [@react.component]
  let make = (~children) => {
    <h2
      className=[%tw
        "text-gray-700 text-2xl md:text-2xl mb-2 md:mb-4 font-bold"
      ]>
      children
    </h2>;
  };
};

module Leading = {
  [@genType]
  [@react.component]
  let make = (~children) => {
    <p className=[%tw "text-base mb-2 md:mb-4 text-gray-700 font-medium"]>
      children
    </p>;
  };
};

module P = {
  [@genType]
  [@react.component]
  let make = (~children) => {
    <p className=[%tw "text-base mb-2 md:mb-4 text-gray-700"]> children </p>;
  };
};

module Quote = {
  [@genType]
  [@react.component]
  let make = (~children) => {
    <h2
      className=[%tw
        "text-gray-700 text-2xl md:text-2xl mb-2 md:mb-4 font-bold italic text-center"
      ]>
      children
    </h2>;
  };
};
