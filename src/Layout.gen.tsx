/* TypeScript file generated from Layout.re by genType. */
/* eslint-disable import/first */


import * as React from 'react';

const $$toRE891194928: { [key: string]: any } = {"Large": 48800667, "Medium": 861718677, "None": 870530776, "Small": 311976103};

// tslint:disable-next-line:no-var-requires
const LayoutBS = require('./Layout.bs');

// tslint:disable-next-line:interface-over-type-literal
export type Props = {
  readonly children: React.ReactNode; 
  readonly classNames?: string; 
  readonly spacing?: 
    "Large"
  | "Medium"
  | "None"
  | "Small"
};

export const Container_make: React.ComponentType<{
  readonly children: React.ReactNode; 
  readonly classNames?: string; 
  readonly spacing?: 
    "Large"
  | "Medium"
  | "None"
  | "Small"
}> = function Layout_Container(Arg1: any) {
  const $props = {children:Arg1.children, classNames:Arg1.classNames, spacing:(Arg1.spacing == null ? undefined : $$toRE891194928[Arg1.spacing])};
  const result = React.createElement(LayoutBS.Container.make, $props);
  return result
};

// tslint:disable-next-line:interface-over-type-literal
export type Column_make_Props = {
  readonly children: React.ReactNode; 
  readonly classNames?: string; 
  readonly spacing?: 
    "Large"
  | "Medium"
  | "None"
  | "Small"
};

export const Column_make: React.ComponentType<{
  readonly children: React.ReactNode; 
  readonly classNames?: string; 
  readonly spacing?: 
    "Large"
  | "Medium"
  | "None"
  | "Small"
}> = function Layout_Column(Arg1: any) {
  const $props = {children:Arg1.children, classNames:Arg1.classNames, spacing:(Arg1.spacing == null ? undefined : $$toRE891194928[Arg1.spacing])};
  const result = React.createElement(LayoutBS.Column.make, $props);
  return result
};

// tslint:disable-next-line:interface-over-type-literal
export type Row_make_Props = {
  readonly children: React.ReactNode; 
  readonly classNames?: string; 
  readonly spacing?: 
    "Large"
  | "Medium"
  | "None"
  | "Small"
};

export const Row_make: React.ComponentType<{
  readonly children: React.ReactNode; 
  readonly classNames?: string; 
  readonly spacing?: 
    "Large"
  | "Medium"
  | "None"
  | "Small"
}> = function Layout_Row(Arg1: any) {
  const $props = {children:Arg1.children, classNames:Arg1.classNames, spacing:(Arg1.spacing == null ? undefined : $$toRE891194928[Arg1.spacing])};
  const result = React.createElement(LayoutBS.Row.make, $props);
  return result
};
