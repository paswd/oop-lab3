#include <iostream>
#include <cstdlib>
#include "figure.h"
#include "stack.h"
#include "square.h"
#include "trapeze.h"
#include "rectangle.h"
#include <memory>


Figure GetEmptyFigure(void)
{
	Position empty_pos;
	empty_pos.x = 0;
	empty_pos.y = 0;
	Figure *empty_href = new FSquare(empty_pos, -1.0);
	Figure empty = *empty_href;
	delete empty_href;
	Figure empty;
	empty.IsEmpty = true;
	return empty;
}

StackNode::StackNode(void)
{
	this->value = GetEmptyFigure();
	this->next = NULL;
}

std::shared_ptr<StackNode> StackNode::GetNext(void)
{
	return this->next;
}

std::ostream& operator<<(std::ostream& os, const StackNode& node)
{
	os << node.value;
	return os;
}


Stack::Stack(void)
{
	this->top = NULL;
}

Stack::~Stack(void)
{
	std::shared_ptr<StackNode> node_del = this->top;
	while (node_del) {
		std::shared_ptr<StackNode> tmp = node_del->next;
		delete node_del;
		node_del = tmp;
	}
}


void Stack::Push(std::shared_ptr<Figure> &&figure)
{
	std::shared_ptr<StackNode> nw = new StackNode();
	nw->value = value;
	nw->next = this->top;
	this->top = nw;
}

std::shared_ptr<Figure> Stack::Pop(void)
{
	if (this->IsEmpty()) {
		printf("Stack is empty\n");
		return GetEmptyFigure();
	}
	std::shared_ptr<StackNode> result = this->top->value;
	std::shared_ptr<StackNode> node_del = this->top;
	this->top = this->top->next;
	delete node_del;
	return result;
}

Item Stack::Top(void)
{
	if (this->IsEmpty())
		return GetEmptyFigure();
	return this->top->value;
}

bool Stack::IsEmpty(void)
{
	if (this->top == NULL)
		return true;
	return false;
}

size_t Stack::Depth(void)
{
	if (this->IsEmpty())
		return 0;

	Item value = this->Pop();
	int res = this->Depth();
	this->Push(value);
	return res + 1;
}

/*void Stack::Print(void)
{
	if (this->IsEmpty())
		return;
	Item value = this->Pop();
	this->Print();
	value.Print();
	this->Push(value);
}*/

std::ostream& operator<<(std::ostream& os,const Stack& stack)
{
	//os << "Test" << std::endl;
	std::shared_ptr<StackNode> ths = stack.top;
	size_t cnt = 0;
	while (ths != NULL) {
		if (cnt > 0) {
			std::cout << "-------------------------------" << std::endl;
		}
		os << *ths;
		ths = ths->GetNext();
		cnt++;
	}
	return os;
}

