module Label = {
  [@genType]
  [@react.component]
  let make = (~text) => {
    <label
      htmlFor=text className=[%tw "text-gray-600 text-sm font-medium mb-2"]>
      text->React.string
    </label>;
  };
};

module Input = {
  [@genType]
  [@react.component]
  let make =
      (
        ~label=?,
        ~value,
        ~disabled=false,
        ~onBlur,
        ~onChange,
        ~classNames=?,
        ~type_="text",
        ~placeholder="",
        ~errorMessage=None,
      ) => {
    <div className=[%tw "flex flex-col"]>
      {label->Option.mapWithDefault(React.null, label => <Label text=label />)}
      <input
        id={label->Option.getWithDefault("")}
        value
        onBlur
        onChange
        disabled
        className={String.concat(
          " ",
          [
            [%tw
              "appearance-none block w-full bg-gray-300 text-gray-700 rounded py-3 px-4 leading-tight focus:outline-none focus:bg-white"
            ],
            Cn.unpack(classNames),
          ],
        )}
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
        "mr-8 justify-self-start self-start first:rounded-bl-sm last:rounded-tl-sm
        only-child:rounded-tl-none only-child:rounded-bl-xl mb-2 last:mb-0"
      ]
    | `Right => [%tw
        "ml-8 justify-self-end self-end first:rounded-br-sm last:rounded-tr-sm"
      ];
  let colorToStyling =
    fun
    | `Default => [%tw "bg-white text-black"]
    | `Contrast => [%tw "bg-black text-white"];

  [@genType]
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
      className={String.concat(
        " ",
        [
          [%tw "text-base sm:text-lg px-6 py-3 rounded-xl"],
          Cn.ifTrue("fade-in-delay", animate && animationDelayed),
          Cn.ifTrue("fade-in", animate && !animationDelayed),
          Cn.ifTrue("slide-up", !animate && !animationDelayed),
          alignmentToStyling(align),
          colorToStyling(color),
        ],
      )}>
      children
    </div>;
  };
};

module BubbleOption = {
  [@genType]
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
  [@genType]
  [@react.component]
  let make = (~onSubmit, ~placeholder={j|"Skriv ditt svar här...|j}) => {
    let (inputValue, setInputValue) = React.useState(_ => "");

    let handleInputChange = event => {
      event->ReactEvent.Form.persist;
      setInputValue(_prevValue => event->ReactEvent.Form.target##value);
    };

    <form
      className=[%tw "grid grid-cols-2 grid-flow-col items-center"]
      onSubmit={event => {
        event->ReactEvent.Form.preventDefault;
        onSubmit(inputValue);
      }}>
      <input
        value=inputValue
        onChange=handleInputChange
        className=[%tw
          "appearance-none block w-full bg-gray-300 text-gray-700 py-3 px-4 leading-tight
            focus:outline-none focus:bg-white col-span-2 rounded-l"
        ]
        type_="text"
        placeholder
      />
      <button
        className=[%tw "bg-gray-300 text-gray-500 h-full py-2 px-4 rounded-r"]
        disabled={String.length(inputValue) == 0}>
        <SVGSend width="18" fill="currentColor" />
      </button>
    </form>;
  };
};

module ChatFormAnswerOptions = {
  [@genType]
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

module Link = {
  [@genType]
  [@react.component]
  let make = (~to_, ~children, ~active=false) => {
    <button
      className={String.concat(
        " ",
        [
          Cn.ifTrue([%tw "text-blue-500"], active),
          Cn.ifTrue([%tw "text-gray-600"], !active),
        ],
      )}
      onClick={_event => ReasonReactRouter.push(to_)}>
      children
    </button>;
  };
};

module CategoryThumbnail = {
  [@genType]
  [@react.component]
  let make = (~data) => {
    let categoryName = data##label;

    let (isOpen, setIsOpen) = React.useState(_ => false);

    <Layout.Column
      classNames=[%tw "justify-stretch justify-items-center w-full"]>
      <button
        onClick={_ => setIsOpen(_wasOpen => true)}
        className=[%tw "bg-white rounded-xl p-4 w-full h-32"]>
        <ArticleModal
          data
          isOpen
          onClose={_ => setIsOpen(_wasOpen => false)}
        />
      </button>
      <p> {React.string({j|$categoryName|j})} </p>
    </Layout.Column>;
  };
};

module ApplicationThumbnail = {
  [@genType]
  [@react.component]
  let make = (~link, ~id, ~appName) => {
    let registrationId = {js|/?dp_referall_id=OK123|js};

    <Layout.Column
      classNames=[%tw "justify-stretch justify-items-center w-full"]>
      <a
        href={link ++ registrationId}
        target="_blank"
        key=id
        className=[%tw "bg-white rounded-xl p-4 w-full h-32"]
      />
      <p> {React.string({j|$appName|j})} </p>
    </Layout.Column>;
  };
};

module Tag = {
  [@genType]
  [@react.component]
  let make = (~text, ~onClick, ~active) => {
    <button
      onClick
      className={String.concat(
        " ",
        [
          [%tw "py-2 px-4 rounded-full"],
          Cn.ifTrue([%tw "bg-blue-200 text-blue-800"], active),
          Cn.ifTrue([%tw "bg-white text-gray-600"], !active),
        ],
      )}>
      {React.string(text)}
    </button>;
  };
};

module Article = {
  [@react.component]
  let make = (~title, ~text, ~asset=?, ~articleType: [ | `Article | `Quote]) => {
    <Layout.Column classNames=[%tw "p-6 rounded-lg bg-gray-300 relative"]>
      <span className=[%tw "absolute top-0 right-0 p-6"]>
        <SVGHeart width="16" height="16" fill="black" />
      </span>
      {switch (articleType) {
       | `Article =>
         <Layout.Row classNames=[%tw "items-center mr-4"]>
           <Typography.H2> {React.string({j|$title|j})} </Typography.H2>
         </Layout.Row>
       | `Quote =>
         <Layout.Row
           classNames=[%tw "items-center justify-center w-5/6 mx-auto"]>
           <blockquote className=[%tw "grid gap-8 col-start-2 col-end-2"]>
             <Typography.Quote>
               {React.string({j|"$title"|j})}
             </Typography.Quote>
           </blockquote>
         </Layout.Row>
       }}
      {asset->Option.mapWithDefault(React.null, asset =>
         <img src=asset alt="" className=[%tw "w-full h-auto"] />
       )}
      <Typography.P> {React.string({j|$text|j})} </Typography.P>
    </Layout.Column>;
  };
};

module BottomNavigation = {
  [@react.component]
  let make = (~currentRoute) => {
    <nav
      className=[%tw
        "fixed bottom-0 left-0 right-0 w-full h-16 bg-white border-t border-gray-200"
      ]>
      <Layout.Row classNames=[%tw "h-full items-center justify-around"]>
        <Link to_="/" active={currentRoute == `Feed}>
          <SVGHome width="24" height="24" fill="currentColor" />
        </Link>
        <Link to_="/explore" active={currentRoute == `Applications}>
          <SVGExplore width="24" height="24" fill="currentColor" />
        </Link>
        <Link to_="/my-profile" active={currentRoute == `Profile}>
          <SVGUserSolidCircle width="24" height="24" fill="currentColor" />
        </Link>
      </Layout.Row>
    </nav>;
  };
};
