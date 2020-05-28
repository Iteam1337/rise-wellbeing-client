module ServicesQuery = [%graphql
  {|
    query ServicesAndCategories {
      services {
        categories {
          id
          name
        }
        id
        link
        name
      }

      categories {
        id
        name
      }
    }
  |}
];

type state('service, 'tag) = {
  activeTags: list(Js.t('tag)),
  availableTags: list(Js.t('tag)),
  services: list(Js.t('service)),
};

[@react.component]
let make = () => {
  let (state, setState) =
    React.useState(_ => {activeTags: [], availableTags: [], services: []});
  let (status, _) = ApolloHooks.useQuery(ServicesQuery.definition);

  React.useEffect1(
    () => {
      switch (status) {
      | Data(data) =>
        setState(prevState =>
          {
            ...prevState,
            services: data##services->List.fromArray,
            availableTags:
              data##categories
              ->Array.map(category => category)
              ->List.fromArray,
          }
        )
      | _ => ()
      };

      None;
    },
    [|status|],
  );

  let handleTagClick = (wasActive, clickedTag) =>
    if (wasActive) {
      setState(prevState =>
        {
          ...prevState,
          activeTags:
            prevState.activeTags
            ->List.keep(tag => !String.equal(tag##id, clickedTag##id)),
        }
      );
    } else {
      setState(prevState =>
        {...prevState, activeTags: [clickedTag, ...prevState.activeTags]}
      );
    };

  let tagActive = tag => {
    state.activeTags
    ->List.has(tag, (activeTag, tagToCheck) =>
        String.equal(activeTag##id, tagToCheck##id)
      );
  };

  <Layout.Container spacing=`Small>
    <Layout.Column spacing=`Medium>
      <Typography.H1> {React.string("Utforska")} </Typography.H1>
      <Layout.Row
        spacing=`Small
        classNames=[%tw
          "grid grid-flow-col max-w-full overflow-x-scroll pb-4 grid-auto-columns-max-content"
        ]>
        {state.availableTags
         ->List.map(tag => {
             let isActive = tagActive(tag);

             <Elements.Tag
               key=tag##id
               onClick={_ => handleTagClick(isActive, tag)}
               active=isActive
               text=tag##name
             />;
           })
         ->List.toArray
         ->React.array}
      </Layout.Row>
      {switch (status) {
       | NoData
       | Loading =>
         <Typography.P>
           {React.string({j|Laddar listan med tjänser...|j})}
         </Typography.P>
       | Error(_) =>
         <p> {React.string({j|Hmm. Någonting verkar ha gått snett.|j})} </p>
       | Data(data) =>
         <Layout.Column classNames=[%tw "grid-cols-2 pb-16"] spacing=`Medium>
           {data##services
            ->Array.keep(service =>
                if (List.length(state.activeTags) > 0) {
                  service##categories
                  ->Array.some(category =>
                      state.activeTags
                      ->List.has(category, (activeTag, serviceToCheck) =>
                          String.equal(activeTag##id, serviceToCheck##id)
                        )
                    );
                } else {
                  true;
                }
              )
            ->Array.map(app => {
                let appName = app##name;

                <Elements.ApplicationThumbnail
                  key=app##id
                  appName
                  link=app##link
                  id=app##id
                />;
              })
            ->React.array}
         </Layout.Column>
       }}
    </Layout.Column>
  </Layout.Container>;
};
