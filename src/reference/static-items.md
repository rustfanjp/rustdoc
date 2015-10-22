% Static items

### Static items

A *static item* is similar to a *constant*, except that it represents a precise
memory location in the program. A static is never "inlined" at the usage site,
and all references to it refer to the same memory location. Static items have
the `static` lifetime, which outlives all other lifetimes in a Rust program.
Static items may be placed in read-only memory if they do not contain any
interior mutability.

Statics may contain interior mutability through the `UnsafeCell` language item.
All access to a static is safe, but there are a number of restrictions on
statics:

* Statics may not contain any destructors.
* The types of static values must ascribe to `Sync` to allow thread-safe access.
* Statics may not refer to other statics by value, only by reference.
* Constants cannot refer to statics.

Constants should in general be preferred over statics, unless large amounts of
data are being stored, or single-address and mutability properties are required.

