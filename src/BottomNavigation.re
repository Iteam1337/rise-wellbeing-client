[@react.component]
let make = (~currentRoute) => {
  <nav className=[%tw "fixed bottom-0 left-0 right-0 w-full h-16 bg-gray-300"]>
    <Layout.Row classNames=[%tw "h-full items-center justify-around"]>
      <Elements.Link to_="/" active={currentRoute == `Feed}>
        {React.string("Feed")}
      </Elements.Link>
      <Elements.Link to_="/explore" active={currentRoute == `Applications}>
        {React.string("Utforska")}
      </Elements.Link>
    </Layout.Row>
  </nav>;
};
