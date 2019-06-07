open Helpers;

module S = {
  open Css;

  let header =
    style([
      borderBottom(px(5), `dashed, black),
      paddingTop(em(1.)),
      textAlign(`center),
      minWidth(px(370)),
      selector(
        "& h1",
        [
          fontSize(em(5.)),
          margin(`zero),
          media("(max-width: 640px)", [fontSize(em(3.))]),
        ],
      ),
    ]);

  let title_box = style([display(`inlineBlock)]);

  let menu_item_styles = [
    display(`inlineBlock),
    padding(px(10)),
    marginTop(em(0.5)),
    marginBottom(em(0.8)),
    border(px(2), `solid, white),
    fontSize(em(1.5)),
    media("(max-width: 640px)", [fontSize(em(1.))]),
    textTransform(`uppercase),
    selector(
      "&.active",
      [
        borderStyle(`solid),
        borderColor(black),
        backgroundColor(black),
        color(white),
      ],
    ),
    selector("&:hover", [borderStyle(`dotted), borderColor(black)]),
  ];

  let menu =
    style([
      width(pct(100.)),
      display(`flex),
      marginBottom(em(0.3)),
      flexDirection(`row),
      flexWrap(`nowrap),
      justifyContent(`spaceEvenly),
      selector("& div a", menu_item_styles),
    ]);
};

[@react.component]
let make = (~title) => {
  let activeClassName = "active";
  <div className=S.header>
    <div className=S.title_box>
      <h1> {title |> text} </h1>
      <div className=S.menu>
        <div>
          <Gatsby.Link _to="/" activeClassName> {"Blog" |> text} </Gatsby.Link>
        </div>
        <div>
          <Gatsby.Link _to="/about/" activeClassName>
            {"Research" |> text}
          </Gatsby.Link>
        </div>
        <div>
          <Gatsby.Link _to="/critics/" activeClassName>
            {"Keyword-critics" |> text}
          </Gatsby.Link>
        </div>
      </div>
    </div>
  </div>;
};