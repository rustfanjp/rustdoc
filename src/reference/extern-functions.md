% Extern functions

#### Extern functions

Extern functions are part of Rust's foreign function interface, providing the
opposite functionality to [external blocks](#external-blocks). Whereas
external blocks allow Rust code to call foreign code, extern functions with
bodies defined in Rust code _can be called by foreign code_. They are defined
in the same way as any other Rust function, except that they have the `extern`
modifier.

```
// Declares an extern fn, the ABI defaults to "C"
extern fn new_i32() -> i32 { 0 }

// Declares an extern fn with "stdcall" ABI
extern "stdcall" fn new_i32_stdcall() -> i32 { 0 }
```

Unlike normal functions, extern fns have type `extern "ABI" fn()`. This is the
same type as the functions declared in an extern block.

```
# extern fn new_i32() -> i32 { 0 }
let fptr: extern "C" fn() -> i32 = new_i32;
```

Extern functions may be called directly from Rust code as Rust uses large,
contiguous stack segments like C.

