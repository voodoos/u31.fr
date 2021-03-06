open Helpers;

module S = {
  open Css;

  let fixed_header_anim =
    keyframes([
      (0, [transform(translate(`zero, pct(-100.)))]),
      (100, [transform(translate(`zero, `zero))]),
    ]);
  //keyframes([(0, [opacity(0.)]), (100, [opacity(1.)])]);

  let header = [
    borderBottom(px(5), `dashed, black),
    width(pct(100.)),
    paddingTop(em(1.)),
    textAlign(`center),
    zIndex(100),
    selector("a", [textDecoration(`none)]),
    selector(
      "&.fixed",
      [
        position(`sticky),
        top(`zero),
        left(`zero),
        paddingTop(`zero),
        fontSize(em(0.7)),
        backgroundColor(Theme.bg_color),
        animation(~duration=500, fixed_header_anim),
      ],
    ),
  ];

  let title_box = [
    display(`inlineFlex),
    flexDirection(`row),
    flexWrap(`wrap),
    justifyContent(`spaceAround),
    alignItems(`center),
    alignContent(`center),
    selector(".fixed &", [width(pct(100.))]),
    selector(
      "& h1",
      [
        fontSize(em(5.)),
        textAlign(`center),
        margin(`zero),
        flexBasis(pct(100.)),
        selector(".fixed &", [fontSize(em(2.)), flexBasis(`auto)]),
      ],
    ),
  ];

  let menu_item_styles = [
    display(`inlineBlock),
    padding(px(10)),
    paddingTop(px(12)),
    marginTop(em(0.5)),
    marginRight(Theme.menu_item_sep),
    marginBottom(em(0.8)),
    border(px(2), `dotted, transparent),
    fontSize(em(1.5)),
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
    selector(".fixed &", [marginTop(`zero), marginBottom(`zero)]),
    transition(~duration=100, "border-color"),
    selector("&:hover", [borderStyle(`dotted), borderColor(black)]),
  ];

  let menu = [
    //width(pct(100.)),
    display(`flex),
    paddingLeft(Theme.menu_item_sep),
    marginBottom(em(0.3)),
    flexDirection(`row),
    flexWrap(`wrap),
    justifyContent(`spaceEvenly),
    selector("& a", menu_item_styles),
    selector(".fixed &", [marginTop(`zero), marginBottom(`zero)]),
  ];

  let page_description = [
    margin(`zero),
    paddingTop(rem(2.)),
    paddingBottom(rem(2.)),
    textAlign(`center),
    borderBottom(px(5), `dashed, black),
  ];

  let sharp = [display(`inlineBlock)];
  let des_text = [display(`inlineBlock)];
};

[@react.component]
let make = (~title, ~page_description=?, ~pathname, ~showLangSwitch=true) => {
  let (fixed, set_fixed) = React.useState(() => false);
  let activeClassName = "active";
  React.useEffect(() => {
    // We need to watch scroll to fix the header
    let target = Webapi.Dom.Document.asEventTarget(Webapi.Dom.document);
    let scroll_handler = _e => {
      let win = Helpers.get_win();
      let yo = win |> Webapi.Dom.Window.pageYOffset;

      // if (!fixed && yo > 800.) {
      //   set_fixed(_ => true);
      // };

      // if (fixed && yo < 200.) {
      //   set_fixed(_ => false);
      // };
    };
    Helpers.new_event_listener("scroll", scroll_handler, target);
    //None; // Deactivating small nav. Need some thinking. nice but useless ?
  });
  let intl = ReactIntl.useIntl();
  let pref = Locale.pref(intl);
  <React.Fragment>
    <WithCss>
      {css =>
         <React.Fragment>
           <header
             className={css(~classNames=[fixed ? "fixed" : ""], [S.header])}>
             <div className={css([S.title_box])}>
               <h1> {title |> text} </h1>
               <nav className={css([S.menu])}>
                 <Gatsby.Link _to={pref("/")} activeClassName>
                   <ReactIntl.FormattedMessage
                     id="menu.blog"
                     defaultMessage="Blog"
                   />
                 </Gatsby.Link>
                 <Gatsby.Link _to={pref("/about/")} activeClassName>
                   <ReactIntl.FormattedMessage
                     id="menu.about"
                     defaultMessage="AboutDef"
                   />
                 </Gatsby.Link>
                 <Gatsby.Link _to={pref("/origallery/")} activeClassName>
                   <ReactIntl.FormattedMessage
                     id="menu.gallery"
                     defaultMessage="Origallery"
                   />
                 </Gatsby.Link>
               </nav>
             </div>
           </header>
           /* <Gatsby.Link _to="/critics/" activeClassName>
                {"K-Critics" |> text}
              </Gatsby.Link>*/
           {if (showLangSwitch) {
              let className =
                Css.(
                  css([
                    [
                      position(`absolute),
                      left(pct(75.)),
                      padding(em(0.3)),
                      paddingTop(em(0.2)),
                      paddingBottom(em(0.2)),
                      border(px(3), `dotted, black),
                      borderTopStyle(`none),
                      fontSize(em(0.8)),
                      textAlign(`center),
                      width(em(1.2)),
                      textTransform(`uppercase),
                      selector(
                        "&:hover",
                        [borderStyle(`solid), borderTopStyle(`none)],
                      ),
                      selector("& a", [textDecoration(`none)]),
                    ],
                  ])
                );
              Locale.(
                <Gatsby.Link _to={switch_lang(pathname)}>
                  <span className> {intl->get_other->toString |> text} </span>
                </Gatsby.Link>
              );
            } else {
              React.null;
            }}
           {switch (page_description) {
            | Some(des) =>
              <React.Fragment>
                <h4 className={css([S.page_description])}> {des |> text} </h4>
              </React.Fragment>
            | None => React.null
            }}
         </React.Fragment>}
    </WithCss>
  </React.Fragment>;
};