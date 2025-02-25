#pragma once

#include <iostream>
#include <map>
#include <list>  // Change from vector to list

class BitcoinExchange
{
    private:

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(BitcoinExchange const & oth);
        BitcoinExchange & operator=(BitcoinExchange const & rhs);
        std::string valueDate(std::string input, std::map<std::string, double> valueBank);
        std::list<std::pair<std::string, double>> readInput(const std::string& filename); // Change return type to list
        std::map<std::string, double> readData(const std::string& filename);
        void processData(std::list<std::pair<std::string, double>> input, std::map<std::string, double> bank); // Change parameter type to list
};

// $> ./btc
// Error: could not open file.
// $> ./btc input.txt
// 2011-01-03 => 3 = 0.9
// 2011-01-03 => 2 = 0.6
// 2011-01-03 => 1 = 0.3
// 2011-01-03 => 1.2 = 0.36
// 2011-01-09 => 1 = 0.32
// Error: not a positive number.
// Error: bad input => 2001-42-42
// 2012-01-11 => 1 = 7.1
// Error: too large a number.
// $>
// Warning: The container(s) you use to validate this exercise will no
// longer be usable for the rest of this module.
// 7
