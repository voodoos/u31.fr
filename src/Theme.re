open Css;

let fontFamily = "'Merriweather', serif";
let fontFamily = "'Quattrocento', serif";

let page_title = style([textAlign(`center), textTransform(`uppercase)]);

//////////////////
/// TYPOGRAPHY ///
//////////////////

let font_base_size = em(0.5);
let font_grow_factor = vw(1.0);
let font_scale = 1.20;
let font_size_rem = (~level) => em(font_scale ** level);
let make_global_scale = () =>
  List.iter(
    i =>
      Css.global(
        "h" ++ string_of_int(i),
        [fontSize(font_size_rem(~level=float_of_int(6 - i)))],
      ),
    [1, 2, 3, 4, 5],
  );

//////////////////
///// LAYOUT /////
//////////////////

let main_block_max_size = ch(50.);
let large_block_max_size = ch(62.);

let break = point =>
  switch (point) {
  | `mobileOnly => "(max-width: 1200px)"
  | `mediumMobileOnly => "(max-width: 910px)"
  | `smallMobileOnly => "(max-width: 700px)"
  | `simpleGallery => "(max-width: 480px)"
  };

//////////////////
///// GLOBAL /////
//////////////////
/* See Styles.r*/