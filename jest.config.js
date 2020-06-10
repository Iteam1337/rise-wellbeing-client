module.exports = {
  verbose: true,
  testPathIgnorePatterns: ["node_modules", "StyleMock.bs.js"],
  moduleNameMapper: {
    "\\.(css|less)$": "<rootDir>/__tests__/StyleMock.bs.js",
  },
};
