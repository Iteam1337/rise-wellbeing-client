[@react.component]
let make = () => {
  <Layout.Container spacing=`Small classNames=[%tw " h-full"]>
    <Layout.Column
      spacing=`Large classNames=[%tw " justify-center text-center"]>
      <Typography.H1> {React.string("Digital Plattform")} </Typography.H1>
      <Typography.P>
        <Elements.Link to_="/categorise">
          {React.string(
             {j|Hej! Det ser ut som att det är första gången du besöker denna webbplats.|j},
           )}
        </Elements.Link>
      </Typography.P>
      <Typography.P>
        <Elements.Link to_="/categorise">
          {React.string({j|Ta mig till vägledningen.|j})}
        </Elements.Link>
      </Typography.P>
    </Layout.Column>
  </Layout.Container>;
};
