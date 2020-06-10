const plugin = require("tailwindcss/plugin");

module.exports = {
  purge: [],
  theme: {
    extend: {
      height: {
        "1/3": "33vh",
      },
      borderRadius: {
        xl: "1rem",
      },
    },
  },
  variants: {
    margin: ["responsive", "first", "hover", "focus", "last"],
    borderRadius: ["responsive", "first", "hover", "focus", "last", "only"],
  },
  plugins: [
    plugin(function ({ addVariant, e }) {
      addVariant("only", ({ modifySelectors, separator }) => {
        modifySelectors(({ className }) => {
          return `.${e(`only-child${separator}${className}`)}:only-child`;
        });
      });
    }),
  ],
};
