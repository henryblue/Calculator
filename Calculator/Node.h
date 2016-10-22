#ifndef _NODE_H_
#define _NODE_H_
#include "FuncationTable.h"
#include <vector>
#include <cassert>

class Storage;

class Noncopyable {
protected:
	Noncopyable(){}
	~Noncopyable(){}
private:
	Noncopyable(const Noncopyable&);
	const Noncopyable& operator=(const Noncopyable&);
};

class Node : private Noncopyable
{
public:
	Node(){}
	virtual double Calc() const = 0;
	virtual bool IsValue() const   //ÊÇ·ñÊÇ×óÖµ
	{
		return false;
	}
	virtual void Assign(double val)
	{
		assert(!"Assign called incorrectlly");
	}
	virtual ~Node(){}
};

class NumberNode : public Node {
public:
	NumberNode(double number) : number_(number){}
	double Calc() const;
	~NumberNode(){}

private:
	const double number_;
};

class BinaryNode : public Node
{
public:
	BinaryNode(Node* left, Node* right) :
		leftNode_(left), rightNode_(right){}
	~BinaryNode();

protected:
	Node* const leftNode_;
	Node* const rightNode_;
};

class UnaryNode : public Node
{
public:
	UnaryNode(Node* child) 
		: childNode_(child){}
	~UnaryNode();
protected:
	Node* const childNode_;
};

//class AddNode : public BinaryNode
//{
//public:
//	AddNode(Node* left, Node* right)
//		:BinaryNode(left, right){}
//	double Calc() const;
//	~AddNode(){}
//};
//
//class SubNode : public BinaryNode
//{
//public:
//	SubNode(Node* left, Node* right)
//		:BinaryNode(left, right){}
//	double Calc() const;
//	~SubNode(){}
//};
//
//class MultiplyNode : public BinaryNode
//{
//public:
//	MultiplyNode(Node* left, Node* right)
//		:BinaryNode(left, right){}
//	double Calc() const;
//	~MultiplyNode(){}
//};
//
//class DivideNode : public BinaryNode
//{
//public:
//	DivideNode(Node* left, Node* right)
//		:BinaryNode(left, right){}
//	double Calc() const;
//	~DivideNode(){}
//};

class AssignNode : public BinaryNode
{
public:
	AssignNode(Node* left, Node* right)
		:BinaryNode(left, right)
	{
		assert(left->IsValue());
	}
	double Calc() const;
	~AssignNode(){}
};

class UMinusNode : public UnaryNode
{
public:
	UMinusNode(Node* child)
		: UnaryNode(child){}
	double Calc() const;
	~UMinusNode(){}
};

class FuncationNode : public UnaryNode
{
public:
	FuncationNode(Node* child, PtrFun pFun)
		: UnaryNode(child), pFun_(pFun){}
	double Calc() const;
	~FuncationNode(){}

private:
	PtrFun pFun_;
};

class MultipleNode : public Node
{
public:
	MultipleNode(Node* node);
	~MultipleNode();
	void AppendChild(Node* node, bool psitive);

protected:
	std::vector<Node*> childs_;
	std::vector<bool> positives_;
};

class SumNode : public MultipleNode
{
public:
	SumNode(Node* node) : MultipleNode(node){}
	~SumNode(){}
	double Calc() const;

};

class ProductNode : public MultipleNode
{
public:
	ProductNode(Node* node) : MultipleNode(node){}
	~ProductNode(){}
	double Calc() const;

};

class VariableNode : public Node
{
public:
	VariableNode(unsigned int id, Storage& storage) :
		id_(id), storage_(storage){}
	~VariableNode(){}
	double Calc() const;
	bool IsValue() const;
	void Assign(double val);
private:
	const unsigned int id_;
	Storage& storage_;
};

#endif

