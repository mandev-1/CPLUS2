// Include the Zombie class definition from Zombie.hpp file
// This lets us use the Zombie class in this file
#include "Zombie.hpp"

// This function creates a temporary zombie that automatically gets cleaned up
// It takes a string parameter 'name' that will be the zombie's name
void randomChump(std::string name)
{
    // Create a new Zombie object called 'zombie' on the stack
    // The '(name)' part passes the name to the Zombie constructor
    // This zombie will automatically be destroyed when the function ends
    Zombie zombie(name);

    // Call the announce() method on our zombie
    // This makes the zombie print its name and "BraiiiiiiinnnzzzZ..."
    zombie.announce();
}
