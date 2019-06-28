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
          backgroundColor(Theme.bg_color),
          fontFamily(Theme.fontFamily),
          fontSize(
            `calc((`add, Theme.font_base_size, Theme.font_grow_factor)),
          ),
        ],
      ),
      selector(
        "a",
        [
          color(currentColor),
          textDecoration(`underline),
          textDecorationStyle(`dotted),
          textDecorationColor(hex("4a4a4a")),
          selector("&:hover", [textDecorationStyle(`solid)]),
        ],
      ),
      selector("h1, h2, h3, h4, h5", [textAlign(`left)]),
      selector(".gatsby-highlight", [fontSize(em(0.8))]),
    ],
  );
};