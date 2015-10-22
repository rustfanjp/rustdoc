% Macro By Example

### Macro By Example

The macro expander matches and transcribes every token that does not begin with
a `$` literally, including delimiters. For parsing reasons, delimiters must be
balanced, but they are otherwise not special.

In the matcher, `$` _name_ `:` _designator_ matches the nonterminal in the Rust
syntax named by _designator_. Valid designators are `item`, `block`, `stmt`,
`pat`, `expr`, `ty` (type), `ident`, `path`, `tt` (either side of the `=>`
in macro rules). In the transcriber, the designator is already known, and so
only the name of a matched nonterminal comes after the dollar sign.

In both the matcher and transcriber, the Kleene star-like operator indicates
repetition. The Kleene star operator consists of `$` and parentheses, optionally
followed by a separator token, followed by `*` or `+`. `*` means zero or more
repetitions, `+` means at least one repetition. The parentheses are not matched or
transcribed. On the matcher side, a name is bound to _all_ of the names it
matches, in a structure that mimics the structure of the repetition encountered
on a successful match. The job of the transcriber is to sort that structure
out.

The rules for transcription of these repetitions are called "Macro By Example".
Essentially, one "layer" of repetition is discharged at a time, and all of them
must be discharged by the time a name is transcribed. Therefore, `( $( $i:ident
),* ) => ( $i )` is an invalid macro, but `( $( $i:ident ),* ) => ( $( $i:ident
),*  )` is acceptable (if trivial).

When Macro By Example encounters a repetition, it examines all of the `$`
_name_ s that occur in its body. At the "current layer", they all must repeat
the same number of times, so ` ( $( $i:ident ),* ; $( $j:ident ),* ) => ( $(
($i,$j) ),* )` is valid if given the argument `(a,b,c ; d,e,f)`, but not
`(a,b,c ; d,e)`. The repetition walks through the choices at that layer in
lockstep, so the former input transcribes to `(a,d), (b,e), (c,f)`.

Nested repetitions are allowed.

