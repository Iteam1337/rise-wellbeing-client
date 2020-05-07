module H1 = {
  [@react.component]
  let make = (~children) => {
    <h1 className=[%tw "text-2xl md:text-3xl font-bold mb-2 md:mb-4"]>
      children
    </h1>;
  };
};

module H2 = {
  [@react.component]
  let make = (~children) => {
    <h2 className=[%tw "text-gray-700 text-lg md:text-2xl mb-2 md:mb-4"]>
      children
    </h2>;
  };
};

module P = {
  [@react.component]
  let make = (~children) => {
    <p className=[%tw "text-base mb-2 md:mb-4"]> children </p>;
  };
};
