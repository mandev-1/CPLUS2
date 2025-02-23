#include "Array.hpp"
#include <iostream>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

    	int	i;
	Array<int>	intArray0;
	Array<int>	intArray(5);

	i = 0;
	while (i < 5)
	{
		intArray[i] = i;
		i++;
	};
	intArray0 = intArray;
	std::cout << intArray0[1] << std::endl;
	Array<int>	temp = intArray0;
	std::cout << intArray0[2] << std::endl;
	try
	{
		intArray0[-2] = 0;
	}

	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    
    std::cout << "\033[1;36m=== Additional Template Tests ===\033[0m\n";

    Array<char> charArray(4);
    charArray[0] = 'C'; charArray[1] = 'P'; charArray[2] = 'P'; charArray[3] = '!';
    std::cout << "\033[1;32mChar Array: \033[0m";
    for (unsigned int i = 0; i < charArray.size(); i++)
        std::cout << charArray[i];
    std::cout << std::endl;
    Array<double> doubleArray(3);
    doubleArray[0] = 3.14; doubleArray[1] = 2.718; doubleArray[2] = 1.414;
    std::cout << "\033[1;33mDouble Array: \033[0m";
    for (unsigned int i = 0; i < doubleArray.size(); i++)
        std::cout << doubleArray[i] << " ";
    std::cout << std::endl;
    Array<double> doubleCopy(doubleArray);
    std::cout << "\033[1;34mCopied Double Array: \033[0m";
    for (unsigned int i = 0; i < doubleCopy.size(); i++)
        std::cout << doubleCopy[i] << " ";
    std::cout << std::endl;
    Array<std::string> emptyArray;
    std::cout << "\033[1;35mEmpty Array size: \033[0m" << emptyArray.size() << std::endl;
    std::cout << "\033[1;31mTesting out of bounds access:\033[0m\n";
    try {
        doubleArray[99] = 42.0;
    } catch (const std::exception& e) {
        std::cout << "Error caught: " << e.what() << std::endl;
    }

    return EXIT_SUCCESS;

}