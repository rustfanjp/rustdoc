% Constant items

### Constant items

A *constant item* is a named _constant value_ which is not associated with a
specific memory location in the program. Constants are essentially inlined
wherever they are used, meaning that they are copied directly into the relevant
context when used. References to the same constant are not necessarily
guaranteed to refer to the same memory address.

Constant values must not have destructors, and otherwise permit most forms of
data. Constants may refer to the address of other constants, in which case the
address will have the `static` lifetime. The compiler is, however, still at
liberty to translate the constant many times, so the address referred to may not
be stable.

Constants must be explicitly typed. The type may be `bool`, `char`, a number, or
a type derived from those primitive types. The derived types are references with
the `static` lifetime, fixed-size arrays, tuples, enum variants, and structs.

```
const BIT1: u32 = 1 << 0;
const BIT2: u32 = 1 << 1;

const BITS: [u32; 2] = [BIT1, BIT2];
const STRING: &'static str = "bitstring";

struct BitsNStrings<'a> {
    mybits: [u32; 2],
    mystring: &'a str
}

const BITS_N_STRINGS: BitsNStrings<'static> = BitsNStrings {
    mybits: BITS,
    mystring: STRING
};
```

