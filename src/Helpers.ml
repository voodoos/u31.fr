let nothing = React.null

let text = React.string

let list list = list |> Array.of_list |> React.array
let array arr =  arr |> React.array

let nodeList node = node##list |> Array.to_list

(* Style helpers *)
let onHover styles = Css.selector "&:hover" styles

let and_then (f: 'a -> 'b option) = function
  | Some(v) -> f(v)
  | None -> None

(* Ocaml things *)
let opt_map f =
  function
  | Some(v) -> Some(f(v))
  | None -> None

let get_win () = Webapi.Dom.window
let get_doc () = Webapi.Dom.(document |> Document.asHtmlDocument)

(* Dom things *)
let get_body () =
  Webapi.Dom.(
    document |> Document.asHtmlDocument |> and_then(HtmlDocument.body)
  )

(* Add Event Listener and provide cleanup function *)
(* For use with UseEffect *)
let new_event_listener name handler target =
  let cleanup = fun () ->
          Webapi.Dom.EventTarget.removeEventListener
            name
            handler
            target
           in
  Webapi.Dom.EventTarget.addEventListener name handler target;
  Some cleanup