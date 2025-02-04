#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	srand(time(NULL));
	char c = "ABC"[rand() % 3];

	std::cout << "Type " << c << " created!" << std::endl;
	switch (c)
	{
	case 'A':
		return new A;
	case 'B':
		return new B;
	case 'C':
		return new C;
	}
	return NULL;
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Pointer is type A." << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Pointer is type B." << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Pointer is type C." << std::endl;
	else
		std::cout << "Cannot identify pointer type." << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "Reference is type A." << std::endl;
	}
	catch (std::exception &exception)
	{
		try
		{
			B &b = dynamic_cast<B &>(p);
			(void)b;
			std::cout << "Reference is type B." << std::endl;
		}
		catch (std::exception &exception)
		{
			try
			{

				C &c = dynamic_cast<C &>(p);
				(void)c;
				std::cout << "Reference is type C." << std::endl;
			}
			catch (std::exception &exception)
			{

				std::cout << "Cannot identify pointer type." << std::endl;
			}
		}
	}
}

int main()
{
	Base *type = generate();

	identify(type);
	identify(*type);

	delete type;
	return 0;
}