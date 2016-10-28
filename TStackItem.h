#ifndef TSTACKITEM_H
#define TSTACKITEM_H
#include <memory>
#include "figure.h"

/*typedef enum {
	SQUARE,
	TRAPEZE,
	RECTANGLE
} Type;

class Item {
public:
	Type type;
	FSquare square;
	Trapeze trapeze;
	Rectangle rectangle;

	bool IsEmpty;
	friend std::ostream& operator<<(std::ostream& os, const Item& obj);
};*/

class TStackItem {
public:
	TStackItem(const std::shared_ptr<Figure>& Item);
	friend std::ostream& operator<<(std::ostream& os, const TStackItem& obj);

	std::shared_ptr<TStackItem> SetNext(std::shared_ptr<TStackItem> &next);
	std::shared_ptr<TStackItem> GetNext();
	std::shared_ptr<Figure> GetItem() const;
	virtual ~TStackItem();
private:
	std::shared_ptr<Figure> item;
	std::shared_ptr<TStackItem> next;
};
#endif /* TSTACKITEM_H */
