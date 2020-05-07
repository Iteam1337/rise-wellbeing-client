module Container = {
  [@react.component]
  let make = (~children, ~className=?) => {
    <section className={Cn.unpack(className)}> children </section>;
  };
};

module Column = {
  [@react.component]
  let make = (~children) => {
    <section className=[%tw "grid gap-4"]> children </section>;
  };
};
