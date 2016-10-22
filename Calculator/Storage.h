#ifndef _STORAGE_H_
#define _STORAGE_H_

#include <vector>

class SymbolTable;

class Storage
{
public:
	Storage(SymbolTable& tbl);
	~Storage();
	void Clear();
	bool IsInit(unsigned int id) const;
	void AddConstants(SymbolTable& tbl);
	double GetValue(unsigned int id) const;
	void SetValue(unsigned int id, double val);
	void AddValue(unsigned int id, double val);

private:
	std::vector<double> cells_;
	std::vector<bool> inits_;
};

#endif // _STORAGE_H_

