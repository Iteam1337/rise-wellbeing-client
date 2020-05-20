let use = () => {
  let (isFirstTimeVisitor, setFirstTimeVisitor) = React.useState(_ => false);

  React.useEffect0(() => {
    let maybeFirstTimeVisitor =
      Dom.Storage.getItem(
        "__digital_plattform_not_first_time_visitor",
        Dom.Storage.localStorage,
      );

    let isFirstTimeVisitor =
      switch (maybeFirstTimeVisitor) {
      | Some(_yes) => false
      | None => true
      };

    setFirstTimeVisitor(_prevValue =>
      if (isFirstTimeVisitor) {
        Dom.Storage.setItem(
          "__digital_plattform_not_first_time_visitor",
          "true",
          Dom.Storage.localStorage,
        );
        true;
      } else {
        false;
      }
    );

    None;
  });

  isFirstTimeVisitor;
};
