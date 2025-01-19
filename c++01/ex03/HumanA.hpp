#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA {
private:
    std::string name;
    Weapon& weapon;  // Reference because HumanA will always have a weapon

public:
    HumanA(const std::string& name, Weapon& weapon);
    void attack() const;
};

#endif
