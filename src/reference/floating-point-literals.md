% Floating-point literals

##### Floating-point literals

A _floating-point literal_ has one of two forms:

* A _decimal literal_ followed by a period character `U+002E` (`.`). This is
  optionally followed by another decimal literal, with an optional _exponent_.
* A single _decimal literal_ followed by an _exponent_.

Like integer literals, a floating-point literal may be followed by a
suffix, so long as the pre-suffix part does not end with `U+002E` (`.`).
The suffix forcibly sets the type of the literal. There are two valid
_floating-point suffixes_, `f32` and `f64` (the 32-bit and 64-bit floating point
types), which explicitly determine the type of the literal.

The type of an _unsuffixed_ floating-point literal is determined by
type inference:

* If a floating-point type can be _uniquely_ determined from the
  surrounding program context, the unsuffixed floating-point literal
  has that type.

* If the program context under-constrains the type, it defaults to `f64`.

* If the program context over-constrains the type, it is considered a
  static type error.

Examples of floating-point literals of various forms:

```
123.0f64;        // type f64
0.1f64;          // type f64
0.1f32;          // type f32
12E+99_f64;      // type f64
let x: f64 = 2.; // type f64
```

This last example is different because it is not possible to use the suffix
syntax with a floating point literal ending in a period. `2.f64` would attempt
to call a method named `f64` on `2`.

The representation semantics of floating-point numbers are described in
["Machine Types"](#machine-types).

