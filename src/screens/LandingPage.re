[@react.component]
let make = () => {
  <Layout.Container spacing=`Small classNames=[%tw " h-full"]>
    <Layout.Column spacing=`Large classNames=[%tw "pb-20"]>
      <Typography.H1> {React.string("Digital Plattform")} </Typography.H1>
      <Elements.Article
        articleType=`Article
        title="Rubrik"
        text="Lorem ipsum dolor sit amet, consectetur adipiscing
      elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim
      veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequata."
      />
      <Elements.Article
        articleType=`Article
        asset="https://picsum.photos/500/320"
        title="Very long title spanning over multiple lines"
        text="Lorem ipsum dolor sit amet, consectetur adipiscing
      elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim
      veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequata."
      />
      <Elements.Article
        articleType=`Quote
        title={js|Citat från en personlig berättelse om psykisk hälsa|js}
        text="Lorem ipsum dolor sit amet, consectetur adipiscing
      elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim
      veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequata."
      />
    </Layout.Column>
  </Layout.Container>;
};
