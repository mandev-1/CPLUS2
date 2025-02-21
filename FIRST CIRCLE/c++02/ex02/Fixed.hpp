#ifndef FIXED_HPP
#define FIXED_HPP

#pragma once
#include <iostream>

class Fixed
{
    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;

    public:
        // Orthodox Canonical Form requirements
        Fixed(void);
        Fixed(const Fixed& src);
        Fixed& operator=(const Fixed& rhs);
        ~Fixed(void);

        // Additional constructors
        Fixed(int value);
        Fixed(const float value);

        // Comparison operators
        bool operator>(const Fixed& rhs) const;
        bool operator<(const Fixed& rhs) const;
        bool operator>=(const Fixed& rhs) const;
        bool operator<=(const Fixed& rhs) const;
        bool operator==(const Fixed& rhs) const;
        bool operator!=(const Fixed& rhs) const;

        // Arithmetic operators
        Fixed operator+(const Fixed& rhs) const;
        Fixed operator-(const Fixed& rhs) const;
        Fixed operator*(const Fixed& rhs) const;
        Fixed operator/(const Fixed& rhs) const;

        // Increment/Decrement operators
        Fixed& operator++();    // Pre-increment
        Fixed operator++(int);  // Post-increment
        Fixed& operator--();    // Pre-decrement
        Fixed operator--(int);  // Post-decrement

        // Member functions
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

        // Static member functions
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
};

// Overload of << operator to enable stream output of Fixed objects
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
