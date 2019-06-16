open Helpers;

module S = {
  open Css;
  let wrapper = style([textAlign(`center)]);
  let content =
    style([
      display(`inlineBlock),
      boxSizing(`borderBox),
      width(Theme.main_block_size),
      padding(em(1.)),
      textAlign(`justify),
      media(Theme.break(`mobileOnly), [width(pct(90.))]),
    ]);

  let large_content =
    merge([content, style([width(Theme.large_block_size)])]);
};

Styles.make_global_style();

[@react.component]
let make = (~large=false, ~children) => {
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
    <Header title />
    <div className={if (large) {S.large_content} else {S.content}}>
      children
    </div>
  </div>;
};