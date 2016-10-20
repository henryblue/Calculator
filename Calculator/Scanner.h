#ifndef _SCANNER_H_
#define _SCANNER_H_
#include <string>

enum EToken
{
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
	Scanner(const std::string& buf);
	~Scanner(){}
	void Accept();
	double Number() const;
	EToken Token() const;

private:
	void skipWhite();

private:
	const std::string buf_;
	EToken token_;
	double number_;
	unsigned int curPos_;
};

#endif //_SCANNER_H_

