#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "\e[0;33mDefault Constructor called of ScalarConverter\e[0m" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of ScalarConverter\e[0m" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "\e[0;31mDestructor called of ScalarConverter\e[0m" << std::endl;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter &assign)
{
	if (this == &assign) return *this;
	return *this;
}

void print(float convert){
	
	const char char_value = static_cast<char>(convert);
	const long long_value = static_cast<long>(convert);
	bool end_in_zero = static_cast<int>(convert) - convert == 0;

	std::cout << "char: ";
	if (convert < CHAR_MIN || convert > CHAR_MAX || std::isnan(convert))
		std::cout << "impossible" << std::endl;
	else if (!isprint(convert))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << char_value << std::endl;


	std::cout << "int: ";
	if (long_value < INT_MIN || long_value > INT_MAX || std::isnan(convert))
		std::cout << "impossible" << std::endl;
	else
		std::cout << long_value << std::endl;

	std::cout << "float: " << convert;
	if (end_in_zero)
		std::cout << ".0";
	std::cout << "f" << std::endl;

	std::cout << "double: " << static_cast<double>(convert);
	if (end_in_zero)
		std::cout << ".0";
	std::cout << std::endl;

}

void print(double convert){
	const char char_value = static_cast<char>(convert);
	const long long_value = static_cast<long>(convert);
	bool end_in_zero = static_cast<int>(convert) - convert == 0;

	std::cout << "char: ";
	if (convert < CHAR_MIN || convert > CHAR_MAX || isnan(convert))
		std::cout << "impossible" << std::endl;
	else if (!isprint(convert))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << char_value << std::endl;


	std::cout << "int: ";
	if (long_value < INT_MIN || long_value > INT_MAX || isnan(convert))
		std::cout << "impossible" << std::endl;
	else
		std::cout << long_value << std::endl;


	std::cout << "float: " << static_cast<float>(convert);
	if (end_in_zero)
		std::cout << ".0";
	std::cout << "f" << std::endl;

	std::cout << "double: " << convert;
	if (end_in_zero)
		std::cout << ".0";
	std::cout << std::endl;
}

void print(int convert){

	const char char_value = static_cast<char>(convert);

	std::cout << "char: ";
	if (convert < CHAR_MIN || convert > CHAR_MAX)
		std::cout << "impossible" << std::endl;
	else if (!isprint(convert))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << char_value << std::endl;

	std::cout << "int: " << static_cast<int>(convert) << std::endl;
	std::cout << "float: " << static_cast<float>(convert) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(convert) << ".0" << std::endl;

}

void print(char convert){
	std::cout << "char: " << convert << std::endl;
	std::cout << "int: " << static_cast<int>(convert) << std::endl;
	std::cout << "float: " << static_cast<float>(convert) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(convert) << ".0" << std::endl;
}

bool is_double(const std::string &str)
{
    return (str.find_first_not_of("0123456789.-") == std::string::npos && str.find(".") != std::string::npos
		&& (str.find("-") == 0 || str.find("-") == std::string::npos))
		|| ( str == "-inf" || str == "+inf" || str == "nan");
}

bool is_float(const std::string &str)
{
    return (str.find_first_not_of("0123456789.f-") == std::string::npos && str.find(".") != std::string::npos
		&& str.find("f", str.length() - 1)!= std::string::npos && (str.find("-") == 0 || str.find("-") == std::string::npos))
		|| ( str == "-inff" || str == "+inff" || str == "nanf") ;
}

bool is_int(const std::string &str)
{
    return str.find_first_not_of("0123456789.-") == std::string::npos && ((str.find("-") == 0 && str.length() > 1 ) || str.find("-") == std::string::npos);
}

void ScalarConverter::convert(std::string convert)
{
	double convert_to_d;

	if (is_float(convert))
		print(std::atof(convert.c_str()));
	else if (is_double(convert))
	{
		convert_to_d = std::atof(convert.c_str());
		print(convert_to_d);
	}
	else if (is_int(convert))
		print(std::atoi(convert.c_str()));
	else if (convert.length() == 1)
		print(convert[0]);
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}
