#include <cmath>
#include <cassert>
#include <iostream>
#include "Storage.h"
#include "SymbolTable.h"

Storage::Storage(SymbolTable& tbl)
{
	AddConstants(tbl);
}


Storage::~Storage()
{
}

void Storage::Clear()
{
	cells_.clear();
	inits_.clear();
}

bool Storage::IsInit(unsigned int id) const
{
	return id < cells_.size() && inits_[id];
}

void Storage::AddConstants(SymbolTable& tbl)
{
	std::cout << "variable list:" << std::endl;
	unsigned int id = tbl.Add("e");
	AddValue(id, exp(1.0));
	std::cout << "  e=" << exp(1.0) << std::endl;
	id = tbl.Add("pi");
	AddValue(id, 2.0 * acos(0.0)); //·´ÓàÏÒ pi = 2*cos(0)
	std::cout << "  pi=" << 2.0 * acos(0.0) << std::endl << std::endl;
}

double Storage::GetValue(unsigned int id) const
{
	assert(id < cells_.size());
	return cells_[id];
}

void Storage::SetValue(unsigned int id, double val)
{
	assert(id <= cells_.size());
	if (id < cells_.size())
	{
		cells_[id] = val;
		inits_[id] = true;
	}
	else if (id == cells_.size())
	{
		AddValue(id, val);
	}
}

void Storage::AddValue(unsigned int id, double val)
{
	cells_.resize(id + 1);
	inits_.resize(id + 1);
	cells_[id] = val;
	inits_[id] = true;
}