% Macros

## Macros

`macro_rules` allows users to define syntax extension in a declarative way.  We
call such extensions "macros by example" or simply "macros" — to be distinguished
from the "procedural macros" defined in [compiler plugins][plugin].

Currently, macros can expand to expressions, statements, items, or patterns.

(A `sep_token` is any token other than `*` and `+`. A `non_special_token` is
any token other than a delimiter or `$`.)

The macro expander looks up macro invocations by name, and tries each macro
rule in turn. It transcribes the first successful match. Matching and
transcription are closely related to each other, and we will describe them
together.

