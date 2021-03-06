open Helpers;
module S = {
  open Css;
  let grid = [
    display(`grid),
    width(pct(100.)),
    unsafe("gridTemplateColumns", "repeat(auto-fill, 200px)"),
    gridAutoFlow(`rowDense),
    gridGap(rem(1.)),
    justifyContent(`center),
    media(
      Theme.break(`simpleGallery),
      [important(unsafe("gridTemplateColumns", "repeat(auto-fill, 100%)"))],
    ),
  ];
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
    <WithCss>
      {css =>
         <div className={css([S.grid])}>
           {Array.map(
              photo => {
                let key = next_key();
                let nphoto = photo##node;
                let active = key == active;
                let onClick = onClick(key);
                <Image nphoto active onClick key={string_of_int(key)} />;
              },
              photos,
            )
            |> array}
         </div>}
    </WithCss>
  </React.Fragment>;
  /*<h1 className=Theme.page_title>
      {"A collection of hastily taken and carelessly cropped photographs of tortured squares of paper"
       |> text}
    </h1>*/
};