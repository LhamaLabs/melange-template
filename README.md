# Melange Template

A simple project template using [Melange](https://github.com/melange-re/melange) with 
[opam](https://opam.ocaml.org/).

## Quick Start

```shell
pnpm run init

# In separate terminals:
pnpm run watch
pnpm run serve
```

### React

React support is provided by
[`reason-react`](https://github.com/reasonml/reason-react/). The entry
point of the sample React app is [`src/ReactApp.re`](src/ReactApp.re).

## Commands

All the build commands are defined in the `scripts` field of `package.json`. This
is completely optional, and other tools like `make` could be used.

You can see all available commands by running `npm run`. There are explanations
on each command in the `scriptsComments` field of the `package.json` file.
Here are a few of the most useful ones:

- `pnpm run init`: set up opam local switch and download OCaml, Melange and
JavaScript dependencies
- `pnpm run install-opam-npm`: install OCaml, Melange and JavaScript dependencies
- `pnpm run watch`: watch for the filesystem and have Melange rebuild on every
change
- `pnpm run serve`: serve the application with a local HTTP server

## JavaScript output

Since Melange compiles source files into JavaScript files, it can be used
for projects on any JavaScript platform - not just the browser.

The template includes two `melange.emit` stanza for two separate apps. This
stanza tells Dune to generate JavaScript files using Melange, and specifies in
which folder the JavaScript files should be placed, by leveraging the `target`
field:
- The React app JavaScript files will be placed in `_build/default/src/output/*`.
- The NodeJS app JavaScript files will be placed in `_build/default/src/node/*`.

So for example, [`src/Hello.ml`](src/Hello.ml) (using OCaml syntax) can be run with
`node`:

```bash
node _build/default/src/node/src/Hello.mjs
```

Similarly, `_build/default/src/output/src/ReactApp.js` can be passed as entry to a bundler
like Webpack:

```bash
webpack --mode production --entry ./_build/default/src/output/src/ReactApp.js
```

## Setup

- [ ] Change the Project Information in [dune-project](./dune-project)
  - [ ] Change name for the Project Name
  - [ ] Change author and mantainer
  - [ ] Change project URLs
  - [ ] Change the package info
- [ ] Change the Project Name in [package.json](./package.json)
