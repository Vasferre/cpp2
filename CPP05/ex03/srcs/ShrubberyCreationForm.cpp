#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery form", "default", 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("shrubbery form", target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
{
	*this = copy;
	std::cout << "Copy Constructor called of ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor called of ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
	if (this == &assign) return *this;
	return *this;
}

void ShrubberyCreationForm::executeAction() const {

	std::ofstream out;

	out.open((this->get_target() + "_shrubbery").c_str(), std::ofstream::in | std::ofstream::trunc);

	out << std::endl;
	out << "                                            ." << std::endl;
	out << "                                    .         ;  " << std::endl;
	out << "       .              .              ;%     ;;   " << std::endl;
	out << "         ,           ,                :;%  %;   " << std::endl;
	out << "          :         ;                   :;%;'     .,   " << std::endl;
	out << " ,.        %;     %;            ;        %;'    ,;" << std::endl;
	out << "   ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
	out << "    %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
	out << "     ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
	out << "      `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
	out << "       `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
	out << "          `:%;.  :;bd%;          %;@%;'" << std::endl;
	out << "            `@%:.  :;%.         ;@@%;'   " << std::endl;
	out << "              `@%.  `;@%.      ;@@%;         " << std::endl;
	out << "                `@%%. `@%%    ;@@%;        " << std::endl;
	out << "                  ;@%. :@%%  %@@%;       " << std::endl;
	out << "                    %@bd%%%bd%%:;     " << std::endl;
	out << "                      #@%%%%%:;;" << std::endl;
	out << "                      %@@%%%::;" << std::endl;
	out << "                      %@@@%(o);  . '         " << std::endl;
	out << "                      %@@@o%;:(.,'         " << std::endl;
	out << "                  `.. %@@@o%::;         " << std::endl;
	out << "                     `)@@@o%::;         " << std::endl;
	out << "                      %@@(o)::;        " << std::endl;
	out << "                     .%@@@@%::;         " << std::endl;
	out << "                     ;%@@@@%::;.          " << std::endl;
	out << "                    ;%@@@@%%:;;;. " << std::endl;
	out << "                ...;%@@@@@%%:;;;;,..   " << std::endl;

}