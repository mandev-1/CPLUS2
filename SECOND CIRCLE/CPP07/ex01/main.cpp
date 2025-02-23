#include <iostream>
#include <string>

#include "iter.hpp"

void printChar(const char &c)
{
    std::cout << c;
}

int main()
{
    int arrInt[] = {42, -7, 0, 999, -42, 21};
    size_t lenInt = sizeof(arrInt) / sizeof(arrInt[0]);
    std::cout << "\033[1;31mTesting integers:\033[0m ";
    iter(arrInt, lenInt, printElement<int>);
    std::cout << std::endl;

    std::string arrStr[] = {"kalousek je pimp", "Develop a class template Array that contains elements of type T and that implements the following behavior and functions:", "cat", "dog"};
    size_t lenStr = sizeof(arrStr) / sizeof(arrStr[0]);
    std::cout << "\033[1;32mTesting strings:\033[0m ";
    iter(arrStr, lenStr, printElement<std::string>);
    std::cout << std::endl;

    char arrChar[] = {'x', 'l', 'c', 'x', 'p', '8'};
    size_t lenChar = sizeof(arrChar) - 1;
    std::cout << "\033[1;33mTesting chars:\033[0m ";
    iter(arrChar, lenChar, printChar);
    std::cout << std::endl;
    std::cout << lenChar << std::endl;


    double arrDouble[] = {3.14, 2.718, 1.414, 1.732, 2.236};
    size_t lenDouble = sizeof(arrDouble) / sizeof(arrDouble[0]);
    std::cout << "\033[1;34mTesting doubles:\033[0m ";
    iter(arrDouble, lenDouble, printElement<double>);
    std::cout << std::endl;

    float arrFloat[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    size_t lenFloat = sizeof(arrFloat) / sizeof(arrFloat[0]);
    std::cout << "\033[1;35mTesting floats:\033[0m ";
    iter(arrFloat, lenFloat, printElement<float>);
    std::cout << std::endl;

    return 0;
}