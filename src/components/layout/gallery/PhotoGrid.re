open Helpers;
module S = {
  open Css;
  let grid =
    style([
      display(`grid),
      width(pct(100.)),
      unsafe("grid-template-columns", "repeat(auto-fill, 200px)"),
      gridAutoFlow(`rowDense),
      gridGap(rem(1.)),
      justifyContent(`center),
    ]);
};

[@react.component]
let make = (~photos) => {
  // Keys for list of images
  let i = ref(0);
  let next_key = () => {
    i := i^ + 1;
    i^;
  };
  // State hook, store the key of the active image
  let (active, set_active) = React.useState(() => 0);
  let onClick = (key, _evt) => set_active(a => a == key ? 0 : key);
  <React.Fragment>
    <h1 className=Theme.page_title>
      {"A collection of hastily taken and carelessly cropped photographs of tortured squares of paper"
       |> text}
    </h1>
    <div className=S.grid>
      {Array.map(
         photo => {
           let key = next_key();
           let photo = photo##node##childImageSharp;
           let active = key == active;
           let onClick = onClick(key);
           <Image photo active onClick key={string_of_int(key)} />;
         },
         photos,
       )
       |> array}
    </div>
  </React.Fragment>;
};