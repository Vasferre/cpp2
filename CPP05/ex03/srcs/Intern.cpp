#include "intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotmyRequestForm.hpp"

Intern::Intern()
{
	std::cout << "\e[0;33mDefault Constructor called of Intern\e[0m" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of Intern\e[0m" << std::endl;
}

Intern::~Intern()
{
	std::cout << "\e[0;31mDestructor called of Intern\e[0m" << std::endl;
}

Intern & Intern::operator=(const Intern &assign)
{
	if (this == &assign) return *this;
	return *this;
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	AForm *new_form = NULL;

	t_forms forms[3] = {
		{ "shrubbery creation", new ShrubberyCreationForm(target) },
		{ "robotmy request", new RobotmyRequestForm(target) },
		{ "presidential pardon", new PresidentialPardonForm(target) }
	};

	for (int i = 0; i < 3; i++) 
	{
		if (forms[i].name == name) new_form = forms[i].formclass;
		else delete forms[i].formclass;
	}

	if (!new_form) std::cout << "Intern was not able to find the form " << name << std::endl;
	else std::cout << "Intern creates form " << name << std::endl;
	
	return (new_form);
}