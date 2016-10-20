#include "Parser.h"
#include "scanner.h"
#include "Node.h"
#include <cassert>
#include <iostream>

Parser::Parser(Scanner& scanner) : scanner_(scanner), tree_(0)
{
}

void Parser::Parse()
{
	tree_ = Expr();
}

Node* Parser::Expr()
{
	Node* node = Term();
	EToken token = scanner_.Token();
	if (token == TOKEN_PLUS)
	{
		scanner_.Accept();
		Node* nodeRight = Expr();
		node = new AddNode(node, nodeRight);
	}
	else if (token == TOKEN_MINUS)
	{
		scanner_.Accept();
		Node* nodeRight = Expr();
		node = new SubNode(node, nodeRight);
	}
	return node;
}
Node* Parser::Term()
{
	Node* node = Factor();
	EToken token = scanner_.Token();
	if (token == TOKEN_MULTIPLY)
	{
		scanner_.Accept();
		Node* nodeRight = Term();
		node = new MultiplyNode(node, nodeRight);
	}
	else if (token == TOKEN_DIVIDE)
	{
		scanner_.Accept();
		Node* nodeRight = Term();
		node = new DivideNode(node, nodeRight);
	}
	return node;
}

Node* Parser::Factor()
{
	Node* node;
	EToken token = scanner_.Token();
	if (token == TOKEN_LPARENTHESIS)
	{
		scanner_.Accept(); // accept '('
		node = Expr();
		if (scanner_.Token() == TOKEN_RPARENTHESIS)
		{
			scanner_.Accept(); // accept ')'
		}
		else
		{
			status_ = STATUS_ERROR;
			// TODO: 抛出异常
			std::cout << "missing parentthesis" << std::endl;
			node = 0;
		}
	}
	else if (token == TOKEN_NUMBER)
	{
		node = new NumberNode(scanner_.Number());
		scanner_.Accept();
	}
	else if (token == TOKEN_MINUS)
	{
		scanner_.Accept();   // accept minus
		node = new UMinusNode(Factor());
	}
	else
	{
		status_ = STATUS_ERROR;
		// TODO: 抛出异常
		std::cout << "Not a valid expreesion" << std::endl;
		node = 0;
	}
	return node;
}

double Parser::Calculate() const
{
	assert(tree_ != 0);
	return tree_->Calc();
}
