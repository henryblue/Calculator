#include <iostream>
#include "Calc.h"


Calc::Calc() : funTbl_(symTbl_), storage_(symTbl_)
{
}

Calc::~Calc()
{
}

void Calc::ListFun() const
{
	for (unsigned int i = 0; i < funTbl_.size(); ++i)
	{
		std::cout << symTbl_.GetSymbolName(i) << std::endl;
	}
}

void Calc::ListVar() const
{
	for (unsigned int i = funTbl_.size(); i < symTbl_.GetCurId(); ++i)
	{
		std::string name = symTbl_.GetSymbolName(i);
		double val;
		if (GetVariableValue(i, val))
		{
			std::cout << name << " = " << val << std::endl;
		}
		else
		{
			std::cout << name << " = ?" << std::endl;
		}
	}
}

bool Calc::GetVariableValue(unsigned int id, double& val) const
{
	if (storage_.IsInit(id))
	{
		val = storage_.GetValue(id);
		return true;
	}
	return false;
}

bool Calc::IsFuncation(unsigned int id) const
{
	return id < funTbl_.size();
}

PtrFun Calc::GetFuncation(unsigned int id) const
{
	return funTbl_.GetFuncation(id);
}

unsigned int Calc::FindSymbol(const std::string& str) const
{
	return symTbl_.Find(str);
}

unsigned int Calc::AddSymbol(const std::string& str)
{
	return symTbl_.Add(str);
}

Storage& Calc::GetStorage()
{
	return storage_;
}