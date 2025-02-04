#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat zoze("Jose", 150);
	Bureaucrat jorge("Jorge the executer", 1);
	std::cout << std::endl;

	// AForm aform("a", "b", 0, 0);

	ShrubberyCreationForm monke("monke");
	PresidentialPardonForm apps("apps");
	RobotomyRequestForm primats("primats");

	zoze.executeForm(monke);
	zoze.signForm(monke);
	jorge.signForm(monke);
	zoze.executeForm(monke);

	std::cout << std::endl;

	jorge.signForm(monke);
	jorge.executeForm(monke);

	std::cout << std::endl;

	jorge.signForm(primats);
	jorge.executeForm(primats);
	jorge.executeForm(primats);

	std::cout << std::endl;

	jorge.signForm(apps);
	jorge.executeForm(apps);

	std::cout << std::endl;

	return 0;
}