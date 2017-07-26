/* Rectangle.h */
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Point.h"
#include "Shape.h"
#include <iostream>
#include <memory>
using namespace std;

class Rectangle: public Shape
{
public:
	Rectangle(const int&, const int&, const int&, const int&);
private:
	int width;
	int height;
	Point leftUp;
};

inline
Rectangle::Rectangle(const int &w, const int &h, const int &x, const int &y):leftUp(make_shared<Point>(x, y)), width(w), height(h){}

#endif