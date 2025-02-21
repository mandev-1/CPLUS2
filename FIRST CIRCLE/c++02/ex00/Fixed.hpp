#ifndef FIXED_HPP
#define FIXED_HPP

#pragma once

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

        // Member functions
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif