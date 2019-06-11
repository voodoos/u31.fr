module S = {
  open Css;
  let grid_item = style([]);

  let thumbnail = active => {
    style([display(active ? `none : `block)]);
  };

  let wide = active => {
    style([display(active ? `block : `none)]);
  };
};

[@react.component]
let make = (~photo) => {
  let (active, set_active) = React.useState(() => false);
  let onClick = _evt => set_active(a => a ? false : true);
  <div className=S.grid_item onClick>
    <div className={S.wide(active)}> <Gatsby.Img fluid=photo##fluid /> </div>
    <div className={S.thumbnail(active)}>
      <Gatsby.Img fixed=photo##fixed />
    </div>
  </div>;
};