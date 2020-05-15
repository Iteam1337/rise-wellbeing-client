module Question = {
  [@decco]
  type selectOption = {
    text: string,
    value: string,
  };

  [@decco]
  type textQuestion = {
    id: string,
    messages: list(string),
    [@decco.default None]
    answer: option(string),
    [@decco.default None]
    answerPlaceholder: option(string),
  };

  [@decco]
  type selectQuestion = {
    id: string,
    message: string,
    options: list(selectOption),
    [@decco.default None]
    answer: option(selectOption),
  };

  [@decco]
  type question =
    | Text(textQuestion)
    | Select(selectQuestion);
};
