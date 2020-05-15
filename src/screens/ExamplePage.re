[@react.component]
let make = () => {
  <Layout.Container spacing=`Small>
    <Layout.Column>
      <Layout.Container>
        <Typography.H1>
          {React.string("This is a leading title")}
        </Typography.H1>
        <Typography.P>
          {React.string(
             "Pellentesque in leo aliquet magna suscipit rutrum id eu orci. Suspendisse vitae dapibus diam, eu elementum dolor. Sed feugiat a erat eget rhoncus. Nullam ac tempor orci. Mauris dignissim ornare quam, ac iaculis purus dapibus non. Donec id elit ac arcu porta euismod. Sed eu lorem aliquet, luctus erat sit amet, suscipit sapien. Proin tincidunt sapien sit amet mauris ultricies, vitae lacinia metus ultricies. In ac rhoncus lacus. Pellentesque eget tellus efficitur, blandit turpis nec, pharetra lacus. Curabitur fermentum sed sapien et bibendum.",
           )}
        </Typography.P>
      </Layout.Container>
      <Layout.Container>
        <Typography.H2>
          {React.string("This is a secondary title, h2.")}
        </Typography.H2>
        <Typography.P>
          {React.string(
             "Pellentesque in leo aliquet magna suscipit rutrum id eu orci. Suspendisse vitae dapibus diam, eu elementum dolor. Sed feugiat a erat eget rhoncus. Nullam ac tempor orci. Mauris dignissim ornare quam, ac iaculis purus dapibus non. Donec id elit ac arcu porta euismod. Sed eu lorem aliquet, luctus erat sit amet, suscipit sapien. Proin tincidunt sapien sit amet mauris ultricies, vitae lacinia metus ultricies. In ac rhoncus lacus. Pellentesque eget tellus efficitur, blandit turpis nec, pharetra lacus. Curabitur fermentum sed sapien et bibendum.",
           )}
        </Typography.P>
        <Forms.Login />
      </Layout.Container>
    </Layout.Column>
  </Layout.Container>;
};
