#include "Node.h"
#include "Storage.h"
#include <cmath>
#include <cassert>
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

//double AddNode::Calc() const
//{
//	return leftNode_->Calc() + rightNode_->Calc();
//}
//
//double SubNode::Calc() const
//{
//	return leftNode_->Calc() - rightNode_->Calc();
//}
//
//double MultiplyNode::Calc() const
//{
//	return leftNode_->Calc() * rightNode_->Calc();
//}
//
//double DivideNode::Calc() const
//{
//	double divisor = rightNode_->Calc();
//	if (divisor != 0)
//	{
//		return leftNode_->Calc() / divisor;
//	}
//	else
//	{
//		std::cout << "" << std::endl;
//		return HUGE_VAL;
//	}
//}

double UMinusNode::Calc() const
{
	return -childNode_->Calc();
}

double FuncationNode::Calc() const
{
	return (*pFun_)(childNode_->Calc());
}

MultipleNode::MultipleNode(Node* node)
{
	AppendChild(node, true);
}

MultipleNode::~MultipleNode()
{
	std::vector<Node*>::const_iterator it;
	for (it = childs_.begin(); it != childs_.end(); ++it)
	{
		delete *it;
	}
}

void MultipleNode::AppendChild(Node* node, bool positive)
{
	childs_.push_back(node);
	positives_.push_back(positive);
}

double SumNode::Calc() const
{
	double result = 0.0;
	std::vector<Node*>::const_iterator childIt = childs_.begin();
	std::vector<bool>::const_iterator positiveIt = positives_.begin();
	for (; childIt != childs_.end(); ++childIt, ++positiveIt)
	{
		assert(positiveIt != positives_.end());
		double val = (*childIt)->Calc();
		if (*positiveIt)
		{
			result += val;
		} 
		else
		{
			result -= val;
		}
	}
	assert(positiveIt == positives_.end());
	return result;
}

double ProductNode::Calc() const
{
	double result = 1.0;
	std::vector<Node*>::const_iterator childIt = childs_.begin();
	std::vector<bool>::const_iterator positiveIt = positives_.begin();
	for (; childIt != childs_.end(); ++childIt, ++positiveIt)
	{
		assert(positiveIt != positives_.end());
		double val = (*childIt)->Calc();
		if (*positiveIt)
		{
			result *= val;
		}
		else if (val != 0.0)
		{
			result /= val;
		}
		else
		{
			std::cout << "Division by zero." << std::endl;
			return HUGE_VAL;
		}
	}
	assert(positiveIt == positives_.end());
	return result;
}

double VariableNode::Calc() const
{
	double x = 0.0;
	if (storage_.IsInit(id_))
	{
		x = storage_.GetValue(id_);
	}
	else
	{
		std::cout << "Use of uninitialized variable" << std::endl;
	}
	return x;
}

bool VariableNode::IsValue() const
{
	return true;
}
void VariableNode::Assign(double val)
{
	storage_.SetValue(id_, val);
}

double AssignNode::Calc() const
{
	double val = 0.0;
	val = rightNode_->Calc();
	leftNode_->Assign(val);
	return val;
}