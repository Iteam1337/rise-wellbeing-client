[@react.component]
let make =
    (
      ~width: option(string)=?,
      ~height: option(string)=?,
      ~fill: option(string)=?,
      ~stroke: option(string)=?,
    ) => <svg viewBox="0 0 20 20" ?width ?height ?fill ?stroke> <path d="M10 3.22l-.61-.6a5.5 5.5 0 0 0-7.78 7.77L10 18.78l8.39-8.4a5.5 5.5 0 0 0-7.78-7.77l-.61.61z"/> </svg>;
