// This line includes the Zombie class definition from Zombie.hpp file
#include "Zombie.hpp"

// Zombie* - This function returns a pointer (*) to a Zombie object
// std::string name - This is the parameter that takes a string value for the zombie's name
Zombie* newZombie(std::string name)
{
    // new - Creates a new Zombie object on the heap (dynamic memory)
    // return - Sends back the memory address of the new Zombie object
    return new Zombie(name);
}
