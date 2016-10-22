#ifndef _CALC_H_
#define _CALC_H_

#include "SymbolTable.h"
#include "Storage.h"
#include "FuncationTable.h"

class Calc
{
friend class Parser;
public:
	Calc();
	~Calc();

private:
	unsigned int FindSymbol(const std::string& str) const;
	unsigned int AddSymbol(const std::string& str);
	Storage& GetStorage();
	bool IsFuncation(unsigned int id) const;
	PtrFun GetFuncation(unsigned int id) const;

private:
	SymbolTable symTbl_;
	FuncationTable funTbl_;
	Storage storage_;
};

#endif

