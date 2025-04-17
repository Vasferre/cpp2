#include "easyfind.hpp"
#include <vector>
#include <list>


//inicia os containers e percorre
int main(void)
{


	std::vector<int> intVector;
	std::list<int> intList;

	for (int i = 0; i <= 40; i++) {
		intVector.push_back(i);
		intList.push_back(i);
	}
	std::cout << "Vector:" << std::endl;
    std::cout << "[0...40] -> 12: " << easyfind(intVector, 12) << std::endl;
    std::cout << "[0...40] -> 40: " << easyfind(intVector, 40) << std::endl;
	std::cout << "[0...40] -> 50: " << easyfind(intVector, 50) << std::endl;

	std::cout << "List: " << std::endl;
    std::cout << "[0...40] -> 12: " << easyfind(intList, 12) << std::endl;
    std::cout << "[0...40] -> 40: " << easyfind(intList, 40) << std::endl;
	std::cout << "[0...40] -> 50: " << easyfind(intList, 50) << std::endl;

	return 0;
}
