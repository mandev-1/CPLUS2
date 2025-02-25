#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        if (!validateInput(argv[i])) {
            throw std::invalid_argument("Invalid input: " + std::string(argv[i]));
        }
        int num = std::atoi(argv[i]);
        vec.push_back(num);
        deq.push_back(num);
    }
}

bool PmergeMe::validateInput(const std::string& input) {
    if (input.empty()) return false;
    for (size_t i = 0; i < input.length(); ++i) {
        if (!std::isdigit(input[i])) return false;
    }
    return true;
}

/**
 * @brief Generates a sequence of Jacobsthal numbers up to a given limit
 * 
 * The Jacobsthal sequence is defined as:
 * J(0) = 0
 * J(1) = 1
 * J(n) = J(n-1) + 2*J(n-2) for n > 1
 * 
 * @param n The upper limit for generating Jacobsthal numbers
 * @return std::vector<size_t> Vector containing the Jacobsthal sequence up to n
 *
 * @note The sequence will stop when the next Jacobsthal number would exceed n
 * @note Returns empty vector if n = 0
 */
std::vector<size_t> PmergeMe::generateJacobsthalNumbers(size_t n) {
    std::vector<size_t> jacobsthal;
    if (n == 0) return jacobsthal;
    jacobsthal.push_back(0);
    if (n == 1) return jacobsthal;
    jacobsthal.push_back(1);
    size_t i = 2;
    while (jacobsthal.back() < n) {
        size_t next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
        if (next > n) break;
        jacobsthal.push_back(next);
        ++i;
    }
    return jacobsthal;
}

/**
 * @brief Inserts an element into a sorted container using binary search
 * 
 * @tparam T Container type that supports random access (e.g., vector, deque)
 * @param container The sorted container to insert into
 * @param start Starting index for binary search
 * @param end Ending index for binary search
 * @param value Value to be inserted
 * 
 * @details Uses binary search (bispacial) to find the correct position (and half) to insert the value
 * while maintaining the sorted order of the container. The container must be
 * sorted before calling this function. The insertion is performed at the found
 * position using container's insert method.
 */
template<typename T>
void PmergeMe::insertElement(T& container, size_t start, size_t end,
                           typename T::value_type value) {
    while (start < end) {
        size_t mid = start + (end - start) / 2;
        if (container[mid] > value)
            end = mid;
        else
            start = mid + 1;
    }
    container.insert(container.begin() + start, value);
}

/**
 * @brief Performs Ford-Johnson (merge-insertion) sorting algorithm on a container
 * 
 * This algorithm works by:
 * 1. Pairing elements and creating a main chain of larger elements and pending chain of smaller elements
 * 2. Sorting the main chain
 * 3. Inserting elements from pending chain using Jacobsthal numbers for optimal insertion sequence
 * 
 * @tparam T Container type that supports random access (e.g., vector, deque)
 * @param container Reference to container to be sorted
 * 
 * The algorithm has the following steps:
 * - Pairs elements and separates them into main_chain (larger elements) and pending (smaller elements)
 * - Handles odd-sized input by storing the unpaired element
 * - Sorts the main chain
 * - Generates Jacobsthal numbers for optimal insertion sequence
 * - Inserts pending elements into the sorted main chain using binary insertion
 * - Finally inserts the unpaired element (if exists)
 * 
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */
template<typename T>
void PmergeMe::fordJohnsonSort(T& container) {
    if (container.size() <= 1) return;
    T main_chain;
    T pending;
    size_t unpaired = container.size() % 2;
    typename T::value_type unpaired_element;
    for (size_t i = 0; i < container.size() - unpaired; i += 2) {
        if (container[i] > container[i + 1]) {
            main_chain.push_back(container[i]);
            pending.push_back(container[i + 1]);
        } else {
            main_chain.push_back(container[i + 1]);
            pending.push_back(container[i]);
        }
    }
    if (unpaired) {
        unpaired_element = container.back();
    }
    std::sort(main_chain.begin(), main_chain.end());
    container.clear();
    container = main_chain;
    std::vector<size_t> jacobsthal = generateJacobsthalNumbers(pending.size());
    if (!pending.empty()) {
        insertElement(container, 0, container.size(), pending[0]);
    }
    for (size_t i = 1; i < jacobsthal.size(); ++i) {
        size_t start = jacobsthal[i - 1];
        size_t end = jacobsthal[i];
        for (size_t j = end; j > start; --j) {
            if (j - 1 < pending.size()) {
                insertElement(container, 0, container.size(), pending[j - 1]);
            }
        }
    }
    for (size_t i = jacobsthal.back() + 1; i <= pending.size(); ++i) {
        insertElement(container, 0, container.size(), pending[i - 1]);
    }
    if (unpaired) {
        insertElement(container, 0, container.size(), unpaired_element);
    }
}

void PmergeMe::execute() {
    std::cout << "Before: ";
    for (const auto& num : vec) std::cout << num << " ";
    std::cout << std::endl;
    clock_t start = clock();
    fordJohnsonSort(vec);
    clock_t end = clock();
    double timeVec = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    start = clock();
    fordJohnsonSort(deq);
    end = clock();
    double timeDeq = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    displayResults(timeVec, timeDeq);
}

void PmergeMe::displayResults(double timeVec, double timeDeq) {
    std::cout << "After: ";
    for (const auto& num : vec) std::cout << num << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : " << std::fixed
              << std::setprecision(5) << timeVec << " ms" << std::endl;
    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque : " << std::fixed
              << std::setprecision(5) << timeDeq << " ms" << std::endl;
}
