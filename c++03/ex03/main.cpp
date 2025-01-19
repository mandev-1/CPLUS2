#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
    DiamondTrap diamond("Mark");
    diamond.attack("Handsome Jack");
    diamond.takeDamage(64);
    diamond.beRepaired(10);
    diamond.whoAmI();

    return EXIT_FAILURE;
}