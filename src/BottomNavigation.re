[@react.component]
let make = (~currentRoute) => {
  <nav
    className=[%tw
      "fixed bottom-0 left-0 right-0 w-full h-16 bg-white border-t border-gray-200"
    ]>
    <Layout.Row classNames=[%tw "h-full items-center justify-around"]>
      <Elements.Link to_="/" active={currentRoute == `Feed}>
        <SVGHome width="24" height="24" fill="currentColor" />
      </Elements.Link>
      <Elements.Link to_="/explore" active={currentRoute == `Applications}>
        <SVGExplore width="24" height="24" fill="currentColor" />
      </Elements.Link>
      <Elements.Link to_="/my-profile" active={currentRoute == `Profile}>
        <SVGUserSolidCircle width="24" height="24" fill="currentColor" />
      </Elements.Link>
    </Layout.Row>
  </nav>;
};
