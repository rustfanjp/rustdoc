% Raw string literals

##### Raw string literals

Raw string literals do not process any escapes. They start with the character
`U+0072` (`r`), followed by zero or more of the character `U+0023` (`#`) and a
`U+0022` (double-quote) character. The _raw string body_ can contain any sequence
of Unicode characters and is terminated only by another `U+0022` (double-quote)
character, followed by the same number of `U+0023` (`#`) characters that preceded
the opening `U+0022` (double-quote) character.

All Unicode characters contained in the raw string body represent themselves,
the characters `U+0022` (double-quote) (except when followed by at least as
many `U+0023` (`#`) characters as were used to start the raw string literal) or
`U+005C` (`\`) do not have any special meaning.

Examples for string literals:

```
"foo"; r"foo";                     // foo
"\"foo\""; r#""foo""#;             // "foo"

"foo #\"# bar";
r##"foo #"# bar"##;                // foo #"# bar

"\x52"; "R"; r"R";                 // R
"\\x52"; r"\x52";                  // \x52
```

