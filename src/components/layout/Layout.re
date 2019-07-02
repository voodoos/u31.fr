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

[@react.component]
let make =
    (
      ~large=false,
      ~page_description=?,
      ~pathname,
      ~lang="en",
      ~showLangSwitch=true,
      ~children,
    ) => {
  Js.log(pathname);
  let title = "The Naked Blog";
  let locale = Locale.fromString(lang);
  <ReactIntl.IntlProvider
    locale={locale->Locale.toString}
    messages={locale->Locale.translations->Locale.translationsToDict}>
    <React.Fragment>
      <BsReactHelmet>
        <html lang />
        <title> {title |> text} </title>
        <meta name="description" content="Everything is awesome!" />
      </BsReactHelmet>
      <WithCss>
        {css =>
           <div className={css([S.wrapper])}>
             <GlobalCss styles={Styles.get_global_style()} />
             /*<link
                 href="https://fonts.googleapis.com/css?family=Quattrocento&display=swap"
                 rel="stylesheet"
                 crossorigin=true
               />*/
             <Header title ?page_description showLangSwitch pathname />
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
      </WithCss>
    </React.Fragment>
  </ReactIntl.IntlProvider>;
};