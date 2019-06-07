open Helpers;

module S = {
  open Css;
  let wrapper = style([textAlign(`center)]);
  let content =
    style([
      display(`inlineBlock),
      boxSizing(`borderBox),
      maxWidth(em(50.)),
      width(pct(100.)),
      padding(em(1.)),
      textAlign(`justify),
    ]);
};

Styles.make_global_style();

[@react.component]
let make = (~children) => {
  let title = "The Naked Code";
  <div className=S.wrapper>
    <BsReactHelmet>
      <title> {title |> text} </title>
      <meta name="description" content="Everything is awesome!" />
      <link
        href="https://fonts.googleapis.com/css?family=Merriweather:400,700&display=swap"
        rel="stylesheet"
      />
    </BsReactHelmet>
    <Header title />
    <div className=S.content> children </div>
  </div>;
};