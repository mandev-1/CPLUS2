#ifndef FIXED_HPP
#define FIXED_HPP

#pragma once
#include <iostream>

/**
 * @brief Fixed point number class implementation
 *
 * In C++, unlike C, function overloading allows multiple functions (or constructors)
 * to have the same name but different parameter lists. This is called "function overloading".
 * The compiler distinguishes between them based on:
 * - Number of parameters
 * - Types of parameters
 * - Order of parameters
 *
 * In this class, we have multiple constructors:
 * - Default constructor: Fixed()
 * - Copy constructor: Fixed(const Fixed&)
 * - Int constructor: Fixed(const int)
 * - Float constructor: Fixed(const float)
 *
 * The compiler automatically determines which constructor to call based on the argument type
 * when creating a new Fixed object. For example:
 * Fixed a;          // Calls default constructor
 * Fixed b(42);      // Calls int constructor
 * Fixed c(42.42f);  // Calls float constructor
 * Fixed d(b);       // Calls copy constructor
 *
 * This feature is part of C++'s polymorphism and type safety system, making the code
 * more flexible and intuitive to use while maintaining type safety.
 */

class Fixed
{
    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;

    public:
        // Orthodox Canonical Form requirements
        Fixed(void);                         // Default constructor
        Fixed(const Fixed& src);             // Copy constructor
        Fixed& operator=(const Fixed& rhs);  // Copy assignment operator
        ~Fixed(void);                        // Destructor

        // Additional constructors
        Fixed(int value);                    // Int constructor
        Fixed(const float value);            // Float constructor

        // Member functions
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

// Stream operator overload
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
