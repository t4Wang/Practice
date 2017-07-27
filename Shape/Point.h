/* Point.h */
#ifndef POINT_H
#define POINT_H

#include <iostream>
using std::ostream;

class Point {
	friend ostream &operator<<(ostream &os, const Point &p);
private:
	int x, y;
public:
	Point(const int &x = 0, const int &y = 0):x(x), y(y) {}
};

inline ostream&
operator<<(ostream &os, const Point &p) {
	return os << "(" << p.x << "," << p.y << ")";
}

#endif