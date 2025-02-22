#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>

class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(ScalarConverter const & other);
        ScalarConverter & operator=(ScalarConverter const & rhs);

    public:
        static void Convert(const std::string& literal);
};
