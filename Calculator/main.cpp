#include <iostream>
#include <string>
#include "Scanner.h"
#include "Parser.h"
#include "Calc.h"
#include "Exception.h"

int main() 
{
	STATUS status = STATUS_OK;
	Calc calc;
	do
	{
		std::cout << ">> ";
		Scanner scanner(std::cin);
		if (!scanner.IsEmpty())
		{
			Parser parser(scanner, calc);
			try
			{
				status = parser.Parse();
				if (status == STATUS_OK)
				{
					std::cout << parser.Calculate() << std::endl;
				}
			}
			catch (SyntaxError& e)
			{
				status = STATUS_ERROR;
				std::cout << e.what() << std::endl;
			}
			catch (Exception& e)
			{
				status = STATUS_ERROR;
				std::cout << e.what() << std::endl;
			}
			catch (std::bad_alloc& e)
			{
				status = STATUS_ERROR;
				std::cout << e.what() << std::endl;
			}
			catch (...)
			{
				status = STATUS_ERROR;
				std::cout << "Internal error" << std::endl;
			}
		}
		else
		{
			std::cout << "Expression is empty" << std::endl;
		}
	} while (status != STATUS_QUIT);

	return 0;
}