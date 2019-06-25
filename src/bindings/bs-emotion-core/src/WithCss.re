// A Helper to use Emotion in the ClassNames style
// Only support the css function
open EClassNames;

[@react.component]
let make =
    (~children: (list(EClassNames.style) => class_name) => React.element) => {
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