#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

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
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    
    return 0;
}