#include "easyfind.hpp"

int main() {
    int vec;
    std::index<int> vec = {1, 2, 3, 4, 5};
    int found = easyfind(vec, 3);
    std::cout << "Found: " << found << std::endl; // Output: Found: 3

    int notFound = easyfind(vec, 10);
    std::cout << "Not Found: " << notFound << std::endl; // Output: Not Found: -1

    return 0;
}