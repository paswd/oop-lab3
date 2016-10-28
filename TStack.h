#ifndef TSTACK_H
#define TSTACK_H
#include "TStackItem.h"
#include <iostream>
#include <memory>

class TStack {
public:
	TStack();

	void push(std::shared_ptr<Figure> &&item);
	bool empty();
	std::shared_ptr<Figure> pop();
	friend std::ostream& operator<<(std::ostream& os,const TStack& stack);
	virtual ~TStack();
private:

	std::shared_ptr<TStackItem> head;
};
#endif /* TSTACK_H */
