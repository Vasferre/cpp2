#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotmy form", "default", 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("robotmy form", target, 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
{
    *this = copy;
    std::cout << "Copy Constructor called of RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Destructor called of RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &assign)
{
    if (this == &assign)
        return *this;
    return *this;
}

void RobotomyRequestForm::executeAction() const 
{
    std::srand(std::time(NULL));

    std::cout << "Drill" << std::endl;

    if(random() % 2 == 0)
        std::cout << this->get_target() << "sucessfully robotmized" << std::endl;
    else
        std::cout << this->get_target() << "failed when trying to robotimize" << std::endl;
}