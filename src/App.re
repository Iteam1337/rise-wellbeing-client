[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  let page =
    switch (url.path) {
    | [] => <CategorisePage />
    | ["suggested-applications"] => <SuggestedApplicationsPage />
    | ["example"] => <ExamplePage />
    | _ => <Typography.H1> {React.string("Not found.")} </Typography.H1>
    };

  <div className=[%tw "md:max-w-screen-lg mx-auto"]> page </div>;
};
