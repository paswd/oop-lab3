#include "TStack.h"

TStack::TStack() : head(NULL) {
}
std::ostream& operator<<(std::ostream& os, const TStack& stack) {
	std::shared_ptr<TStackItem> item = stack.head;

	while(item != NULL) {
		os << *item;
		item = item->GetNext();
	}

	return os;
}
void TStack::push(std::shared_ptr<Figure> &&item) {
	std::shared_ptr<TStackItem> other(new TStackItem(item));
	other->SetNext(head);
	head = other;
}
bool TStack::empty() {
	return head == NULL;
}
std::shared_ptr<Figure> TStack::pop() {
	std::shared_ptr<Figure> result;
	if (head != NULL) {
		result = head->GetItem();
		head = head->GetNext();
	}
	return result;
}
TStack::~TStack() {

}
