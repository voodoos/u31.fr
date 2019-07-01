[@bs.module "./translations/en.json"]
external en: array(ReactIntl.translation) = "default";
[@bs.module "./translations/fr.json"]
external fr: array(ReactIntl.translation) = "default";

let translationsToDict = (translations: array(ReactIntl.translation)) => {
  translations->Belt.Array.reduce(
    Js.Dict.empty(),
    (dict, entry) => {
      dict->Js.Dict.set(
        entry##id,
        switch (entry##message->Js.Nullable.toOption) {
        | None
        | Some("") => entry##defaultMessage
        | Some(message) => message
        },
      );
      dict;
    },
  );
};

type locale =
  | En
  | Fr;

let all = [|En, Fr|];

let toString =
  fun
  | En => "en"
  | Fr => "fr";

let fromString =
  fun
  | "fr" => Fr
  | _ => En;

let translations =
  fun
  | En => en
  | Fr => fr;

let other =
  fun
  | En => Fr
  | Fr => En;