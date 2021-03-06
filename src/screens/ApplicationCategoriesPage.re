module CategoriesQuery = [%graphql
  {|
    query Categories {
      categories {
          id
          label
          introduction
          information
      }
    }
  |}
];

type state('category) = {categories: list('category)};

[@react.component]
let make = () => {
  let (state, setState) = React.useState(_ => {categories: []});

  let (categoriesStatus, _) =
    ApolloHooks.useQuery(CategoriesQuery.definition);

  React.useEffect1(
    () => {
      switch (categoriesStatus) {
      | Data(categoriesData) =>
        setState(_prevState =>
          {categories: categoriesData##categories->List.fromArray}
        )
      | _ => ()
      };

      None;
    },
    [|categoriesStatus|],
  );

  <Layout.Container spacing=`Small>
    <Layout.Column spacing=`Medium classNames=[%tw "pb-20"]>
      <Typography.H1> {React.string("Utforska")} </Typography.H1>
      {switch (categoriesStatus) {
       | NoData
       | Loading =>
         <Typography.P>
           {React.string({j|Laddar listan med tjänser...|j})}
         </Typography.P>

       | Error(_) =>
         <p> {React.string({j|Hmm. Någonting verkar ha gått snett.|j})} </p>

       | Data(categoriesData) =>
         <>
           <Typography.P>
             <Elements.Link to_="/categorise">
               <Typography.H2> {React.string("Starta guide")} </Typography.H2>
             </Elements.Link>
           </Typography.P>
           <Layout.Column classNames=[%tw "grid-cols-2"] spacing=`Medium>
             {categoriesData##categories
              ->Array.map(category => {
                  <Elements.CategoryThumbnail
                    key={category##id}
                    data=category
                  />
                })
              ->React.array}
           </Layout.Column>
         </>
       }}
    </Layout.Column>
  </Layout.Container>;
};
