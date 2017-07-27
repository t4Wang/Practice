/* Rectangle.h */
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Point.h"
#include "Shape.h"

#include <iostream>
using std::cout;
using std::endl;

class Rectangle: public Shape
{
public:
	Rectangle(const int &n = 0, const int &w = 10, const int &h = 10, const int &x = 0, const int &y = 0)
			:Shape(n, Point(x, y)), width(w), height(h){ /* 如果值不合理就抛异常 */ }
	int getArea() override { return width * height; }
	void print() override { cout << "no:" << getNo() << " position:" << position << " width:" << width << " height:" << height << endl; }
private:
	int width;
	int height;
};

#endif
