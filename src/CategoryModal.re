[%raw "require('@reach/dialog/styles.css')"];

[@react.component]
let make = (~isOpen, ~data, ~onClose) => {
  let dummyNodeRef = React.useRef(Js.Nullable.null);
  let title = data##name;
  let introductoryText = data##introduction;
  let description = data##information;

  <Layout.Container>
    <Reach.Dialog.Overlay
      className=[%tw
        "absolute top-0 right-0 left-0 bottom-0 p-0 pb-6 w-full m-0 bg-white"
      ]
      isOpen
      initialFocusRef=dummyNodeRef
      onDismiss={() => onClose()}>
      <button
        className=[%tw
          "rounded-full bg-gray-300 p-4 fixed top-0 right-0 mt-6 mr-6"
        ]
        onClick={_ => onClose()}>
        <Reach.VisuallyHidden> "Close" </Reach.VisuallyHidden>
        <SVGClose width="32" height="32" fill="black" />
      </button>
      <Layout.Column>
        <div className=[%tw "h-64 w-full bg-gray-800"]>
          <img
            src="https://picsum.photos/500/320"
            alt=""
            className=[%tw "w-full h-64"]
          />
        </div>
        <Layout.Column classNames=[%tw "p-6"]>
          <Typography.H2> {React.string({j|$title|j})} </Typography.H2>
          <Typography.Leading>
            {React.string({j|$introductoryText|j})}
          </Typography.Leading>
          <Typography.P> {React.string({j|$description|j})} </Typography.P>
        </Layout.Column>
      </Layout.Column>
    </Reach.Dialog.Overlay>
  </Layout.Container>;
};
