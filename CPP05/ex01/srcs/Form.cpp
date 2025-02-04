#include "Form.hpp"

Form::Form() : name("default"), is_signed(false), grade(1), exec_grade(1)
{

}

Form::Form(std::string name, int grade, int exec_grade) : name(name), is_signed(false)
{
    try
    {
        if (grade < 1 || exec_grade < 1)
            throw Form::GradeTooHighException();
        if (grade > 150 || exec_grade > 150)
            throw Form::GradeTooLowException();
        this->grade = grade;
        this->exec_grade = exec_grade;
        std::cout << "Fields constructor called of Form" << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

Form::Form(const Form &copy)
{
    *this = copy;
    std::cout << "copy Constructor called of Form" << std::endl;
}

Form::~Form()
{
    std::cout << "Destructor Called of Form" << std::endl;
}

Form & Form::operator=(const Form &assign)
{
    name = assign.get_name();
    is_signed = assign.get_is_signed();
    grade = assign.get_sign();
    exec_grade = assign.get_grade();
    return *this;
}

std::string Form::get_name() const
{
    return name;
}

bool Form::get_is_signed() const
{
    return is_signed;
}

int Form::get_sign() const
{
    return grade;
}

int Form::get_grade() const
{
    return exec_grade;
}

void Form::beSigned(Bureaucrat &buro)
{
    if(buro.get_grade() > grade)
        throw (Form::GradeTooLowException());
    else
    {
        is_signed = true;
        std::cout << buro.get_name() << "sucessfully signed" << name << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	return out << "Form: " << form.get_name() << "(name), " << form.get_is_signed() << "(is singed), " << form.get_sign() << "(signed grade), " << form.get_grade() << "(exec grade)." ;
}

const char * Form::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char * Form::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}