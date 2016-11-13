#ifndef _SCANNER_H_
#define _SCANNER_H_
#include <string>

enum EToken
{
	TOKEN_COMMAND,
	TOKEN_END,
	TOKEN_ERROR,
	TOKEN_NUMBER,
	TOKEN_PLUS,
	TOKEN_MINUS,
	TOKEN_MULTIPLY,
	TOKEN_DIVIDE,
	TOKEN_LPARENTHESIS,
	TOKEN_RPARENTHESIS,
	TOKEN_IDENTIFIER,   
	TOKEN_ASSIGN
};

class Scanner
{
public:
	explicit Scanner(std::istream& in);
	~Scanner(){}
	void Accept();
	void AcceptCommand();
	bool IsEmpty() const;
	bool IsCommand() const;
	bool IsScannerDone() const;
	double Number() const;
	EToken Token() const;
	std::string GetSymbol() const;

private:
	void ReadChar();

private:
	std::istream& in_;
	EToken token_;
	double number_;
	std::string symbol_;
	bool isEmpty_;
	int look_;
};

#endif //_SCANNER_H_

