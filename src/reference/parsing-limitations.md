% Parsing limitations

### Parsing limitations

The parser used by the macro system is reasonably powerful, but the parsing of
Rust syntax is restricted in two ways:

1. Macro definitions are required to include suitable separators after parsing
   expressions and other bits of the Rust grammar. This implies that
   a macro definition like `$i:expr [ , ]` is not legal, because `[` could be part
   of an expression. A macro definition like `$i:expr,` or `$i:expr;` would be legal,
   however, because `,` and `;` are legal separators. See [RFC 550] for more information.
2. The parser must have eliminated all ambiguity by the time it reaches a `$`
   _name_ `:` _designator_. This requirement most often affects name-designator
   pairs when they occur at the beginning of, or immediately after, a `$(...)*`;
   requiring a distinctive token in front can solve the problem.

[RFC 550]: https://github.com/rust-lang/rfcs/blob/master/text/0550-macro-future-proofing.md

