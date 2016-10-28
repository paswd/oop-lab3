#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <cstdlib>
#include <iostream>
#include "figure.h"
#include "geometry.h"

class Rectangle : public Figure {
public:
	Rectangle();
	Rectangle(std::istream &is);
	Rectangle(Position in_pos, double len_a, double len_b);
	Rectangle(const Rectangle &orig);
	double Square() override;
	//void Print() override;
	virtual ~Rectangle();
	std::ostream& toStream(std::ostream& os) override;
	friend std::ostream& operator<<(std::ostream& os, const Rectangle& obj);
	friend std::istream& operator>>(std::istream& is, Rectangle& obj);
private:
	Position pos;
	double LenA;
	double LenB;
};

#endif /* RECTANGLE_H */
