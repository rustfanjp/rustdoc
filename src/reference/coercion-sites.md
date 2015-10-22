% Coercion sites

### Coercion sites

A coercion can only occur at certain coercion sites in a program; these are
typically places where the desired type is explicit or can be derived by
propagation from explicit types (without type inference). Possible coercion
sites are:

* `let` statements where an explicit type is given.

   For example, `128` is coerced to have type `i8` in the following:

   ```rust
   let _: i8 = 128;
   ```

* `static` and `const` statements (similar to `let` statements).

* Arguments for function calls

  The value being coerced is the actual parameter, and it is coerced to
  the type of the formal parameter.

  For example, `128` is coerced to have type `i8` in the following:

  ```rust
  fn bar(_: i8) { }

  fn main() {
     bar(128);
  }
  ```

* Instantiations of struct or variant fields

  For example, `128` is coerced to have type `i8` in the following:

  ```rust
  struct Foo { x: i8 }

  fn main() {
      Foo { x: 128 };
  }
  ```

* Function results, either the final line of a block if it is not
  semicolon-terminated or any expression in a `return` statement

  For example, `128` is coerced to have type `i8` in the following:

  ```rust
  fn foo() -> i8 {
      128
  }
  ```

If the expression in one of these coercion sites is a coercion-propagating
expression, then the relevant sub-expressions in that expression are also
coercion sites. Propagation recurses from these new coercion sites.
Propagating expressions and their relevant sub-expressions are:

* Array literals, where the array has type `[U; n]`. Each sub-expression in
the array literal is a coercion site for coercion to type `U`.

* Array literals with repeating syntax, where the array has type `[U; n]`. The
repeated sub-expression is a coercion site for coercion to type `U`.

* Tuples, where a tuple is a coercion site to type `(U_0, U_1, ..., U_n)`.
Each sub-expression is a coercion site to the respective type, e.g. the
zeroth sub-expression is a coercion site to type `U_0`.

* Parenthesised sub-expressions (`(e)`): if the expression has type `U`, then
the sub-expression is a coercion site to `U`.

* Blocks: if a block has type `U`, then the last expression in the block (if
it is not semicolon-terminated) is a coercion site to `U`. This includes
blocks which are part of control flow statements, such as `if`/`else`, if
the block has a known type.

