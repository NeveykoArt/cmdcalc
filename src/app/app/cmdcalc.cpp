#include <cxxopts.hpp>
#include <cmdlib/calculator.hpp>
#include <cmdlib/parser.hpp>
#include <iostream>

int main(int argc, char **argv) {
  cxxopts::Options options("cmdcalc", "calculator for cmd");

  try {
    // clang-format off
      options.add_options()
      ("input", "text to parce", cxxopts::value<std::string>());
    // clang-format on

    const auto result = options.parse(argc, argv);
    const auto example = result["input"].as<std::string>();

	auto *table = new struct token[example.size()];
	std::size_t position = 0;
	int table_index = 0;

	parser(example, table, position, table_index);

	checkTable(table, table_index);

	bool incorrect_flag = false;
	double answer = Calculator(table, incorrect_flag, table_index);

	if (incorrect_flag) {
		throw std::runtime_error("Calculation failed. Cannot divide by zero.\n");
	}

	std::cout << "\tAnswer = " << answer << "\n";

  } catch (const std::exception &e) {
    std::cerr << e.what() << "\n";
    return 1;
  }
}
