#include <map>
#include <fstream>
#include <iostream>
#include <limits>
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(BitcoinExchange const & oth)
{
    *this = oth;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
    if (this != &rhs)
    {

    }
    return *this;
}

// As input, takes in the DATE | COINS (in format YYYY-MM-DD | COINS)
// Outputs the entire printable line (YYYY-MM--DD => COINS = VALUE)
//
// (e.g.: 2011-01-03 => 1.2 = 0.36)
std::string BitcoinExchange::valueDate(std::string input, std::map<std::string, double> valueBank)
{
    size_t pipePos = input.find('|');
    if (pipePos == std::string::npos)
        return "Error: bad input => " + input;
    
    std::string date = input.substr(0, pipePos - 1);
    // Check date format: YYYY-MM-DD
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return "Error: bad input => " + input;

    // Check if all other characters are digits
    for (size_t i = 0; i < date.length(); i++) {
        if (i != 4 && i != 7 && !isdigit(date[i]))
            return "Error: bad input => " + input;
    }

    // Extract year, month, day
    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));

    // Validate ranges
    if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
        return "Error: bad input => " + input;
    double coins;
    
    try { coins = std::stod(input.substr(pipePos + 1)); }
    catch (...) { return "Error: invalid value."; }
    
    if (coins < 0) return "Error: not a positive number.";
    if (coins > 1000) return "Error: too large a number.";
    
    std::map<std::string, double>::iterator it = valueBank.lower_bound(date);
    if (it != valueBank.begin() && it->first != date)
        --it;
    
    if (it == valueBank.end())
        return "Error: no data available.";
    
    double value = coins * it->second;
    std::string result = date + " => " + std::to_string(coins) + " = " + std::to_string(value);
    
    // Remove trailing zeros and decimal point if necessary
    size_t lastNonZero = result.find_last_not_of('0');
    if (lastNonZero != std::string::npos && result[lastNonZero] == '.')
        result.erase(lastNonZero);
    else if (lastNonZero != std::string::npos)
        result.erase(lastNonZero + 1);
    
    return result;
}



// processes .txt files
// processes .csv files
//
// takes in either: 2011-01-03 | 3      (for .txt files)
//              or: 2009-01-14,0        (for .csv files)
std::map<std::string, double> BitcoinExchange::readData(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Could not open file: " + filename);
    std::map<std::string, double> data;
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        size_t separator = line.find(',');
        if (separator == std::string::npos)
            separator = line.find('|');
        if (separator != std::string::npos) {
            std::string date = line.substr(0, separator);
            double value = std::stod(line.substr(separator + 1));
            if (!date.empty())
                data[date] = value;
        }
    }
    
    return data;
}

std::vector<std::pair<std::string, double>> BitcoinExchange::readInput(const std::string& filename) 
{
    std::vector<std::pair<std::string, double>> result;
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file: " + filename);
    }
    std::string line;
    while (std::getline(file, line)) 
    {
        size_t pipePos = line.find('|');
        if (pipePos != std::string::npos) 
        {
            std::string date = line.substr(0, pipePos - 1);
            try 
            {
                double value = std::stod(line.substr(pipePos + 1));
                result.push_back(std::make_pair(date, value));
            } 
            catch (...) 
            {
                result.push_back(std::make_pair(line, 0.0));
            }
        } 
        else 
        {
            result.push_back(std::make_pair(line, 0.0));
        }
    }
    return result;
}

void BitcoinExchange::processData(std::vector<std::pair<std::string, double>> input, 
                                std::map<std::string, double> bank)
{
    for (size_t i = 0; i < input.size(); i++) {
        std::string result = valueDate(input[i].first + " | " + 
                                     std::to_string(input[i].second), bank);
        std::cout << result << std::endl;
    }
}