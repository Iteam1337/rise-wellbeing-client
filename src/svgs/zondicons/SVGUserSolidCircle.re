[@react.component]
let make =
    (
      ~width: option(string)=?,
      ~height: option(string)=?,
      ~fill: option(string)=?,
      ~stroke: option(string)=?,
    ) => <svg viewBox="0 0 20 20" ?width ?height ?fill ?stroke> <path d="M10 20a10 10 0 1 1 0-20 10 10 0 0 1 0 20zM7 6v2a3 3 0 1 0 6 0V6a3 3 0 1 0-6 0zm-3.65 8.44a8 8 0 0 0 13.3 0 15.94 15.94 0 0 0-13.3 0z"/> </svg>;
