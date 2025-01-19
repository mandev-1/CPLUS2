#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
    ClapTrap bro("Bro");
    FragTrap frag("Fry");
    ScavTrap scav("Scav");
    bro.attack("Handsome Jack");
    frag.attack("Handsome Jack");
    scav.attack("Handsome Jack");
    frag.takeDamage(64);
    bro.takeDamage(5);
    bro.beRepaired(5);
    std::cout << bro.name << " is ready to fight again!" << std::endl;

    scav.guardGate();
    scav.attack("Handsome Jack");
    scav.takeDamage(64);
    std::cout << scav.name << ": I have " << scav.hitPoints << "HP" << std::endl;
    scav.beRepaired(10);
    std::cout << scav.name << ": I have " << scav.hitPoints << "HP" << std::endl;

    std::cout << std::endl;
    frag.highFivesGuys();

    return EXIT_FAILURE;
}