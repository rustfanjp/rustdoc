% FFI attributes

### FFI attributes

On an `extern` block, the following attributes are interpreted:

- `link_args` - specify arguments to the linker, rather than just the library
  name and type. This is feature gated and the exact behavior is
  implementation-defined (due to variety of linker invocation syntax).
- `link` - indicate that a native library should be linked to for the
  declarations in this block to be linked correctly. `link` supports an optional `kind`
  key with three possible values: `dylib`, `static`, and `framework`. See [external blocks](#external-blocks) for more about external blocks. Two
  examples: `#[link(name = "readline")]` and
  `#[link(name = "CoreFoundation", kind = "framework")]`.

On declarations inside an `extern` block, the following attributes are
interpreted:

- `link_name` - the name of the symbol that this function or static should be
  imported as.
- `linkage` - on a static, this specifies the [linkage
  type](http://llvm.org/docs/LangRef.html#linkage-types).

On `enum`s:

- `repr` - on C-like enums, this sets the underlying type used for
  representation. Takes one argument, which is the primitive
  type this enum should be represented for, or `C`, which specifies that it
  should be the default `enum` size of the C ABI for that platform. Note that
  enum representation in C is undefined, and this may be incorrect when the C
  code is compiled with certain flags.

On `struct`s:

- `repr` - specifies the representation to use for this struct. Takes a list
  of options. The currently accepted ones are `C` and `packed`, which may be
  combined. `C` will use a C ABI compatible struct layout, and `packed` will
  remove any padding between fields (note that this is very fragile and may
  break platforms which require aligned access).

