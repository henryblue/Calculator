#include <algorithm>
#include "SymbolTable.h"
#include "Exception.h"

SymbolTable::~SymbolTable()
{
}

unsigned int SymbolTable::GetCurId() const
{
	return curId_;
}

unsigned int SymbolTable::Add(const std::string& str)
{
	dictionary_[str] = curId_;
	return curId_++;
}

unsigned int SymbolTable::Find(const std::string& str) const
{
	std::map<const std::string, unsigned int>::const_iterator it;
	it = dictionary_.find(str);
	if (it != dictionary_.end())
	{
		return it->second;
	}
	else
	{
		return ID_NOT_FIND;
	}
}

void SymbolTable::Clear()
{
	dictionary_.clear();
	curId_ = 0;
}

class IsEqualId
{
public:
	IsEqualId(unsigned int id) :id_(id) {}
	bool operator()(const std::pair<const std::string, unsigned int>& it)
	{
		return it.second == id_;
 	}

private:
	unsigned int id_;
};

std::string SymbolTable::GetSymbolName(unsigned int id) const
{
	std::map<const std::string, unsigned int>::const_iterator it;
	IsEqualId isEqualId(id);
	it = find_if(dictionary_.begin(), dictionary_.end(), isEqualId);
	if (it == dictionary_.end())
	{
		throw Exception("Internal error: missing entry in symbol table");
	}
	return it->first;
}