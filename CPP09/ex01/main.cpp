#include "RPN.hpp"

int main(int argc, char const *argv[])
{

    if (argc != 2)
    {
        std::cout << "Invalid amount of arguments" << std::endl;
        return 1;
    }

    try
    {
        RPN rpn;
        std::cout << rpn.getResult(std::string(argv[1])) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}