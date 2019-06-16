open Css;

// Global style is called in App.js
let make_global_style = () => {
  ignore(
    fontFace(
      ~fontFamily="Quattrocento",
      ~src=[`url("/fonts/Quattrocento/Quattrocento-Regular.ttf")],
      ~fontWeight=`normal,
      (),
    ),
  );
  ignore(
    fontFace(
      ~fontFamily="Quattrocento",
      ~src=[`url("/fonts/Quattrocento/Quattrocento-Bold.ttf")],
      ~fontWeight=`bold,
      (),
    ),
  );
  global("html", [fontSize(`calc((`add, em(0.5), vw(1.0))))]);
  global(
    "body",
    [
      backgroundColor(white),
      fontFamily(Theme.fontFamily),
      //fontSize(Theme.font_base_size),
      selector("a", [color(currentColor), textDecoration(`none)]),
      // media(Theme.break(`mediumMobileOnly), [fontSize(px(15))]),
      // media(Theme.break(`smallMobileOnly), [fontSize(px(10))]),
    ],
  );
  global("h1, h2, h3, h4, h5", [textAlign(`left)]);
  global("h1", [fontSize(Theme.font_size_rem(~level=5.))]);
  global("h2", [fontSize(Theme.font_size_rem(~level=4.))]);
  global("h3", [fontSize(Theme.font_size_rem(~level=3.))]);
  global("h4", [fontSize(Theme.font_size_rem(~level=2.))]);
  global("h5", [fontSize(Theme.font_size_rem(~level=1.))]);
};