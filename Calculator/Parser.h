#ifndef _PARSER_H_
#define _PARSER_H_

class Scanner;
class Node;
class Calc;

enum STATUS
{
	STATUS_OK,
	STATUS_ERROR,
	STATUS_QUIT
};

class Parser
{
public:
	Parser(Scanner& scanner, Calc& calc);
	~Parser();
	STATUS Parse();
	Node* Expr();
	Node* Term();
	Node* Factor();
	double Calculate() const;

private:
	Scanner& scanner_;
	Calc& calc_;
	Node* tree_;
	STATUS status_;

};

#endif //_PARSER_H_

