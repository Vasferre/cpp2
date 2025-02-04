#include <ctime>
#pragma once

#include "AForm.hpp"

class RobotmyRequestForm
 : public AForm
{
    private:
        RobotmyRequestForm();
    public:
        RobotmyRequestForm(std::string target);
        RobotmyRequestForm(const RobotmyRequestForm &copy);
        ~RobotmyRequestForm();

        RobotmyRequestForm & operator=(const RobotmyRequestForm &assign);

        void executeAction() const;
};