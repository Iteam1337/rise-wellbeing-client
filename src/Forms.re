module LoginForm = [%form
  type input = {email: string};
  type output = {email: string};
  let validators = {
    email: {
      strategy: OnFirstSuccessOrFirstBlur,
      validate: input =>
        String.length(input.email) > 1
          ? Ok(input.email) : Error("E-mail is
      required"),
    },
  }
];

module Login = {
  [@react.component]
  let make = () => {
    let form =
      LoginForm.useForm(
        ~initialInput={email: ""},
        ~onSubmit=(output, cb) => {
          Js.log(output);
          cb.notifyOnFailure();
        },
      );

    <Layout.Column>
      {switch (form.status) {
       | Editing => "Editing..."->React.string
       | Submitting(_maybeSubmissionError) => "Submitting..."->React.string
       | Submitted => "Perfect"->React.string
       | SubmissionFailed () => "Error"->React.string
       }}
      <form
        onSubmit={event => {
          event->ReactEvent.Form.preventDefault;
          form.submit();
        }}>
        <Elements.Input
          errorMessage={
            form.emailResult
            ->Belt.Option.mapWithDefault(None, someResult => {
                switch (someResult) {
                | Error(message) => Some(message)
                | _ => None
                }
              })
          }
          label="E-mail"
          placeholder="jane@example.com"
          value={form.input.email}
          disabled={form.submitting}
          onBlur={_ => form.blurEmail()}
          onChange={event =>
            form.updateEmail(
              (_input, value) => {email: value},
              event->ReactEvent.Form.target##value,
            )
          }
        />
      </form>
    </Layout.Column>;
  };
};
