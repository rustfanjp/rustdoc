% Whitespace

## Whitespace

Whitespace is any non-empty string containing only the following characters:

- `U+0020` (space, `' '`)
- `U+0009` (tab, `'\t'`)
- `U+000A` (LF, `'\n'`)
- `U+000D` (CR, `'\r'`)

Rust is a "free-form" language, meaning that all forms of whitespace serve only
to separate _tokens_ in the grammar, and have no semantic significance.

A Rust program has identical meaning if each whitespace element is replaced
with any other legal whitespace element, such as a single space character.

