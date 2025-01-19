#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
    ClapTrap bro("Bro");
    bro.attack("Handsome Jack");
    bro.takeDamage(5);
    bro.beRepaired(5);
    std::cout << bro.name << " is ready to fight again!" << std::endl;

    ScavTrap scav("Scav");
    scav.guardGate();
    scav.attack("Handsome Jack");
    scav.takeDamage(64);
    std::cout << scav.name << ": I have " << scav.hitPoints << "HP" << std::endl;
    scav.beRepaired(10);
    std::cout << scav.name << ": I have " << scav.hitPoints << "HP" << std::endl;

    return EXIT_FAILURE;
}