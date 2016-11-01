#ifndef _NODE_H_
#define _NODE_H_
#include <cassert>
#include <vector>
#include <memory>
#include "FuncationTable.h"

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
	BinaryNode(std::auto_ptr<Node>& left, std::auto_ptr<Node>& right) :
		leftNode_(left), rightNode_(right){}
	~BinaryNode();

protected:
	//Node* const leftNode_;
	//Node* const rightNode_;
	std::auto_ptr<Node> leftNode_;
	std::auto_ptr<Node> rightNode_;
};

class UnaryNode : public Node
{
public:
	UnaryNode(std::auto_ptr<Node>& child)
		: childNode_(child){}
	~UnaryNode();
protected:
	std::auto_ptr<Node> childNode_;
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
	AssignNode(std::auto_ptr<Node>& left, std::auto_ptr<Node>& right)
		:BinaryNode(left, right)
	{
		assert(leftNode_->IsValue());
	}
	double Calc() const;
	~AssignNode(){}
};

class UMinusNode : public UnaryNode
{
public:
	UMinusNode(std::auto_ptr<Node>& child)
		: UnaryNode(child){}
	double Calc() const;
	~UMinusNode(){}
};

class FuncationNode : public UnaryNode
{
public:
	FuncationNode(std::auto_ptr<Node>& child, PtrFun pFun)
		: UnaryNode(child), pFun_(pFun){}
	double Calc() const;
	~FuncationNode(){}

private:
	PtrFun pFun_;
};

class MultipleNode : public Node
{
public:
	MultipleNode(std::auto_ptr<Node>& node);
	~MultipleNode();
	void AppendChild(std::auto_ptr<Node>& node, bool psitive);

protected:
	std::vector<Node*> childs_;
	std::vector<bool> positives_;
};

class SumNode : public MultipleNode
{
public:
	SumNode(std::auto_ptr<Node>& node) : MultipleNode(node){}
	~SumNode(){}
	double Calc() const;

};

class ProductNode : public MultipleNode
{
public:
	ProductNode(std::auto_ptr<Node>& node) : MultipleNode(node){}
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

