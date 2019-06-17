open Helpers;

module S = {
  open Css;
  let wrapper = style([]);
  let content =
    style([
      boxSizing(`borderBox),
      marginLeft(`auto),
      marginRight(`auto),
      marginTop(rem(3.)),
      maxWidth(Theme.main_block_max_size),
      width(pct(100.)),
      textAlign(`justify),
      media(Theme.break(`mobileOnly), [width(pct(90.))]),
    ]);

  let large_content =
    merge([content, style([maxWidth(Theme.large_block_max_size)])]);
};

Styles.make_global_style();

[@react.component]
let make = (~large=false, ~page_description=?, ~children) => {
  Js.log(large);
  let title = "The Naked Blog";
  <div className=S.wrapper>
    <BsReactHelmet>
      <html lang="en" />
      <title> {title |> text} </title>
      <meta name="description" content="Everything is awesome!" />
    </BsReactHelmet>
    /*<link
        href="https://fonts.googleapis.com/css?family=Quattrocento&display=swap"
        rel="stylesheet"
        crossorigin=true
      />*/
    <Header title ?page_description />
    <main className={if (large) {S.large_content} else {S.content}}>
      children
    </main>
    <footer />
  </div>;
};