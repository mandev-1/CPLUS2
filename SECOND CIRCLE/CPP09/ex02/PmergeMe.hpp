#pragma once
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

class PmergeMe
{
    private:
        std::vector<int> vec;
        std::deque<int> deq;

        template<typename T>
        void fordJohnsonSort(T& container);

        template<typename T>
        void insertElement(T& container, size_t start, size_t end, typename T::value_type value);

        std::vector<size_t> generateJacobsthalNumbers(size_t n);

    public:
        PmergeMe(int argc, char** argv);
        ~PmergeMe() {}

        void execute();
        void displayResults(double timeVec, double timeDeq);
        bool validateInput(const std::string& input);
};