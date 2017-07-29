/* Shape.h */

#ifndef SHAPE_H
#define SHAPE_H

#include "Point.h"
#include <iostream>
using std::cout;

class Shape
{
private:
	int no;
protected:
	Point position;
public:
	Shape(const int &n = 0, const Point &p = Point(0, 0)):no(n), position(p) {}
	virtual int getArea() = 0;
	virtual const Point getPosition() const { return position; }
	virtual const int getNo() const { return no; }
	virtual void print() const { cout << no; }
	virtual ~Shape() {}
};

#endif
