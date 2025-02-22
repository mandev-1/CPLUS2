#include <iostream>
#include "Serializer.hpp"

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"

void testStackObject()
{
    std::cout << YELLOW << "Test 1: Stack allocation" << RESET << std::endl;
    Serializer::Data data;
    data.i = 42;
    std::cout << "Original data's address: " << &data << ", data.i: " << data.i << std::endl;
    uintptr_t raw = Serializer::serialize(&data);
    Serializer::Data* newData = Serializer::deserialize(raw);
    if (newData == &data)
        std::cout << GREEN << "Success: Serialization/deserialization works for stack object." << RESET << std::endl;
    else
        std::cout << RED << "Error: mismatched pointer for stack object." << RESET << std::endl;
}

void testHeapObject()
{
    std::cout << YELLOW << "Test 2: Heap allocation" << RESET << std::endl;
    Serializer::Data* data = new Serializer::Data;
    data->i = 84;
    std::cout << "Original data's address: " << data << ", data.i: " << data->i << std::endl;
    uintptr_t raw = Serializer::serialize(data);
    Serializer::Data* newData = Serializer::deserialize(raw);
    if (newData == data)
        std::cout << GREEN << "Success: Serialization/deserialization works for heap object." << RESET << std::endl;
    else
        std::cout << RED << "Error: mismatched pointer for heap object." << RESET << std::endl;
    delete data;
}

void testMultipleSerializations()
{
    std::cout << YELLOW << "Test 3: Multiple serializations" << RESET << std::endl;
    Serializer::Data data1, data2;
    data1.i = 21;
    data2.i = 63;
    
    uintptr_t raw1 = Serializer::serialize(&data1);
    uintptr_t raw2 = Serializer::serialize(&data2);
    
    Serializer::Data* newData1 = Serializer::deserialize(raw1);
    Serializer::Data* newData2 = Serializer::deserialize(raw2);
    
    std::cout << "data1 address: " << &data1 << " serialized: " << raw1 << std::endl;
    std::cout << "data2 address: " << &data2 << " serialized: " << raw2 << std::endl;
    
    if (newData1 == &data1 && newData2 == &data2)
        std::cout << GREEN << "Success: Multiple serializations/deserializations correct." << RESET << std::endl;
    else
        std::cout << RED << "Error: Problem in multiple serializations/deserializations." << RESET << std::endl;
}

int main()
{
    std::cout << "Starting Serialization tests..." << std::endl << std::endl;
    
    testStackObject();
    std::cout << std::endl;
    
    testHeapObject();
    std::cout << std::endl;
    
    testMultipleSerializations();
    std::cout << std::endl;
    
    std::cout << "All tests completed." << std::endl;
    return 0;
}