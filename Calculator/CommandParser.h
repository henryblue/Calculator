#ifndef _COMMANDPARSER_H_
#define _COMMANDPARSER_H_

#include <string>
#include "Parser.h"

class Scanner;
class Calc;
class CommandParser
{
public:
	enum ECOmmand
	{
		CMD_HELP,
		CMD_QUIT,
		CMD_VAR,
		CMD_FUN,
		CMD_LOAD,
		CMD_SAVE,
		CMD_ERROR
	};

public:
	CommandParser(Scanner& scanner, Calc& calc);
	~CommandParser();
	STATUS Execute();

private:
	void parser();
	void Help() const;
	void ListVar() const;
	void ListFun() const;
	STATUS Save(const std::string& fileName);
	STATUS Load(const std::string& fileName);

private:
	Scanner& scanner_;
	Calc& calc_;
	ECOmmand cmd_;
	std::string cmdName_;
};

#endif //_COMMANDPARSER_H_
