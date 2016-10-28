#ifndef _STACK_H_
#define _STACK_H_

#include "figure.h"
#include "square.h"
#include "rectangle.h"
#include "trapeze.h"
#include <memory>


typedef FSquare Item;


//FSquare GetEmptyFSquare(void);

Figure GetEmptyFigure(void);

class StackNode {
public:
	Item value;
	//StackNode *next;
	std::shared_ptr<StackNode> next;

	StackNode(void);
	std::shared_ptr<StackNode> GetNext(void);
	friend std::ostream& operator<<(std::ostream& os, const StackNode& node);
};

class Stack {
private:
	//StackNode *top;
	std::shared_ptr<StackNode> top;
public:
	Stack(void);
	~Stack(void);

	//void Push(Item value);
	void Push(std::shared_ptr<Figure> &&figure);
	std::shared_ptr<Figure> Pop(void);
	Item Top(void);
	bool IsEmpty(void);
	size_t Depth(void);
	//void Print(void);
	friend std::ostream& operator<<(std::ostream& os,const Stack& stack);
};

#endif
