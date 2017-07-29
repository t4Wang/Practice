/* Rectangle.h */
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Point.h"
#include "Shape.h"

#include <iostream>
#include <stdexcept>
using std::cout;
using std::endl;
using std::out_of_range;

class Rectangle: public Shape
{
public:
	Rectangle(const int &n = 0, const int &w = 10, const int &h = 10, const int &x = 0, const int &y = 0)
			:Shape(n, Point(x, y)), width(w), height(h){ if (w <=0 || h <= 0) throw out_of_range("长宽值不合法"); }
	int getArea() override { return width * height; }
	void print() const override { cout << "no:" << getNo() << " position:" << position << " width:" << width << " height:" << height << endl; }
private:
	int width;
	int height;
};

#endif
