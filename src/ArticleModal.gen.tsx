/* TypeScript file generated from ArticleModal.re by genType. */
/* eslint-disable import/first */


import * as React from 'react';

// tslint:disable-next-line:no-var-requires
const ArticleModalBS = require('./ArticleModal.bs');

// tslint:disable-next-line:interface-over-type-literal
export type Props<T1,T2,T3> = {
  readonly data: {
    readonly information: T3; 
    readonly introduction: T2; 
    readonly label: T1
  }; 
  readonly isOpen: boolean; 
  readonly onClose: () => void
};

export const make: React.ComponentType<{
  readonly data: {
    readonly information: any; 
    readonly introduction: any; 
    readonly label: any
  }; 
  readonly isOpen: boolean; 
  readonly onClose: () => void
}> = ArticleModalBS.make;
