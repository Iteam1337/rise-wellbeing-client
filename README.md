# Digital Plattform

## Run Project

```sh
npm install
npm run build:styles
npm start # compiles .re-files to .js
# in another tab
npm run server
```

View the app in the browser at http://localhost:8000. Running in this environment provides hot reloading and support for routing; just edit and save the file and the browser will automatically refresh.

To use a port other than 8000 set the `PORT` environment variable (`PORT=8080 npm run server`).

## Build for Production

```sh
npm run clean
npm run build:styles
npm run build
npm run webpack:production
```

This will replace the development artifact `build/Index.js` for an optimized version as well as copy `src/index.html` into `build/`. You can then deploy the contents of the `build` directory (`index.html` and `Index.js`).

**To enable dead code elimination**, change `bsconfig.json`'s `package-specs` `module` from `"commonjs"` to `"es6"`. Then re-run the above 2 commands. This will allow Webpack to remove unused code.

## Developing

### VSCode

1. Install the [OCaml Platform VSCode extension](https://marketplace.visualstudio.com/items?itemName=ocamllabs.ocaml-platform)

2. Install [esy](httpds://esy.sh)

```sh
npm install -g esy@latest
```

3. Run esy

```sh
esy
```
