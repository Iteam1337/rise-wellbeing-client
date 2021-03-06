module Container = {
  let spacingToStyling =
    fun
    | `None => [%tw "p-0"]
    | `Small => [%tw "p-4"]
    | `Medium => [%tw "p-6"]
    | `Large => [%tw "p-8"];

  [@genType]
  [@react.component]
  let make = (~children, ~spacing=`None, ~classNames=?) => {
    let additionalClassNames = Cn.unpack(classNames);
    <section
      className={String.concat(
        " ",
        [spacingToStyling(spacing), additionalClassNames],
      )}>
      children
    </section>;
  };
};

module Column = {
  let spacingToStyling =
    fun
    | `None => [%tw "gap-0"]
    | `Small => [%tw "gap-4"]
    | `Medium => [%tw "gap-6"]
    | `Large => [%tw "gap-8"];

  [@genType]
  [@react.component]
  let make = (~children, ~spacing=`Small, ~classNames=?) => {
    let additionalClassNames = Cn.unpack(classNames);

    <section
      className={String.concat(
        " ",
        [[%tw "grid"], spacingToStyling(spacing), additionalClassNames],
      )}>
      children
    </section>;
  };
};

module Row = {
  let spacingToStyling =
    fun
    | `None => [%tw "gap-0"]
    | `Small => [%tw "gap-4"]
    | `Medium => [%tw "gap-6"]
    | `Large => [%tw "gap-8"];

  [@genType]
  [@react.component]
  let make = (~children, ~spacing=`Small, ~classNames=?) => {
    let additionalClassNames = Cn.unpack(classNames);
    <section
      className={String.concat(
        " ",
        [[%tw "flex"], spacingToStyling(spacing), additionalClassNames],
      )}>
      children
    </section>;
  };
};
