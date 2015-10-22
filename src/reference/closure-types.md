% Closure types

### Closure types

A [lambda expression](#lambda-expressions) produces a closure value with
a unique, anonymous type that cannot be written out.

Depending on the requirements of the closure, its type implements one or
more of the closure traits:

* `FnOnce`
  : The closure can be called once. A closure called as `FnOnce`
    can move out values from its environment.

* `FnMut`
  : The closure can be called multiple times as mutable. A closure called as
    `FnMut` can mutate values from its environment. `FnMut` inherits from
    `FnOnce` (i.e. anything implementing `FnMut` also implements `FnOnce`).

* `Fn`
  : The closure can be called multiple times through a shared reference.
    A closure called as `Fn` can neither move out from nor mutate values
    from its environment. `Fn` inherits from `FnMut`, which itself
    inherits from `FnOnce`.


