/* File: ShapeFactory.h */
#include <iostream>
#include <random>
#include <memory>
#include "Point.h"
#include "Shape.h"

const int SIZE = 20;
class ShapeFactory {
private:
	Shape* shapes[SIZE];
	create();
	filter();
public:
	ShapeFactory();
	ShapeFactory(const ShapeFactory&);
	ShapeFactory &operator=(const ShapeFactory&);
	~ShapeFactory();
	const Shape** getShapes() const;
}
inline
ShapeFactory::ShapeFactory():shapes(new Shape[SIZE]) {
	create();
	filter();
}
inline
ShapeFactory::ShapeFactory(const ShapeFactory &s) {
	shapes = new Shape[SIZE];
	for (auto iter = begin(shapes), r_iter = begin(s); iter != end(shapes); ++iter, ++r_iter) {
		*iter = new Shape(**r_iter);
	}
}
inline ShapeFactory&
ShapeFactory::operator=(const ShapeFactory &right) {
	if (this == &sf) return *this;

	// 删除左侧操作数
	for (auto iter = begin(shapes); iter != end(shapes); ++iter) {
		delete *iter;
	}
	delete[] shapes;

	// 右操作数赋值给左边
	shapes = new Shape[SIZE];
	for (auto iter = begin(shapes), r_iter = begin(right.shapes); iter != end(shapes); ++iter, ++r_iter) {
		*iter = new Shape(**r_iter);
	}

	return *this;
}

// 用于存储随机图形的数组
// 创建图形
inline void
ShapeFactory:: create() {
    // 随机数引擎
    static default_random_engine e;
    static uniform_int_distribution<unsigned> u(1, 10);

    for (int i = 0; i < 10; i++) {
        // 生成一个Rectangle
        shapes[i] = new Rectangle(u(e), u(e), u(e), u(e), u(e));
        // 生成一个Circle
        shapes[i + 10] = new Circle(u(e), u(e), u(e), u(e));
    }
}

// 过滤所有面积小于 50 的图形
inline void
ShapeFactory:: filter() {
	for (auto iter = begin(shapes); iter != end(shapes); ++iter) {
		if (*iter->getArea() < 50) *iter = nullptr;
	}
}
