#include "Calc.h"


Calc::Calc() : funTbl_(symTbl_), storage_(symTbl_)
{
}

Calc::~Calc()
{
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