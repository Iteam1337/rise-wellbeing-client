[@react.component]
let make = () => {
  <Layout.Container spacing=`None classNames=[%tw " h-full"]>
    <Layout.Column
      spacing=`Large classNames=[%tw " justify-center text-center"]>
      <Typography.H1> {React.string("Digital Plattform")} </Typography.H1>
      <Typography.P>
        {React.string({j|Välkommen till plattformen för välmående.|j})}
      </Typography.P>
    </Layout.Column>
  </Layout.Container>;
};
