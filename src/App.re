open Belt;
open Webapi.Dom;

module Document = {
  let element =
    if (Js.typeof(document) !== "undefined") {
      Some(document |> Document.documentElement);
    } else {
      None;
    };
};

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  let isFirstTimeVisitor = IsFirsTimeVisitorHook.use();

  if (isFirstTimeVisitor) {
    let screen =
      switch (url.path) {
      | [] => <FirstTimeVisitLandingPage />
      | ["categorise"] => <CategorisePage />
      | ["explore"] => <SuggestedApplicationsPage />
      | ["my-profile"] => <ExamplePage />
      | _ => <Typography.H1> {React.string("Not found.")} </Typography.H1>
      };

    <div className=[%tw "md:max-w-screen-lg h-full mx-auto p-6"]>
      screen
    </div>;
  } else {
    let screen =
      switch (url.path) {
      | [] => <LandingPage />
      | ["categorise"] => <CategorisePage />
      | ["explore"] => <SuggestedApplicationsPage />
      | ["my-profile"] => <ExamplePage />
      | ["example"] => <ExamplePage />
      | _ => <Typography.H1> {React.string("Not found.")} </Typography.H1>
      };

    let currentRoute =
      switch (url.path->List.head) {
      | Some("explore") => `Applications
      | Some(_) => `Feed
      | None => `Feed
      };

    <div className=[%tw "md:max-w-screen-lg h-full mx-auto p-6"]>
      screen
      <BottomNavigation currentRoute />
    </div>;
  };
};
