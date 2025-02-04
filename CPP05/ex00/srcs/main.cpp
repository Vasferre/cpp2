#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat andre("Andre", 15);
	std::cout << andre << std::endl;

	std::cout << std::endl;
	Bureaucrat xavier("Xavier", 151);
	Bureaucrat xavier2("Xavier2", 0);

	std::cout << std::endl;
	Bureaucrat carlos("Carlos", 3);
	Bureaucrat lituanio("Lituanio", 149);
	std::cout << carlos << std::endl
		 << lituanio << std::endl;
	carlos.inc();
	lituanio.dec();
	std::cout << carlos << std::endl
		 << lituanio << std::endl;
	carlos.inc();
	lituanio.dec();
	std::cout << carlos << std::endl
		 << lituanio << std::endl;
	carlos.inc();
	lituanio.dec();
	std::cout << carlos << std::endl
		 << lituanio << std::endl;

	std::cout << std::endl;

	return 0;
}