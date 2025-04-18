#include "BitcoinExchange.hpp"

float getFinalValue(Btc btc, std::string &key, std::string &value)
{
    std::stringstream exchange(value);
    float fvalue;
    exchange >> fvalue;

    float amount = btc.getFromDate(key);

    if (fvalue < 0)
        throw Btc::NegativeException();

    if (fvalue > 1000)
        throw Btc::TooBigException();

    return fvalue * amount;
}

int main(int argc, char const *argv[])
{

    if (argc != 2)
    {
        std::cout << "Invalid amount of arguments" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open())
    {
        std::cout << "Fail opening file" << std::endl;
        return 1;
    }

    Btc btc;

    std::string line;
    std::string key;
    std::string value;

    std::getline(file, line);

    while (std::getline(file, line))
    {
        try
        {
            std::stringstream ss(line);
            std::getline(ss, key, '|');
            std::getline(ss, value);

            float final = getFinalValue(btc, key, value);

            std::cout << key << " => " << value << " = " << final << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    return 0;
}