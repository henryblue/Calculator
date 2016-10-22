#ifndef _FUNCATIONTABLE_H_
#define _FUNCATIONTABLE_H_

class SymbolTable;

typedef double(*PtrFun)(double);

class FuncationTable
{
public:
	FuncationTable(SymbolTable& tmbl);
	~FuncationTable();
	unsigned int size() const
	{
		return size_;
	}
	PtrFun GetFuncation(unsigned int id) const;

private:
	void Init(SymbolTable& tmbl);

private:
	PtrFun* pFuns_;
	unsigned int size_;
};

#endif
