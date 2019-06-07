open Css;

// Global style is called in App.js
let make_global_style = () => {
  global(
    "body",
    [
      backgroundColor(white),
      fontFamily(Theme.fontFamily),
      selector("a", [color(currentColor), textDecoration(`none)]),
    ],
  );
};