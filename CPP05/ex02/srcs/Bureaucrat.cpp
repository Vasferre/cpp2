#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void):name("default"), grade(1)
{

}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
    try
    {
        if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
        if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
        this->grade = grade;
        std::cout << "Fields Constructor called of Bureaucrat" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
    Bureaucrat::Bureaucrat(const Bureaucrat &copy)
    {
        *this = copy;
        std::cout << "copy Constructor called of Bureaucrat" << std::endl;
    }

    Bureaucrat::~Bureaucrat()
    {
        std::cout << "Destructor called of Bureaucrat" << std::endl;
    }

    Bureaucrat &Bureaucrat::operator=(const Bureaucrat &assign)
    {
        grade = assign.get_grade();
        return *this;
    }

    void Bureaucrat::inc()
    {
        try
        {
            if (grade == 1)
                throw Bureaucrat::GradeTooHighException();
            grade -= 1;
        }
        catch(const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    void Bureaucrat::dec()
    {
        try
        {
            if (grade == 150)
                throw Bureaucrat::GradeTooLowException();
            grade += 1;
        }
        catch(const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << name << " signed " << form.get_name() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << name << " couldn't sign " << form.get_name() << " because " << e.what() << std::endl; 
	}
}
}

    std::string Bureaucrat::get_name() const
    {
        return name;
    }

    int Bureaucrat::get_grade() const
    {
        return grade;
    }

    std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
    {
        return out << bureaucrat.get_name() << ", bureaucrat grade " << bureaucrat.get_grade() << ".";
    }

    const char *Bureaucrat::GradeTooHighException::what() const throw()
    {
        return "grade too high";
    }

    const char *Bureaucrat::GradeTooLowException::what() const throw()
    {
        return "Grade too low";
    }