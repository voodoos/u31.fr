open Css;

let fontFamily = "'Merriweather', serif";
let fontFamily = "'Quattrocento', serif";

let page_title = style([textAlign(`center), textTransform(`uppercase)]);

//let font_scale = 1.25;
let font_base_size = px(20);
let font_scale = 1.20;
let font_size_rem = (~level) => em(font_scale ** level);

let main_block_size = pct(50.);
let large_block_size = pct(70.);

let break = point =>
  switch (point) {
  | `mobileOnly => "(max-width: 1200px)"
  | `mediumMobileOnly => "(max-width: 910px)"
  | `smallMobileOnly => "(max-width: 700px)"
  };