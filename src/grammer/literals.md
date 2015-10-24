% Literals

### Literals

```antlr
lit_suffix : ident;
literal : [ string_lit | char_lit | byte_string_lit | byte_lit | num_lit | bool_lit ] lit_suffix ?;
```

The optional `lit_suffix` production is only used for certain numeric literals,
but is reserved for future extension. That is, the above gives the lexical
grammar, but a Rust parser will reject everything but the 12 special cases
mentioned in [Number literals](reference.html#number-literals) in the
reference.

