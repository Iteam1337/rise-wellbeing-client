/* TypeScript file generated from Elements.re by genType. */
/* eslint-disable import/first */


import * as React from 'react';

const $$toRE182264687: { [key: string]: any } = {"Left": 847852583, "Right": -57574468};

const $$toRE593233270: { [key: string]: any } = {"Contrast": 291744034, "Default": -384499551};

// tslint:disable-next-line:no-var-requires
const ElementsBS = require('./Elements.bs');

import {Focus_t as ReactEvent_Focus_t} from '../src/gentype_shims/ReactEvent.shim';

import {Form_t as ReactEvent_Form_t} from '../src/gentype_shims/ReactEvent.shim';

import {Mouse_t as ReactEvent_Mouse_t} from '../src/gentype_shims/ReactEvent.shim';

import {Question_selectOption as Shared_Question_selectOption} from './Shared.gen';

import {list} from './ReasonPervasives.gen';

// tslint:disable-next-line:interface-over-type-literal
export type Props = { readonly text: string };

export const Label_make: React.ComponentType<{ readonly text: string }> = ElementsBS.Label.make;

// tslint:disable-next-line:interface-over-type-literal
export type Input_make_Props = {
  readonly classNames?: string; 
  readonly disabled?: boolean; 
  readonly errorMessage?: (null | undefined | string); 
  readonly label?: string; 
  readonly onBlur: (_1:ReactEvent_Focus_t) => void; 
  readonly onChange: (_1:ReactEvent_Form_t) => void; 
  readonly placeholder?: string; 
  readonly type_?: string; 
  readonly value: string
};

export const Input_make: React.ComponentType<{
  readonly classNames?: string; 
  readonly disabled?: boolean; 
  readonly errorMessage?: (null | undefined | string); 
  readonly label?: string; 
  readonly onBlur: (_1:ReactEvent_Focus_t) => void; 
  readonly onChange: (_1:ReactEvent_Form_t) => void; 
  readonly placeholder?: string; 
  readonly type_?: string; 
  readonly value: string
}> = function Elements_Input(Arg1: any) {
  const $props = {classNames:Arg1.classNames, disabled:Arg1.disabled, errorMessage:(Arg1.errorMessage == null ? undefined : (Arg1.errorMessage == null ? undefined : Arg1.errorMessage)), label:Arg1.label, onBlur:Arg1.onBlur, onChange:Arg1.onChange, placeholder:Arg1.placeholder, type_:Arg1.type_, value:Arg1.value};
  const result = React.createElement(ElementsBS.Input.make, $props);
  return result
};

// tslint:disable-next-line:interface-over-type-literal
export type MessageBubble_make_Props = {
  readonly align?: 
    "Left"
  | "Right"; 
  readonly animate?: boolean; 
  readonly animationDelayed?: boolean; 
  readonly children: React.ReactNode; 
  readonly color?: 
    "Contrast"
  | "Default"
};

export const MessageBubble_make: React.ComponentType<{
  readonly align?: 
    "Left"
  | "Right"; 
  readonly animate?: boolean; 
  readonly animationDelayed?: boolean; 
  readonly children: React.ReactNode; 
  readonly color?: 
    "Contrast"
  | "Default"
}> = function Elements_MessageBubble(Arg1: any) {
  const $props = {align:(Arg1.align == null ? undefined : $$toRE182264687[Arg1.align]), animate:Arg1.animate, animationDelayed:Arg1.animationDelayed, children:Arg1.children, color:(Arg1.color == null ? undefined : $$toRE593233270[Arg1.color])};
  const result = React.createElement(ElementsBS.MessageBubble.make, $props);
  return result
};

// tslint:disable-next-line:interface-over-type-literal
export type BubbleOption_make_Props = { readonly children: string; readonly onClick: (_1:ReactEvent_Mouse_t) => void };

export const BubbleOption_make: React.ComponentType<{ readonly children: string; readonly onClick: (_1:ReactEvent_Mouse_t) => void }> = ElementsBS.BubbleOption.make;

// tslint:disable-next-line:interface-over-type-literal
export type ChatFormAnswerInput_make_Props = { readonly onSubmit: (_1:string) => void; readonly placeholder?: string };

export const ChatFormAnswerInput_make: React.ComponentType<{ readonly onSubmit: (_1:string) => void; readonly placeholder?: string }> = ElementsBS.ChatFormAnswerInput.make;

// tslint:disable-next-line:interface-over-type-literal
export type ChatFormAnswerOptions_make_Props = { readonly onSelect: (_1:Shared_Question_selectOption) => void; readonly options: list<Shared_Question_selectOption> };

export const ChatFormAnswerOptions_make: React.ComponentType<{ readonly onSelect: (_1:Shared_Question_selectOption) => void; readonly options: list<Shared_Question_selectOption> }> = ElementsBS.ChatFormAnswerOptions.make;

// tslint:disable-next-line:interface-over-type-literal
export type Link_make_Props = {
  readonly active?: boolean; 
  readonly children: React.ReactNode; 
  readonly to_: string
};

export const Link_make: React.ComponentType<{
  readonly active?: boolean; 
  readonly children: React.ReactNode; 
  readonly to_: string
}> = ElementsBS.Link.make;

// tslint:disable-next-line:interface-over-type-literal
export type CategoryThumbnail_make_Props<T1,T2,T3> = { readonly data: {
  readonly information: T3; 
  readonly introduction: T2; 
  readonly label: T1
} };

export const CategoryThumbnail_make: React.ComponentType<{ readonly data: {
  readonly information: any; 
  readonly introduction: any; 
  readonly label: any
} }> = ElementsBS.CategoryThumbnail.make;

// tslint:disable-next-line:interface-over-type-literal
export type ApplicationThumbnail_make_Props<appName> = {
  readonly appName: appName; 
  readonly id: string; 
  readonly link: string
};

export const ApplicationThumbnail_make: React.ComponentType<{
  readonly appName: any; 
  readonly id: string; 
  readonly link: string
}> = ElementsBS.ApplicationThumbnail.make;

// tslint:disable-next-line:interface-over-type-literal
export type Tag_make_Props = {
  readonly active: boolean; 
  readonly onClick: (_1:ReactEvent_Mouse_t) => void; 
  readonly text: string
};

export const Tag_make: React.ComponentType<{
  readonly active: boolean; 
  readonly onClick: (_1:ReactEvent_Mouse_t) => void; 
  readonly text: string
}> = ElementsBS.Tag.make;
