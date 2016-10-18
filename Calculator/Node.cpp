#include "Node.h"
#include <cmath>
#include <iostream>

double NumberNode::Calc() const
{
	return number_;
}

BinaryNode::~BinaryNode()
{
	delete leftNode_;
	delete rightNode_;
}

UnaryNode::~UnaryNode()
{
	delete childNode_;
}

double AddNode::Calc() const
{
	return leftNode_->Calc() + rightNode_->Calc();
}

double SubNode::Calc() const
{
	return leftNode_->Calc() - rightNode_->Calc();
}

double MultiplyNode::Calc() const
{
	return leftNode_->Calc() * rightNode_->Calc();
}

double DivideNode::Calc() const
{
	double divisor = rightNode_->Calc();
	if (divisor != 0)
	{
		return leftNode_->Calc() / divisor;
	}
	else
	{
		std::cout << "" << std::endl;
		return HUGE_VAL;
	}
}

double UMinusNode::Calc() const
{
	return -childNode_->Calc();
}