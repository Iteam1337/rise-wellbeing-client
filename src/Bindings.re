module Framer = {
  module Motion = {
    [@bs.module "framer-motion"] [@bs.scope "motion"] [@react.component]
    external div:
      (
        ~positionTransition: bool,
        ~children: React.element,
        ~initial: Js.t('initial),
        ~animate: Js.t('animate),
        ~exit: Js.t('exit)
      ) =>
      React.element =
      "div";

    [@bs.module "framer-motion"] [@bs.scope "motion"] [@react.component]
    external li:
      (
        ~positionTransition: bool,
        ~children: React.element,
        ~initial: Js.t('initial),
        ~animate: Js.t('animate),
        ~exit: Js.t('exit)
      ) =>
      React.element =
      "li";

    module Div = {
      [@bs.module "framer-motion"] [@bs.scope "motion"] [@react.component]
      external make:
        (
          ~positionTransition: bool,
          ~children: React.element,
          ~initial: Js.t('initial),
          ~animate: Js.t('animate),
          ~exit: Js.t('exit)
        ) =>
        React.element =
        "div";
    };
  };

  module AnimatePresence = {
    [@bs.module "framer-motion"] [@react.component]
    external make: (~children: React.element, ~initial: bool) => React.element =
      "AnimatePresence";
  };
};
