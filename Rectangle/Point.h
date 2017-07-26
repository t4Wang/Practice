/* Point.h */
#ifndef POINT_H
#define POINT_H

class Point {
	int x, y;
public:
	Point() = default;
	Point(const int &x = 0, const int &y = 0):x(x), y(y){}
};

#endif