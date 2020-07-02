/* TypeScript file generated from Conversation.re by genType. */
/* eslint-disable import/first */

import * as React from "react";

// tslint:disable-next-line:no-var-requires
const ConversationBS = require("./Conversation.bs");

import { Question_question as Shared_Question_question } from "./Shared.gen";

import { element as Dom_element } from "./Dom.gen";

import { list } from "./ReasonPervasives.gen";

// tslint:disable-next-line:interface-over-type-literal
export type Props = {
  readonly onNextQuestion?: (_1: Dom_element) => void;
  readonly questions: list<Shared_Question_question>;
};

export const make: React.ComponentType<{
  readonly onNextQuestion?: (_1: Dom_element) => void;
  readonly questions: list<Shared_Question_question>;
}> = ConversationBS.make;
