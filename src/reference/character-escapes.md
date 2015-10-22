% Character escapes

##### Character escapes

Some additional _escapes_ are available in either character or non-raw string
literals. An escape starts with a `U+005C` (`\`) and continues with one of the
following forms:

* An _8-bit code point escape_ starts with `U+0078` (`x`) and is
  followed by exactly two _hex digits_. It denotes the Unicode code point
  equal to the provided hex value.
* A _24-bit code point escape_ starts with `U+0075` (`u`) and is followed
  by up to six _hex digits_ surrounded by braces `U+007B` (`{`) and `U+007D`
  (`}`). It denotes the Unicode code point equal to the provided hex value.
* A _whitespace escape_ is one of the characters `U+006E` (`n`), `U+0072`
  (`r`), or `U+0074` (`t`), denoting the Unicode values `U+000A` (LF),
  `U+000D` (CR) or `U+0009` (HT) respectively.
* The _backslash escape_ is the character `U+005C` (`\`) which must be
  escaped in order to denote *itself*.

