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
          <div dangerouslySetInnerHTML={"__html": article##html} />
        </div>;
      },
      articles,
    );
  arts |> array;
};