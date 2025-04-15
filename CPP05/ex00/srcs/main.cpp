#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat Vasco("Vasco", 15);
	std::cout << Vasco << std::endl;

	std::cout << std::endl;
	Bureaucrat juninho("juninho", 151);
	Bureaucrat juninho2("juninho2", 0);

	std::cout << std::endl;
	Bureaucrat Pedro("pedro", 3);
	Bureaucrat rui("rui", 149);
	std::cout << Pedro << std::endl
		 << rui << std::endl;
	Pedro.inc();
	rui.dec();
	std::cout << Pedro << std::endl
		 << rui << std::endl;
	Pedro.inc();
	rui.dec();
	std::cout << Pedro << std::endl
		 << rui << std::endl;
	Pedro.inc();
	rui.dec();
	std::cout << Pedro << std::endl
		 << rui << std::endl;

	std::cout << std::endl;

	return 0;
}