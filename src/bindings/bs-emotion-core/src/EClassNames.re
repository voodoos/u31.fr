/* code from bs-css */

let rec ruleToJs = rule =>
  switch (rule) {
  | `declaration(name, value) when name == "content" => (
      name,
      Js.Json.string(value == "" ? "\"\"" : value),
    )
  | `declaration(name, value) => (name, Js.Json.string(value))
  | `selector(name, ruleset) => (name, rulesToJson(ruleset))
  | `shadow(value) => ("boxShadow", Js.Json.string(value))
  | `textShadow(value) => ("textShadow", Js.Json.string(value))
  | `transition(value) => ("transition", Js.Json.string(value))
  | `animation(value) => ("animation", Js.Json.string(value))
  }

and rulesToJson = rules =>
  List.map(ruleToJs, rules)->Js.Dict.fromList->Js.Json.object_;

type class_name = string;

type style = list(Css.rule);

type emo = {
  .
  [@bs.meth] "css": array(Js.Json.t) => string,
  [@bs.meth] "cx": array(string) => string, // todo
  "theme": string // todo
};

[@bs.module "@emotion/core"] [@react.component]
external make: (~children: emo => React.element) => React.element =
  "ClassNames";