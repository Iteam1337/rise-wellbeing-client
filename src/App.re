[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  let isFirstTimeVisitor = IsFirstTimeVisitorHook.use();

  if (isFirstTimeVisitor) {
    let screen =
      switch (url.path) {
      | [] => <FirstTimeVisitLandingPage />
      | ["categorise"] =>
        <CategorisePage onNextQuestion=Webapi.Dom.Element.scrollIntoView />
      /* | ["explore"] => <SuggestedApplicationsPage /> */
      | ["explore"] => <ApplicationCategoriesPage />
      | ["my-profile"] => <MyProfilePage />
      | _ => <Typography.H1> {React.string("Not found.")} </Typography.H1>
      };

    <div className=[%tw "md:max-w-screen-lg h-full mx-auto"]> screen </div>;
  } else {
    let screen =
      switch (url.path) {
      | [] => <LandingPage />
      | ["categorise"] =>
        <CategorisePage onNextQuestion=Webapi.Dom.Element.scrollIntoView />
      /* | ["explore"] => <SuggestedApplicationsPage /> */
      | ["explore"] => <ApplicationCategoriesPage />
      | ["my-profile"] => <MyProfilePage />
      | ["example"] => <ExamplePage />
      | _ => <Typography.H1> {React.string("Not found.")} </Typography.H1>
      };

    let currentRoute =
      switch (url.path->List.head) {
      | Some("explore") => `Applications
      | Some("my-profile") => `Profile
      | Some(_) => `Feed
      | None => `Feed
      };

    <div className=[%tw "md:max-w-screen-lg h-full mx-auto"]>
      screen
      <Elements.BottomNavigation currentRoute />
    </div>;
  };
};
