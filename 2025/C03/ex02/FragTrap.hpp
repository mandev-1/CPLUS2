#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#pragma once

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap
{
public:
    FragTrap(std::string name);
    ~FragTrap();
    void highFivesGuys(void);


private:

};

#endif // FRAGTRAP_HPP