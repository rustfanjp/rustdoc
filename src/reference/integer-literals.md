% Integer literals

##### Integer literals

An _integer literal_ has one of four forms:

* A _decimal literal_ starts with a *decimal digit* and continues with any
  mixture of *decimal digits* and _underscores_.
* A _hex literal_ starts with the character sequence `U+0030` `U+0078`
  (`0x`) and continues as any mixture of hex digits and underscores.
* An _octal literal_ starts with the character sequence `U+0030` `U+006F`
  (`0o`) and continues as any mixture of octal digits and underscores.
* A _binary literal_ starts with the character sequence `U+0030` `U+0062`
  (`0b`) and continues as any mixture of binary digits and underscores.

Like any literal, an integer literal may be followed (immediately,
without any spaces) by an _integer suffix_, which forcibly sets the
type of the literal. The integer suffix must be the name of one of the
integral types: `u8`, `i8`, `u16`, `i16`, `u32`, `i32`, `u64`, `i64`,
`isize`, or `usize`.

The type of an _unsuffixed_ integer literal is determined by type inference:

* If an integer type can be _uniquely_ determined from the surrounding
  program context, the unsuffixed integer literal has that type.

* If the program context under-constrains the type, it defaults to the
  signed 32-bit integer `i32`.

* If the program context over-constrains the type, it is considered a
  static type error.

Examples of integer literals of various forms:

```
123i32;                            // type i32
123u32;                            // type u32
123_u32;                           // type u32
0xff_u8;                           // type u8
0o70_i16;                          // type i16
0b1111_1111_1001_0000_i32;         // type i32
0usize;                            // type usize
```

