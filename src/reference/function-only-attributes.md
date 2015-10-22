% Function-only attributes

### Function-only attributes

- `main` - indicates that this function should be passed to the entry point,
  rather than the function in the crate root named `main`.
- `plugin_registrar` - mark this function as the registration point for
  [compiler plugins][plugin], such as loadable syntax extensions.
- `start` - indicates that this function should be used as the entry point,
  overriding the "start" language item. See the "start" [language
  item](#language-items) for more details.
- `test` - indicates that this function is a test function, to only be compiled
  in case of `--test`.
- `should_panic` - indicates that this test function should panic, inverting the success condition.
- `cold` - The function is unlikely to be executed, so optimize it (and calls
  to it) differently.

