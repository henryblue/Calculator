#include <iostream>
#include <string>
#include "Scanner.h"
#include "Parser.h"
#include "Calc.h"

int main() 
{
	STATUS status = STATUS_OK;
	Calc calc;
	do
	{
		std::cout << ">> ";
		std::string buf;
		std::getline(std::cin, buf);
		//std::cout << buf << std::endl;
		Scanner scanner(buf);
		if (!scanner.IsEmpty())
		{
			Parser parser(scanner, calc);
			status = parser.Parse();
			if (status == STATUS_OK)
			{
				std::cout << parser.Calculate() << std::endl;
			}
			else if (status == STATUS_ERROR)
			{
				std::cout << "Syntax Error" << std::endl;
			}
		}
		else
		{
			std::cout << "Expression is empty" << std::endl;
		}
	} while (status != STATUS_QUIT);

	return 0;
}