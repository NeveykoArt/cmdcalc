#include <cxxopts.hpp>
#include <cmdlib/indexer.hpp>
#include <cmdlib/parser.hpp>
#include <cmdlib/searcher.hpp>
#include <iostream>

int main(int argc, char **argv) {
  cxxopts::Options options("cmdcalc", "calculator for cmd");
  if (argc != 2) {
	std::cout << "./exe example\n";
	return -1;
  }
  try {
    // clang-format off
      options.add_options()
      ("input", "text to parce", cxxopts::value<std::string>());
    // clang-format on

    const auto result = options.parse(argc, argv);

    const auto example = result["input"].as<std::string>();

    	struct token* table = calloc(strlen(example), sizeof(struct token));
	std::size_t position = 0;
	int table_index = 0;
	if (!parcer(example, table, position, table_index)) {
		std::cout << "Wrong input at " << position << " position.\n";
		delete[] table;
		return -1;
	}
	if (!checkTable(table, table_index)) {
		std::cout << "Impossible example. Change the input.\n";
		delete[] table;
		return -1;
	}
	bool incorrect_flag = false;
	double answer = Calculator(table, incorrect_flag, table_index);
	if (incorrect_flag) {
		std::cout << "Calculation failed. Cannot divide by zero.\n";
		delete[] table;
		return -1;
	}
	std::cout << "\tAnswer = " << answer << "\n";
	delete[] table;

  } catch (const std::exception &e) {
    std::cerr << e.what() << "\n";
    return 1;
  }
}
