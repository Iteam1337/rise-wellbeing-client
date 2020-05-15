[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  let screen =
    switch (url.path) {
    | [] => <LandingPage />
    | ["categorise"] => <CategorisePage />
    | ["suggested-applications"] => <SuggestedApplicationsPage />
    | ["example"] => <ExamplePage />
    | _ => <Typography.H1> {React.string("Not found.")} </Typography.H1>
    };

  <div className=[%tw "md:max-w-screen-lg h-full mx-auto p-6"]> screen </div>;
};
