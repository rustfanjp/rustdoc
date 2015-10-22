% Infinite loops

### Infinite loops

A `loop` expression denotes an infinite loop.

A `loop` expression may optionally have a _label_. The label is written as
a lifetime preceding the loop expression, as in `'foo: loop{ }`. If a
label is present, then labeled `break` and `continue` expressions nested
within this loop may exit out of this loop or return control to its head.
See [Break expressions](#break-expressions) and [Continue
expressions](#continue-expressions).

