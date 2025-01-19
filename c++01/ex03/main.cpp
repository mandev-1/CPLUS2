#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.attack();
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}

// Key points about the implementation:
// 1. `HumanA` uses a reference to `Weapon` because it will always have a weapon.
// 2. `HumanB` uses a pointer to `Weapon` because it might not always have a weapon.
// 3. Both classes can attack using their weapons.
// 4. The `Weapon` class allows changing the weapon type using `setType`.

// When you compile and run this code, it will demonstrate the differences between `HumanA` and `HumanB`,
// showing how they can attack with weapons and how the weapon type can be changed.
