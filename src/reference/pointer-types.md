% Pointer types

### Pointer types

All pointers in Rust are explicit first-class values. They can be copied,
stored into data structures, and returned from functions. There are two
varieties of pointer in Rust:

* References (`&`)
  : These point to memory _owned by some other value_.
    A reference type is written `&type`,
    or `&'a type` when you need to specify an explicit lifetime.
    Copying a reference is a "shallow" operation:
    it involves only copying the pointer itself.
    Releasing a reference has no effect on the value it points to,
    but a reference of a temporary value will keep it alive during the scope
    of the reference itself.

* Raw pointers (`*`)
  : Raw pointers are pointers without safety or liveness guarantees.
    Raw pointers are written as `*const T` or `*mut T`,
    for example `*const i32` means a raw pointer to a 32-bit integer.
    Copying or dropping a raw pointer has no effect on the lifecycle of any
    other value. Dereferencing a raw pointer or converting it to any other
    pointer type is an [`unsafe` operation](#unsafe-functions).
    Raw pointers are generally discouraged in Rust code;
    they exist to support interoperability with foreign code,
    and writing performance-critical or low-level functions.

The standard library contains additional 'smart pointer' types beyond references
and raw pointers.

