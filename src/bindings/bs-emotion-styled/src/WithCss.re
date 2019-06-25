// A Helper to use Emotion in the ClassName style
// Only support the css function
open EClassNames;

type style = list(Css.rule);

[@react.component]
let make = (~children: (list(style) => class_name) => React.element) => {
  <EClassNames>
    {emo => {
       let f = rules => {
         let rjs = List.map(rulesToJson, rules);
         emo##css(Array.of_list(rjs));
       };
       children(f);
     }}
  </EClassNames>;
};