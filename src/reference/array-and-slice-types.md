% Array, and Slice types

### Array, and Slice types

Rust has two different types for a list of items:

* `[T; N]`, an 'array'
* `&[T]`, a 'slice'

An array has a fixed size, and can be allocated on either the stack or the
heap.

A slice is a 'view' into an array. It doesn't own the data it points
to, it borrows it.

Examples:

```{rust}
// A stack-allocated array
let array: [i32; 3] = [1, 2, 3];

// A heap-allocated array
let vector: Vec<i32> = vec![1, 2, 3];

// A slice into an array
let slice: &[i32] = &vector[..];
```

As you can see, the `vec!` macro allows you to create a `Vec<T>` easily. The
`vec!` macro is also part of the standard library, rather than the language.

All in-bounds elements of arrays and slices are always initialized, and access
to an array or slice is always bounds-checked.

