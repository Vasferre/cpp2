#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm 
{
	private:

		RobotomyRequestForm();

	public:
		RobotomyRequestForm(std::string _target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		~RobotomyRequestForm();

		RobotomyRequestForm & operator=(const RobotomyRequestForm &assign);

		void executeAction() const;
};