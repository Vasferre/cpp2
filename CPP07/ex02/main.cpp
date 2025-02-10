#include "Array.hpp"

int main()
{

	unsigned size = 4;
	std::string s[] = {"how", "you", "doin'", "?"};

	Array<int> ints(1);
	Array<std::string> strings(size);

	std::cout << std::endl;

	try
	{
		std::cout << "Ints size: " << ints.size() << std::endl;
		std::cout << "ints[10]: " << ints[10] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

	for (unsigned int i = 0; i < ints.size(); i++)
	{
		ints[i] = i;
		strings[i] = s[i];
	}

	std::cout << "Ints: ";
	for (unsigned int i = 0; i < ints.size(); i++)
		std::cout << ints[i] << " ";
	std::cout << std::endl;

	std::cout << "String: ";
	for (unsigned int i = 0; i < strings.size(); i++)
		std::cout << strings[i] << " ";
	std::cout << std::endl;

	std::cout << std::endl;
	Array<int> copy_ints(ints);

	std::cout << "Copy ints: ";
	for (unsigned int i = 0; i < ints.size(); i++)
	{
		std::cout << copy_ints[i];
	}
	std::cout << std::endl;
	std::cout << std::endl;

	Array<std::string> strings2 = strings;
	std::cout << "String assing: ";
	for (unsigned int i = 0; i < strings.size(); i++)
		std::cout << strings[i] << " ";
	std::cout << std::endl;
	std::cout << std::endl;

	return 0;
}