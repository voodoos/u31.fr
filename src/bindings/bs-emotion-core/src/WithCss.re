// A Helper to use Emotion in the ClassNames style
// Only support the css function
open EClassNames;

[@react.component]
let make =
    (
      ~children:
         (
           (
             ~classNames: list(EClassNames.class_name)=?,
             list(EClassNames.style)
           ) =>
           class_name
         ) =>
         React.element,
    ) => {
  <EClassNames>
    {emo => {
       let f = (~classNames=[], rules) => {
         let rjs = Array.of_list(List.map(rulesToJson, rules));
         let css_name = emo##css(rjs);
         if (List.length(classNames) == 0) {
           css_name;
         } else {
           let cjs = Array.of_list([css_name, ...classNames]);
           emo##cx(cjs);
         };
       };
       children(f);
     }}
  </EClassNames>;
};