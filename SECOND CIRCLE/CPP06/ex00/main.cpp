// C++ code
#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

int main(int argc, char** argv)
{
    // An array of test literals, including cases beyond int limits and -0
    std::string tests[] = {
        "a",              // char case: single character
        "42",             // int case
        "42.0f",          // float case (with f-designator)
        "42.0",           // double case
        "nan",            // pseudo literal (double)
        "-inff",          // pseudo literal (float)
        "+inf",           // pseudo literal (double)
        "0",              // int zero
        "-0",             // negative zero
        "2147483648",     // over int_max case
        "-2147483649",    // under int_min case
        "non convertible" // invalid input example
    };

    size_t numTests = sizeof(tests) / sizeof(tests[0]);
    for (size_t i = 0; i < numTests; i++)
    {
        std::cout << CYAN << "\nTesting literal: \"" << tests[i] << "\"" << RESET << std::endl;
        ScalarConverter::Convert(tests[i]);
        std::cout << YELLOW << "---------------------------------------" << RESET << std::endl;
    }

    // Alternatively, if command line arguments are provided, convert them
    if (argc > 1)
    {
        std::cout << GREEN << "\n--- Testing command line input ---" << RESET << std::endl;
        for (int i = 1; i < argc; i++)
        {
            std::cout << CYAN << "\nTesting literal: \"" << argv[i] << "\"" << RESET << std::endl;
            ScalarConverter::Convert(argv[i]);
            std::cout << YELLOW << "---------------------------------------" << RESET << std::endl;
        }
    }

    return 0;
}