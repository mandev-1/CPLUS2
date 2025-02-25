#include "BitcoinExchange.hpp"
#include <iostream>

// as input put the name of file
// the input file should be .txt
//
// content example row:
// 2011-01-03 | 3
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    
    BitcoinExchange btc;
    std::list<std::pair<std::string, double>> input = btc.readInput(argv[1]);
    std::map<std::string, double> bank = btc.readData("data.csv");
    btc.processData(input, bank);

    return EXIT_SUCCESS;
}
// The program uses data.csv for reference

// The program will take as input a second database, storing the different prices/dates
// to evaluate.

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
// $