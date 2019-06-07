open Helpers;

[@react.component]
let make = (~articles) => {
  let arts =
    Array.map(
      a => {
        let article = a##node##childMarkdownRemark;
        <div
          key={
            article##id;
          }>
          <h1> {article##frontmatter##title |> text} </h1>
          <span> {article##frontmatter##date |> text} </span>
          <div dangerouslySetInnerHTML={"__html": article##html} />
        </div>;
      },
      articles,
    );
  arts |> array;
};