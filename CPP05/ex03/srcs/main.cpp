#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotmyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat zoze("Jose", 150);
	Bureaucrat Vasco("Vasco the executer", 1);
	std::cout << std::endl;

	// AForm aform("a", "b", 0, 0);

	ShrubberyCreationForm monke("monke");
	PresidentialPardonForm apps("apps");
	RobotmyRequestForm primats("primats");

	zoze.executeForm(monke);
	zoze.signForm(monke);
	Vasco.signForm(monke);
	zoze.executeForm(monke);

	std::cout << std::endl;

	Vasco.signForm(monke);
	Vasco.executeForm(monke);

	std::cout << std::endl;

	Vasco.signForm(primats);
	Vasco.executeForm(primats);
	Vasco.executeForm(primats);

	std::cout << std::endl;

	Vasco.signForm(apps);
	Vasco.executeForm(apps);

	std::cout << std::endl;

	return 0;
}