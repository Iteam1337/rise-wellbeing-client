[@react.component]
let make =
    (
      ~width: option(string)=?,
      ~height: option(string)=?,
      ~fill: option(string)=?,
      ~stroke: option(string)=?,
    ) => <svg viewBox="0 0 20 20" ?width ?height ?fill ?stroke> <path d="M10 20a10 10 0 1 1 0-20 10 10 0 0 1 0 20zM7.88 7.88l-3.54 7.78 7.78-3.54 3.54-7.78-7.78 3.54zM10 11a1 1 0 1 1 0-2 1 1 0 0 1 0 2z"/> </svg>;
