open Belt;

module Label = {
  [@react.component]
  let make = (~text) => {
    <label
      htmlFor=text className=[%tw "text-gray-600 text-sm font-medium mb-2"]>
      text->React.string
    </label>;
  };
};

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
      <Label text=label />
      <input
        id=label
        value
        onBlur
        onChange
        disabled
        className=[%tw
          "appearance-none block w-full bg-gray-300 text-gray-700 border border-gray-200 rounded py-3
          px-4 leading-tight focus:outline-none focus:bg-white"
        ]
        type_
        placeholder
      />
      {Option.mapWithDefault(errorMessage, React.null, errMessage => {
         <p className=[%tw "text-red-500 text-xs italic"]>
           errMessage->React.string
         </p>
       })}
    </div>;
  };
};

module MessageBubble = {
  let alignmentToStyling =
    fun
    | `Left => [%tw
        " mr-8 justify-self-start self-start first:rounded-bl-sm last:rounded-tl-sm
        only-child:rounded-tl-none only-child:rounded-bl-xl mb-2 last:mb-0"
      ]
    | `Right => [%tw
        " ml-8 justify-self-end self-end first:rounded-br-sm last:rounded-tr-sm"
      ];

  let colorToStyling =
    fun
    | `Default => [%tw " bg-white text-black"]
    | `Contrast => [%tw " bg-black text-white"];

  [@react.component]
  let make =
      (
        ~children,
        ~align=`Left,
        ~color=`Default,
        ~animate=true,
        ~animationDelayed=false,
      ) => {
    <div
      className={
        [%tw "text-base sm:text-lg px-6 py-3 rounded-xl"]
        ++ Cn.ifTrue(" fade-in-delay", animate && animationDelayed)
        ++ Cn.ifTrue(" fade-in", animate && !animationDelayed)
        ++ alignmentToStyling(align)
        ++ colorToStyling(color)
      }>
      children
    </div>;
  };
};

module BubbleOption = {
  [@react.component]
  let make = (~children, ~onClick) => {
    <button
      onClick
      className=[%tw
        "text-base sm:text-lg px-6 py-3 rounded-full bg-white text-black transition
        ease-in-out duration-200 transition-colors hover:bg-black
        hover:text-white justify-self-start mr-2 last:mr-0 cursor-pointer"
      ]>
      children->React.string
    </button>;
  };
};
module ChatFormAnswerInput = {
  [@react.component]
  let make = (~onSubmit, ~placeholder={j|"Skriv ditt svar här...|j}) => {
    let (inputValue, setInputValue) = React.useState(_ => "");

    <form
      onSubmit={event => {
        event->ReactEvent.Form.preventDefault;
        onSubmit(inputValue);
      }}>
      <Input
        value=inputValue
        label=""
        onBlur=ignore
        onChange={event => {
          event->ReactEvent.Form.persist;
          setInputValue(_prevValue => event->ReactEvent.Form.target##value);
        }}
        placeholder
      />
    </form>;
  };
};

module ChatFormAnswerOptions = {
  [@react.component]
  let make = (~options: list(Shared.Question.selectOption), ~onSelect) => {
    <Layout.Row spacing=`None classNames=[%tw " justify-center"]>
      {options
       ->List.map(selectOption =>
           <BubbleOption
             key={selectOption.text} onClick={_e => onSelect(selectOption)}>
             {selectOption.text}
           </BubbleOption>
         )
       ->List.toArray
       ->React.array}
    </Layout.Row>;
  };
};
