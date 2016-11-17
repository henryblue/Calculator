#ifndef _STORAGE_H_
#define _STORAGE_H_

#include <vector>
#include "Serial.h"

class SymbolTable;

class Storage : public Serializable
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

public:
	void Serialize(Serializer& out) const;
	void DeSerialize(DeSerializer& in);

private:
	std::vector<double> cells_;
	std::vector<bool> inits_;
};

#endif // _STORAGE_H_

