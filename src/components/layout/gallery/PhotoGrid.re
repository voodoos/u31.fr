open Helpers;
module S = {
  open Css;
  let grid = style([]);
};

[@react.component]
let make = (~photos) => {
  let i = ref(0);
  let key_plus = () => {
    i := i^ + 1;
    string_of_int(i^);
  };
  <div className=S.grid>
    {Array.map(
       photo => {
         let photo = photo##node##childImageSharp;
         <Image photo key={key_plus()} />;
       },
       photos,
     )
     |> array}
  </div>;
};