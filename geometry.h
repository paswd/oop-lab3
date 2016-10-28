#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <iostream>
#include <cstdlib>

class Position {
public:
	double x;
	double y;

	void Input(std::istream &is);
	//void Print();

	friend std::ostream& operator<<(std::ostream& os, const Position& pos);
	friend std::istream& operator>>(std::istream& is, Position& obj);
};

double Absolute(double num);


#endif /* GEOMETRY_H */
