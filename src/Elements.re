module Input = {
  [@react.component]
  let make =
      (
        ~label,
        ~value,
        ~disabled=false,
        ~onBlur,
        ~onChange,
        ~type_="text",
        ~placeholder="",
        ~errorMessage=None,
      ) => {
    <div className=[%tw "flex flex-col"]>
      <label
        htmlFor=label className=[%tw "text-gray-600 text-sm font-medium mb-2"]>
        label->React.string
      </label>
      <input
        id=label
        value
        onBlur
        onChange
        disabled
        className=[%tw
          "appearance-none block w-full bg-gray-200 text-gray-700 border border-gray-200 rounded py-3
          px-4 mb-3 leading-tight focus:outline-none focus:bg-white"
        ]
        type_
        placeholder
      />
      {Belt.Option.mapWithDefault(errorMessage, React.null, errMessage => {
         <p className=[%tw "text-red-500 text-xs italic"]>
           errMessage->React.string
         </p>
       })}
    </div>;
  };
};
