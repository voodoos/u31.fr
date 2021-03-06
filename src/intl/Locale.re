[@bs.module "./translations/fr.json"]
external fr: array(ReactIntl.translation) = "default";
[@bs.module "./translations/en.json"]
external en: array(ReactIntl.translation) = "default";

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

//let all = [|En, Fr|];

let toString =
  fun
  | En => "en"
  | Fr => "fr";

let toPath =
  fun
  | En => ""
  | Fr => "/fr";

let translations =
  fun
  | En => en
  | Fr => fr;

let other =
  fun
  | En => Fr
  | Fr => En;

let fromString =
  fun
  | "fr" => Fr
  | _ => En;

// Intl specific code
let get = ReactIntl.Intl.locale;

// Add locale to url
let pref = (intl, url) => intl->get->fromString->toPath ++ url;

let get_other = intl => other @@ fromString @@ get @@ intl;

// Get Switched URL
let switch_lang =
  fun
  | "/" => "/fr/"
  | path => {
      String.(
        switch (path->sub(1, 2)) {
        | "fr" => path->sub(3, path->length - 3)
        | _ => "/fr" ++ path
        }
      );
    };