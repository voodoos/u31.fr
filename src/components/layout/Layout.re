open Helpers;

module S = {
  open Css;
  let wrapper = [];
  let content = [
    boxSizing(`borderBox),
    marginLeft(`auto),
    marginRight(`auto),
    marginTop(rem(3.)),
    maxWidth(Theme.main_block_max_size),
    width(pct(100.)),
    textAlign(`justify),
    unsafe("textJustify", "inter-character"),
    media(Theme.break(`mobileOnly), [width(pct(90.))]),
  ];

  let large_content = [content, [maxWidth(Theme.large_block_max_size)]];
};

//Styles.make_global_style();

[@react.component]
let make = (~large=false, ~page_description=?, ~children) => {
  let title = "The Naked Blog";
  <WithCss>
    {css =>
       <div className={css([S.wrapper])}>
         <BsReactHelmet>
           <html lang="en" />
           <title> {title |> text} </title>
           <meta name="description" content="Everything is awesome!" />
         </BsReactHelmet>
         <GlobalCss styles={Styles.get_global_style()} />
         /*<link
             href="https://fonts.googleapis.com/css?family=Quattrocento&display=swap"
             rel="stylesheet"
             crossorigin=true
           />*/
         <Header title ?page_description />
         <main
           className={css(
             if (large) {
               S.large_content;
             } else {
               [S.content];
             },
           )}>
           children
         </main>
         <footer />
       </div>}
  </WithCss>;
};