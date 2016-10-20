#ifndef _NODE_H_
#define _NODE_H_

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

class AddNode : public BinaryNode
{
public:
	AddNode(Node* left, Node* right)
		:BinaryNode(left, right){}
	double Calc() const;
	~AddNode(){}
};

class SubNode : public BinaryNode
{
public:
	SubNode(Node* left, Node* right)
		:BinaryNode(left, right){}
	double Calc() const;
	~SubNode(){}
};

class MultiplyNode : public BinaryNode
{
public:
	MultiplyNode(Node* left, Node* right)
		:BinaryNode(left, right){}
	double Calc() const;
	~MultiplyNode(){}
};

class DivideNode : public BinaryNode
{
public:
	DivideNode(Node* left, Node* right)
		:BinaryNode(left, right){}
	double Calc() const;
	~DivideNode(){}
};

class UMinusNode : public UnaryNode
{
public:
	UMinusNode(Node* child)
		: UnaryNode(child){}
	double Calc() const;
	~UMinusNode(){}
};
#endif

