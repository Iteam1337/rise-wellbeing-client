module ServicesQuery = [%graphql
  {|
    query Services {
      services {
        contact
        id
        link
        name
      }
    }
  |}
];

[@react.component]
let make = () => {
  let (status, _) = ApolloHooks.useQuery(ServicesQuery.definition);

  <Layout.Container spacing=`Small>
    <Layout.Column spacing=`Medium>
      <Typography.H1> {React.string("Utforska")} </Typography.H1>
      <Layout.Column classNames=[%tw "grid-cols-2 pb-16"] spacing=`Medium>
        {switch (status) {
         | NoData
         | Loading => <p> {React.string("Laddar...")} </p>
         | Error(_) =>
           <p>
             {React.string({j|Hmm. Någonting verkar ha gått snett.|j})}
           </p>
         | Data(data) =>
           data##services
           ->Array.map(app => {
               let appName = app##name;

               <Elements.ApplicationThumbnail
                 key=app##id
                 appName
                 link=app##link
                 id=app##id
               />;
             })
           ->React.array
         }}
      </Layout.Column>
    </Layout.Column>
  </Layout.Container>;
};
