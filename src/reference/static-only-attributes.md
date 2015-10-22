% Static-only attributes

### Static-only attributes

- `thread_local` - on a `static mut`, this signals that the value of this
  static may change depending on the current thread. The exact consequences of
  this are implementation-defined.

