#ifndef FIGURE_H
#define FIGURE_H

class Figure {
public:
	virtual double Square() = 0;
	//virtual void Print() = 0;
	virtual ~Figure() {};
	virtual std::ostream& toStream(std::ostream& os) = 0;
};

std::ostream& operator<<(std::ostream& os, Figure& obj);


#endif /* FIGURE_H */
