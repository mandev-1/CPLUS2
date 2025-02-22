#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>

class Serializer
{
public:
    struct Data
    {
        int i;
    };

private:
    Serializer();
    ~Serializer();
    Serializer(Serializer const & other);
    Serializer & operator=(Serializer const & rhs);

public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif // SERIALIZER_HPP