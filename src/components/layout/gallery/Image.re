open Helpers;

let border_size = 4;
let thumb_padding = 5;
let thumb_size = 200 + 0 * thumb_padding;

module S = {
  open Css;
  let grid_item = [
    width(px(thumb_size)),
    height(px(thumb_size)),
    media(Theme.break(`simpleGallery), [important(display(`none))]),
  ];

  let grid_item_wide = active => {
    [
      display(active ? `block : `none),
      position(`relative),
      overflow(`hidden),
      gridColumn(1, -1),
      borderRadius(px(5)),
      media(Theme.break(`simpleGallery), [important(display(`block))]),
    ];
  };

  let thumbnail = [
    display(`block),
    overflow(`hidden),
    position(`relative),
    top(px(- border_size)),
    left(px(- border_size)),
    width(pct(100.)),
    height(pct(100.)),
    border(px(2), `solid, black),
    backgroundColor(white),
    borderRadius(px(8)),
    onHover([border(px(2), `dashed, black)]),
  ];

  let label = [
    position(`absolute),
    width(pct(100.)),
    height(rem(2.)),
    lineHeight(rem(2.)),
    left(`zero),
    bottom(`zero),
    color(white),
    backgroundColor(rgba(0, 0, 0, 0.5)),
    selector(
      "& span",
      [
        display(`inlineBlock),
        width(pct(100.)),
        textAlign(`center),
        verticalAlign(`middle),
        fontSize(rem(1.2)),
      ],
    ),
  ];
};

[@react.component]
let make = (~photo, ~active, ~onClick) => {
  Js.log(photo);
  let label = {
    // todo: better bindings...
    let name = Obj.magic(photo##fluid)##originalName;
    Js.log(name);
    let name =
      switch (String.index(name, '_')) {
      | idx => String.sub(name, idx + 1, String.length(name) - idx - 1)
      | exception Not_found => name
      };
    switch (String.rindex(name, '.')) {
    | idx => String.sub(name, 0, idx)
    | exception Not_found => name
    };
  };
  <WithCss>
    {css =>
       <React.Fragment>
         <div className={css([S.grid_item])} onClick id=photo##id>
           <a className={css([S.thumbnail])} href={"#" ++ photo##id}>
             //target="_blank"
             //onClick={evt => ReactEvent.Mouse.preventDefault(evt)}
              <Gatsby.Img fixed=photo##fixed /> </a>
         </div>
         <a
           className={css([S.grid_item_wide(active)])}
           href="test"
           target="_blank">
           <Gatsby.Img fluid=photo##fluid />
           <div className={css([S.label])}>
             <span> {label |> text} </span>
           </div>
         </a>
       </React.Fragment>}
  </WithCss>;
};