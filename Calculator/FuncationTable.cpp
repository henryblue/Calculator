#include <cmath>
#include <cassert>
//#include <iostream>
#include "FuncationTable.h"
#include "SymbolTable.h"
#include "DebugNew.h"

struct FuncationEntry
{
	PtrFun pFun_;
	char* funName_;
};

FuncationEntry Entrys[] =
{
	log, "log",
	log10, "log10",
	exp, "exp",
	sqrt, "sqrt",
	sin, "sin",
	cos, "cos",
	tan, "tan",
	sinh, "sinh",
	cosh, "cosh",
	tanh, "tanh",
	asin, "asin",
	acos, "acos",
	atan, "atan"
};

FuncationTable::FuncationTable(SymbolTable& tmbl)
	: size_(sizeof(Entrys)/ sizeof(Entrys[0]))
{
	Init(tmbl);
}

void FuncationTable::Init(SymbolTable& tmbl)
{
	//std::cout << "Funcation list:" << std::endl;
	pFuns_ = new PtrFun[size_];
	for (unsigned int i = 0; i < size_; ++i)
	{
		pFuns_[i] = Entrys[i].pFun_;
		unsigned int j = tmbl.Add(Entrys[i].funName_);
		assert(i == j);
		/*if ((i + 1) % 2 == 0)
		{
			std::cout << "  " << Entrys[i].funName_ << std::endl;
		}
		else
		{
			std::cout << "  " << Entrys[i].funName_;
		}*/
	}
	//std::cout << std::endl;
}

PtrFun FuncationTable::GetFuncation(unsigned int id) const
{
	return pFuns_[id];
}

FuncationTable::~FuncationTable()
{
	delete[] pFuns_;
}
