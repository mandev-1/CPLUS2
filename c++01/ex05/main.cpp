#include "Harl.hpp"
#include <iostream>

int main()
{
    Harl harl;

    std::cout << "Testing all Harl's complaint levels:" << std::endl;
    std::cout << "--------------------------------" << std::endl;

    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");

    std::cout << "Testing invalid level:" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    harl.complain("INVALID");

    return 0;
}
