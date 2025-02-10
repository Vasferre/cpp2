#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <sstream>
# include <bits/stdc++.h>
# include <cmath>

class ScalarConverter
{
    private:

    public:
            ScalarConverter();
            ScalarConverter(const ScalarConverter &copy);

            ~ScalarConverter();

            ScalarConverter & operator=(const ScalarConverter &assign);

            static void convert(std::string convert);
};

#endif