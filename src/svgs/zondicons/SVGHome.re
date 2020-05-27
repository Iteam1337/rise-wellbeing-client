[@react.component]
let make =
    (
      ~width: option(string)=?,
      ~height: option(string)=?,
      ~fill: option(string)=?,
      ~stroke: option(string)=?,
    ) => <svg viewBox="0 0 20 20" ?width ?height ?fill ?stroke> <path d="M8 20H3V10H0L10 0l10 10h-3v10h-5v-6H8v6z"/> </svg>;
