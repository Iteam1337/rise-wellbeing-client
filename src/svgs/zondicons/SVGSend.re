[@react.component]
let make =
    (
      ~width: option(string)=?,
      ~height: option(string)=?,
      ~fill: option(string)=?,
      ~stroke: option(string)=?,
    ) => <svg viewBox="0 0 20 20" ?width ?height ?fill ?stroke> <path d="M0 0l20 10L0 20V0zm0 8v4l10-2L0 8z"/> </svg>;
