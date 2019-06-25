open Helpers;

module S = {
  open Css;

  let header = [
    borderBottom(px(5), `dashed, black),
    paddingTop(em(1.)),
    textAlign(`center),
    selector(
      "& h1",
      [fontSize(em(5.)), textAlign(`center), margin(`zero)],
    ),
  ];

  let title_box = [display(`inlineBlock)];

  let menu_item_styles = [
    display(`inlineBlock),
    padding(px(10)),
    marginTop(em(0.5)),
    marginBottom(em(0.8)),
    border(px(2), `dotted, transparent),
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
    transition(~duration=100, "border-color"),
    selector("&:hover", [borderStyle(`dotted), borderColor(black)]),
  ];

  let menu = [
    width(pct(100.)),
    display(`flex),
    marginBottom(em(0.3)),
    flexDirection(`row),
    flexWrap(`nowrap),
    justifyContent(`spaceEvenly),
    selector("& a", menu_item_styles),
  ];

  let page_description = [
    margin(`zero),
    paddingTop(rem(2.)),
    paddingBottom(rem(2.)),
    textAlign(`center),
    borderTop(px(5), `dashed, black),
  ];

  let sharp = [display(`inlineBlock)];
  let des_text = [display(`inlineBlock)];
};

[@react.component]
let make = (~title, ~page_description=?) => {
  let activeClassName = "active";
  <React.Fragment>
    <WithCss>
      {css =>
         <header className={css([S.header])}>
           <div className={css([S.title_box])}>
             <h1> {title |> text} </h1>
             <nav className={css([S.menu])}>
               <Gatsby.Link _to="/" activeClassName>
                 {"Blog" |> text}
               </Gatsby.Link>
               <Gatsby.Link _to="/about/" activeClassName>
                 {"About" |> text}
               </Gatsby.Link>
               <Gatsby.Link _to="/origallery/" activeClassName>
                 {"OriGallery" |> text}
               </Gatsby.Link>
             </nav>
           </div>
           /* <Gatsby.Link _to="/critics/" activeClassName>
                {"K-Critics" |> text}
              </Gatsby.Link>*/
           {switch (page_description) {
            | Some(des) =>
              <React.Fragment>
                <h4 className={css([S.page_description])}> {des |> text} </h4>
              </React.Fragment>
            | None => React.null
            }}
         </header>}
    </WithCss>
  </React.Fragment>;
};