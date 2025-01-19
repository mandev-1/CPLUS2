#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap bro("Bro");
    bro.attack("Handsome Jack");
    bro.takeDamage(5);
    bro.beRepaired(5);
    std::cout << bro.name << " is ready to fight again!" << std::endl;

    return EXIT_FAILURE;
}