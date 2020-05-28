module ApolloReactTesting = {
  module MockedProvider = {
    [@bs.module "@apollo/react-testing"] [@react.component]
    external make:
      (
        ~children: React.element,
        ~mocks: array(Js.t('mocks)),
        ~addTypename: bool
      ) =>
      React.element =
      "MockedProvider";
  };

  module MockedProvider2 = {
    [@bs.module "@apollo/react-testing"] [@react.component]
    external make:
      (
        ~children: React.element,
        ~mocks: (Js.t('mocksA), Js.t('mocksB)),
        ~addTypename: bool
      ) =>
      React.element =
      "MockedProvider";
  };

  module MockedProvider3 = {
    [@bs.module "@apollo/react-testing"] [@react.component]
    external make:
      (
        ~children: React.element,
        ~mocks: (Js.t('mocksA), Js.t('mocksB), Js.t('mocksC)),
        ~addTypename: bool
      ) =>
      React.element =
      "MockedProvider";
  };

  module MockLink = {
    [@bs.module "@apollo/react-testing"] [@bs.new]
    external make:
      (~mocks: array(Js.t('mocks))) => ReasonApolloTypes.apolloLink =
      "MockLink";
  };

  [@bs.module "@apollo/react-testing"]
  external createClient:
    (
      ~data: Js.t('data),
      ~query: Js.t('query),
      ~variables: Js.t('variables)
    ) =>
    Js.t('normalisedCacheObject) =
    "createClient";
};

module MockedProvider = {
  [@react.component]
  let make = (~addTypename=true, ~children, ~mocks=[||]) => {
    <ApolloReactTesting.MockedProvider addTypename mocks>
      children
    </ApolloReactTesting.MockedProvider>;
  };
};

[@bs.module "@testing-library/react"]
external waitForElement: (unit => Dom.element) => Js.Promise.t('a) =
  "waitForElement";

[@bs.module "@testing-library/react"]
external waitForElementToBeRemoved: (unit => Dom.element) => Js.Promise.t('a) =
  "waitForElementToBeRemoved";
