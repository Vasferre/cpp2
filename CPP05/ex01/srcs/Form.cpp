#include "Form.hpp"

Form::Form() : _name("default"), _is_signed(false), _sign_grade(1), _exec_grade(1)
{}

Form::Form(std::string name, int sign_grade, int exec_grade) : _name(name), _is_signed(false)
{
	try
	{
		if (sign_grade < 1 || exec_grade < 1 )
			throw Form::GradeTooHighException();
		if (sign_grade > 150 || exec_grade > 150 )
			throw Form::GradeTooLowException();
		_sign_grade = sign_grade;
		_exec_grade = exec_grade;
		std::cout << "Fields Constructor called of Form" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Form::Form(const Form &copy)
{
	*this = copy;
	std::cout << "Copy Constructor called of Form" << std::endl;
}

Form::~Form()
{
	std::cout << "Destructor called of Form" << std::endl;
}

Form & Form::operator=(const Form &assign)
{
	_name = assign.get_name();
	_is_signed = assign.get_is_signed();
	_sign_grade = assign.get_sign_grade();
	_exec_grade = assign.get_exec_grade();
	return *this;
}

std::string Form::get_name() const
{
	return _name;
}

bool Form::get_is_signed() const
{
	return _is_signed;
}

int Form::get_sign_grade() const
{
	return _sign_grade;
}

int Form::get_exec_grade() const
{
	return _exec_grade;
}

void Form::beSigned(Bureaucrat &buro)
{
	if (buro.get_grade() > _sign_grade)
		throw (Form::GradeTooLowException());
	else
	{
		_is_signed = true;
		std::cout << buro.get_name() << " successfully signed" << _name << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	return out << "Form: " << form.get_name() << "(name), " << form.get_is_signed() << "(is singed), " << form.get_sign_grade() << "(signed grade), " << form.get_exec_grade() << "(exec grade)." ;
}

const char * Form::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char * Form::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}