#include "A_Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define ARRAY_SIZE 10

int main_old(void)
{
    Cat mark;
    Dog martin;
    mark.makeSound();
    martin.makeSound();

    std::cout << "Btw, the type is protected, so we can not access it in main rn." << std::endl;
    return EXIT_SUCCESS;
}

int main()
{
    A_Animal* animals[ARRAY_SIZE];
    for (size_t i = 0; i < ARRAY_SIZE; i++)
        {
            if (i < ARRAY_SIZE / 2)
                animals[i] = new Cat();
            else
                animals[i] = new Dog();
        }

        /* delete all animals */
        for (size_t i = 0; i < ARRAY_SIZE; i++)
        {
            delete animals[i];
        }

        Dog basic;
        Dog tmp = basic;  /* Make a copy */

        Cat cat;
        Cat cat2(cat);  /* Make a copy */


    return 0;
}
