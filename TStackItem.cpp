#include "TStackItem.h"
#include <iostream>


/*std::ostream& operator<<(std::ostream& os, const Item& obj) {
	if (*obj.IsEmpty) {
		os << "Stack is empty" << std::endl;
		return os;
	}
	switch(*obj.type) {
		case SQUARE:
			os << *obj.square;
			break;
		case TRAPEZE:
			os << *obj.trapeze;
			break;
		case RECTANGLE:
			os << *obj.rectangle;
			break;
	}
	os << std::endl;
	//os << "[" << *obj.item << "]" << std::endl;
	return os;
}*/


TStackItem::TStackItem(const std::shared_ptr<Figure>& item) {
	this->item = item;
	this->next = NULL;
	std::cout << "Stack item: created" << std::endl;
}
std::shared_ptr<TStackItem> TStackItem::SetNext(std::shared_ptr<TStackItem>
&next) {
	std::shared_ptr<TStackItem> old = this->next;
	this->next = next;
	return old;
}
std::shared_ptr<Figure> TStackItem::GetItem() const {
	return this->item;
}
std::shared_ptr<TStackItem> TStackItem::GetNext() {
	return this->next;
}
TStackItem::~TStackItem() {
	std::cout << "Stack item: deleted" << std::endl;
}
std::ostream& operator<<(std::ostream& os, const TStackItem& obj) {
	os << "[" << *obj.item << "]" << std::endl;
	return os;
}
