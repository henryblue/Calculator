#ifndef _PARSER_H_
#define _PARSER_H_

class Scanner;
class Node;
enum STATUS
{
	STATUS_OK,
	STATUS_ERROR,
	STATUS_QUIT
};

class Parser
{
public:
	Parser(Scanner& scanner);
	~Parser(){}
	void Parse();
	Node* Expr();
	Node* Term();
	Node* Factor();
	double Calculate() const;

private:
	Scanner& scanner_;
	Node* tree_;
	STATUS status_;

};

#endif //_PARSER_H_

