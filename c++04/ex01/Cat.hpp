#ifndef CAT_HPP
#define CAT_HPP

#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat& other);      // Copy constructor -- called when "new" used
        Cat& operator=(const Cat& other); // Assignment operator
        ~Cat();
        void makeSound() const;
};


// // // Copy Constructor
// A copy constructor is a special constructor in C++ used to create
//  a new object as a copy of an existing object. It is called when:

// A new object is created from an existing object, as in Cat cat2(cat1);
// An object is passed by value to a function
// An object is returned by value from a function
// In your Cat class, the copy constructor is declared as:

// This constructor takes a reference to another Cat object and initializes
//  the new object with the state of the existing object.

// // // // // // // 

// // // Assignment Operator
// The assignment operator is used to copy the contents of one existing object to 
// another existing object of the same type. It is called when:

// An already initialized object is assigned a new value from another existing object, 
// as in cat2 = cat1;
// In your Cat class, the assignment operator is declared as:

// This operator takes a reference to another Cat object and assigns its state to the 
// current object, returning a reference to the current object.

// Why Use Them?
// Copy Constructor: Ensures that when a new object is created as a copy of an existing object,
//  all necessary resources (like dynamic memory) are properly duplicated.
// Assignment Operator: Ensures that when one object is assigned to another, all necessary
//  resources are properly copied and any existing resources in the target object are properly
//   cleaned up to avoid memory leaks.
// Example
// Here is a simple example to illustrate their usage:

// Implementation
// You would typically implement these in your .cpp file to handle deep copying if your class
//  manages resources like dynamic memory. Here is a basic example:

// This ensures that your Cat objects are properly copied and assigned, maintaining 
// the integrity of any resources they manage.


#endif