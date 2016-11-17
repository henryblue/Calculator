#include <cassert>
#include <iostream>
#include "CommandParser.h"
#include "Scanner.h"
#include "Calc.h"
#include "Exception.h"

CommandParser::CommandParser(Scanner& scanner, Calc& calc):
	scanner_(scanner), calc_(calc)
{
	assert(scanner_.IsCommand());
	scanner_.Accept();
	cmdName_ = scanner_.GetSymbol();
	parser();
}


CommandParser::~CommandParser()
{
}

void CommandParser::parser()
{
	switch (tolower(cmdName_[0]))
	{
	case 'h':
		cmd_ = CMD_HELP;
		break;
	case 'q':
		cmd_ = CMD_QUIT;
		break;
	case 'v':
		cmd_ = CMD_VAR;
		break;
	case 'f':
		cmd_ = CMD_FUN;
		break;
	case 'l':
		cmd_ = CMD_LOAD;
		break;
	case 's':
		cmd_ = CMD_SAVE;
		break;
	default:
		cmd_ = CMD_ERROR;
		break;
	}
}

void CommandParser::Help() const
{
	std::cout << "Recogniaed commands:" << std::endl;
	std::cout << "!help" << std::endl;
	std::cout << "!quit" << std::endl;
	std::cout << "!v" << std::endl;
	std::cout << "!f" << std::endl;
	std::cout << "!load filename" << std::endl;
	std::cout << "!save filename" << std::endl;
}

void CommandParser::ListVar() const
{
	std::cout << "variable list:" << std::endl;
	calc_.ListVar();
}

void CommandParser::ListFun() const
{
	std::cout << "funcation list:" << std::endl;
	calc_.ListFun();
}

STATUS CommandParser::Save(const std::string& fileName)
{
	std::cout << "save \"" << fileName << "\"." << std::endl;
	STATUS status = STATUS_OK;
	try
	{
		Serializer out(fileName);
		calc_.Serialize(out);
	}
	catch (FileStreamError& e)
	{
		std::cout << "Save Error: " << e.what() << std::endl;
		status = STATUS_ERROR;
	}
	return status;
}

STATUS CommandParser::Load(const std::string& fileName)
{
	std::cout << "load \"" << fileName << "\"." << std::endl;
	STATUS status = STATUS_OK;
	try
	{
		DeSerializer in(fileName);
		calc_.DeSerialize(in);
	}
	catch (FileStreamError& e)
	{
		std::cout << "Load Error: " << e.what() << std::endl;
		status = STATUS_ERROR;
	}
	return status;
}

STATUS CommandParser::Execute()
{
	STATUS status = STATUS_OK;
	scanner_.AcceptCommand();
	std::string fileName;
	switch (cmd_)
	{
	case CMD_HELP:
		Help();
		break;
	case CMD_QUIT:
		status = STATUS_QUIT;
		break;
	case CMD_VAR:
		ListVar();
		break;
	case CMD_FUN:
		ListFun();
		break;
	case CMD_LOAD:
		fileName = scanner_.GetSymbol();
		status = Load(fileName);
		break;
	case CMD_SAVE:
		fileName = scanner_.GetSymbol();
		status = Save(fileName);
		break;
	case CMD_ERROR:
	default:
		status = STATUS_ERROR;
		std::cout << "Unknown Command \"" << cmdName_ <<"\"."<< std::endl;
		break;
	}
	
	return status;
}