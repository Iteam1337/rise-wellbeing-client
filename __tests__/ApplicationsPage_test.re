open TestFramework;

module Rtl = ReactTestingLibrary;
module Dtl = DomTestingLibrary;

let mocks = [|
  {
    "request": {
      "query":
        ApolloHooks.Query.gql(.
          SuggestedApplicationsPage.ServicesQuery.query,
        ),
    },
    "result": () => {
      {
        "data": {
          "services": [
            {
              "categories": [
                {"id": "1", "name": "Peer to peer", "__typename": "Category"},
                {
                  "id": "3",
                  "name": "Öva upp färdighet",
                  "__typename": "Category",
                },
              ],
              "id": "1",
              "link": "google.se",
              "name": "Mindfulness-appen",
              "__typename": "Service",
            },
            {
              "categories": [
                {"id": "2", "name": "Information", "__typename": "Category"},
              ],
              "id": "2",
              "link": "google.se",
              "name": "Må Bra",
              "__typename": "Service",
            },
          ],
          "categories": [
            {"id": "1", "name": "Peer to peer", "__typename": "Category"},
            {"id": "2", "name": "Information", "__typename": "Category"},
            {
              "id": "3",
              "name": "Öva upp färdighet",
              "__typename": "Category",
            },
          ],
        },
      };
    },
  },
|];

describe("ApplicationsPage", ({test}) => {
  test("renders", ({expect, _}) => {
    let element =
      Rtl.render(
        <TestUtils.MockedProvider mocks>
          <SuggestedApplicationsPage />
        </TestUtils.MockedProvider>,
      );

    let result = element->Rtl.getByText(~matcher=`Str("Utforska"));

    expect.value(result).toMatchSnapshot();
  })
});
