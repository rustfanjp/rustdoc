% Self types

### Self types

The special type `Self` has a meaning within traits and impls. In a trait definition, it refers
to an implicit type parameter representing the "implementing" type. In an impl,
it is an alias for the implementing type. For example, in:

```
trait Printable {
  fn make_string(&self) -> String;
}

impl Printable for String {
    fn make_string(&self) -> String {
        (*self).clone()
    }
}
```

The notation `&self` is a shorthand for `self: &Self`. In this case,
in the impl, `Self` refers to the value of type `String` that is the
receiver for a call to the method `make_string`.

