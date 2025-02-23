#include "whatever.hpp"

int main( void )
{
    int a = 2;
    int b = 3;

    ::swap( a, b );

    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    return 0;
}

// Code above should output:
// a = 3, b = 2
// min(a, b) = 2
// max(a, b) = 3
// c = chaine2, d = chaine1
// min(c, d) = chaine1
// max(c, d) = chaine2
// 6
// Thus--> We will define
// 1) swap
// 2) min
// 3) max

// But how? Well to be able to call it like this, we will define them as a "Global Template functions"
// 
//
// template<typename T>
// void swap(T &a, T &b)
// {
//     T tmp = a;
//     a = b;
//     b = tmp;
// }

// template<typename T>
// const T& min(const T &a, const T &b)
// {
//     return (b < a) ? b : a;
// }

// template<typename T>
// const T& max(const T &a, const T &b)
// {
//     return (a < b) ? b : a;
// }