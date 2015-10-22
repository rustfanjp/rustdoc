% Machine-dependent integer types

#### Machine-dependent integer types

The `usize` type is an unsigned integer type with the same number of bits as the
platform's pointer type. It can represent every memory address in the process.

The `isize` type is a signed integer type with the same number of bits as the
platform's pointer type. The theoretical upper bound on object and array size
is the maximum `isize` value. This ensures that `isize` can be used to calculate
differences between pointers into an object or array and can address every byte
within an object along with one byte past the end.

