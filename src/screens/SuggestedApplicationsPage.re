module CategoriesQuery = [%graphql
  {|
    query Categories {
      categories {
        id
        label
      }
    }
  |}
];

module ServicesQuery = [%graphql
  {|
    query Services {
      services {
        categories {
          id
          label
        }
        id
        link
        name
      }
    }
  |}
];

type state('service, 'category) = {
  activeTags: list('category),
  availableTags: list('category),
  services: list('service),
};

[@react.component]
let make = () => {
  let (state, setState) =
    React.useState(_ => {activeTags: [], availableTags: [], services: []});

  let (servicesStatus, _) = ApolloHooks.useQuery(ServicesQuery.definition);
  let (categoriesStatus, _) =
    ApolloHooks.useQuery(CategoriesQuery.definition);

  React.useEffect2(
    () => {
      switch (servicesStatus, categoriesStatus) {
      | (Data(serviceData), Data(categoriesData)) =>
        setState(prevState =>
          {
            ...prevState,
            services: serviceData##services->List.fromArray,
            availableTags:
              categoriesData##categories
              ->Array.map(category => category)
              ->List.fromArray,
          }
        )
      | _ => ()
      };

      None;
    },
    (categoriesStatus, servicesStatus),
  );

  let handleTagClick = (wasActive, clickedTag) =>
    if (wasActive) {
      setState(prevState =>
        {
          ...prevState,
          activeTags:
            prevState.activeTags->List.keep(tag => tag##id !== clickedTag##id),
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
        activeTag##id == tagToCheck##id
      );
  };

  <Layout.Container spacing=`Small>
    <Layout.Column spacing=`Medium classNames=[%tw "pb-20"]>
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
               key={tag##id}
               onClick={_ => handleTagClick(isActive, tag)}
               active=isActive
               text={tag##label}
             />;
           })
         ->List.toArray
         ->React.array}
      </Layout.Row>
      {switch (servicesStatus, categoriesStatus) {
       | (NoData, _)
       | (_, NoData)
       | (Loading, _)
       | (_, Loading) =>
         <Typography.P>
           {React.string({j|Laddar listan med tjänser...|j})}
         </Typography.P>

       | (Error(_), _)
       | (_, Error(_)) =>
         <p> {React.string({j|Hmm. Någonting verkar ha gått snett.|j})} </p>

       | (Data(serviceData), Data(_categoriesData)) =>
         <>
           <Typography.P>
             <Elements.Link to_="/categorise">
               <Typography.H2> {React.string("Starta guide")} </Typography.H2>
             </Elements.Link>
           </Typography.P>
           <Layout.Column classNames=[%tw "grid-cols-2"] spacing=`Medium>
             {serviceData##services
              ->Array.keep(service =>
                  if (List.length(state.activeTags) > 0) {
                    service##categories
                    ->Array.some(category =>
                        state.activeTags
                        ->List.has(category, (activeTag, serviceToCheck) =>
                            activeTag##id == serviceToCheck##id
                          )
                      );
                  } else {
                    true;
                  }
                )
              ->Array.map(app => {
                  <Elements.ApplicationThumbnail
                    key={app##id}
                    appName={app##name}
                    link={app##link}
                    id={app##id}
                  />
                })
              ->React.array}
           </Layout.Column>
         </>
       }}
    </Layout.Column>
  </Layout.Container>;
};
