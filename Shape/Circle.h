/* Circle.h */

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"
#include "Shape.h"

#include <iostream>
#include <stdexcept>
using std::cout;
using std::endl;
using std::out_of_range;

const double PI = 3.14159265358979323846;

class Circle: public Shape
{
public:
	Circle(const int &n = 0, const int &r = 1, const int &x = 0, const int &y = 0): Shape(n, Point(x, y)), radius(r) { if (r <= 0) throw out_of_range("°ë¾¶²»ºÏ·¨"); }
	int getArea() override { return radius * radius * PI / 2; }
	void print() const override { cout << "no:" << getNo() << " position:" << position << " radius:" << radius << endl; }
private:
	int radius;		// °ë¾¶
};

#endif
