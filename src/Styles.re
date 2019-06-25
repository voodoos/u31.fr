open Css;

// Global style is called in App.js
let get_global_style = () => {
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
  List.rev_append(
    Theme.make_global_scale(),
    [
      selector("html", []),
      selector(
        "body",
        [
          backgroundColor(white),
          fontFamily(Theme.fontFamily),
          selector("a", [color(currentColor), textDecoration(`none)]),
          fontSize(
            `calc((`add, Theme.font_base_size, Theme.font_grow_factor)),
          ),
        ],
      ),
      selector("h1, h2, h3, h4, h5", [textAlign(`left)]),
      selector(".gatsby-highlight", [fontSize(em(0.8))]),
    ],
  );
};