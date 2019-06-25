// A helper component for easier use of EGlobal

[@react.component]
let make = (~styles: list(Css.rule)) => {
  let styles = [|EClassNames.rulesToJson(styles)|];
  <EGlobal styles />;
};