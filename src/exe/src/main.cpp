#include <CLI/CLI.hpp>
#include <iostream>
#include <string>

#include "o-lukas/LibraryPlayground/StringUtil.hpp"

int main(int argc, char** argv) {
  std::string input;

  CLI::App app{"Convert input text to upper or lower case."};

  bool upper = false;
  bool lower = false;

  app.add_flag("-u, --upper", upper, "Convert input to upper case")
      ->excludes("-l, --lower");
  app.add_flag("-l, --lower", lower, "Convert input to lower case")
      ->excludes("-u, --upper");
  app.add_option("input", input, "Input string to transform")->required();

  try {
    app.parse(argc, argv);
  } catch (const CLI::ParseError& e) {
    return app.exit(e);
  }

  std::string output = input;
  if (upper) {
    output = o_lukas::LibraryPlayground::StringUtil::toUpper(input);
  } else if (lower) {
    output = o_lukas::LibraryPlayground::StringUtil::toLower(input);
  }

  std::cout << output << '\n';
  return 0;
}
