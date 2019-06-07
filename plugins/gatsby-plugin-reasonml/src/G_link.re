[@bs.module "gatsby"] [@react.component]
external make:
  (
    ~_to: string,
    ~activeClassName: string=?,
    ~activeStyle: {..}=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~partiallyActive: bool=?,
    ~replace: bool=?,
    ~children: React.element
  ) =>
  React.element =
  "Link";

/* todo: navigate*/