#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat vasco("vasco", 150);
	Bureaucrat rui("rui the executer", 1);
	std::cout << std::endl;

	// AForm aform("a", "b", 0, 0);

	ShrubberyCreationForm cats("cats");
	PresidentialPardonForm tigers("tigers");
	RobotomyRequestForm leons("leons");

	vasco.executeForm(cats);
	vasco.signForm(cats);
	rui.signForm(cats);
	vasco.executeForm(cats);

	std::cout << std::endl;

	rui.signForm(cats);
	rui.executeForm(cats);

	std::cout << std::endl;

	rui.signForm(leons);
	rui.executeForm(leons);
	rui.executeForm(leons);

	std::cout << std::endl;

	rui.signForm(tigers);
	rui.executeForm(tigers);

	std::cout << std::endl;

	return 0;
}
