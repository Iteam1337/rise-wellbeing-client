[%bs.raw {|require("./tailwind.css")|}];
[%bs.raw {|require("./misc.css")|}];

/* Create an InMemoryCache */
let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

/* Create an HTTP Link */
let httpLink =
  ApolloLinks.createHttpLink(~uri="http://localhost:9002/graphql", ());

let client =
  ReasonApollo.createApolloClient(~link=httpLink, ~cache=inMemoryCache, ());

let app = <ApolloHooks.Provider client> <App /> </ApolloHooks.Provider>;

ReactDOMRe.renderToElementWithId(app, "root");
