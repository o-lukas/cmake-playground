#include <iostream>
#include <string>

#include "o-lukas/LibraryPlayground/StringUtil.hpp"

namespace o_lukas::ExecutablePlayground {

enum class CaseMode {
  kUpper,
  kLower,
};

void printUsage(const char* program_name) {
  std::cerr << "Usage: " << program_name << " [--upper|--lower] <string>\n";
}

}  // namespace o_lukas::ExecutablePlayground

int main(int argc, char** argv) {
  auto mode = o_lukas::ExecutablePlayground::CaseMode::kLower;
  std::string input;

  for (int i = 1; i < argc; ++i) {
    const std::string argument = argv[i];

    if (argument == "--upper" || argument == "-u") {
      mode = o_lukas::ExecutablePlayground::CaseMode::kUpper;
      continue;
    }

    if (argument == "--lower" || argument == "-l") {
      mode = o_lukas::ExecutablePlayground::CaseMode::kLower;
      continue;
    }

    if (!input.empty()) {
      input += ' ';
    }
    input += argument;
  }

  if (input.empty()) {
    o_lukas::ExecutablePlayground::printUsage(argv[0]);
    return 1;
  }

  const std::string output =
      mode == o_lukas::ExecutablePlayground::CaseMode::kUpper
          ? o_lukas::LibraryPlayground::StringUtil::toUpper(input)
          : o_lukas::LibraryPlayground::StringUtil::toLower(input);

  std::cout << output << '\n';
  return 0;
}
