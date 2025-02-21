#include "Zombie.hpp"

int main(void)
{
    // Creating a zombie on the heap using newZombie
    Zombie* heapZombie = newZombie("Heap Walker");
    heapZombie->announce();

    // Creating a zombie on the stack using randomChump
    randomChump("Stack Crawler");

    // Don't forget to delete heap-allocated zombie
    delete heapZombie;

    return 0;
}