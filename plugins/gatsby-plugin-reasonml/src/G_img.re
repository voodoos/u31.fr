type t_fixed;
type t_fluid;

[@bs.module "gatsby-image"] [@react.component]
external make: (~fixed: t_fixed=?, ~fluid: t_fluid=?) => React.element =
  "default";