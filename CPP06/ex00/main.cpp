#include "ScalarConverter.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cout << "./convert <parameter>" << std::endl;
		return 1;
	}

	ScalarConverter::convert(argv[1]);

	return 0;
}