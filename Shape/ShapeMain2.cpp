#include <random>
#include <memory>
#include "Point.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
using std::default_random_engine;
using std::uniform_int_distribution;

const int SIZE = 20;

inline Shape**
Create() {
    // 随机数引擎
    static default_random_engine e;
    static uniform_int_distribution<unsigned> u(1, 10);

//  Shape** shapes = new Shape*[SIZE];
//    allocator<Shape*> alloc_ptr;
//    auto ptr_shapes = alloc_ptr.allocate(SIZE);
    Shape** shapes = new Shape*[SIZE];
//    allocator<Shape> alloc;
    shapes = alloc.allocate(SIZE)

    for (int i = 0; i < 10; i++) {
        // 生成一个Rectangle
        alloc.construct(shapes[i], new Rectangle(i, u(e), u(e), u(e), u(e)));
        // 生成一个Circle
        alloc.construct(shapes[i + 10], new Circle(i +10, u(e), u(e), u(e));
    }

    return shapes;
}

// 过滤所有面积小于 50 的图形
inline void
Filter(Shape **shapes) {
    for (int i = 0; i < SIZE; ++i) {
        if (shapes[i]->getArea() < 50) shapes[i] = nullptr;
    }
}


int main() {
    auto shapes = Create();
    Filter(shapes);

    for (int i = 0; i < SIZE; ++i) {
        if (shapes[i])
            shapes[i]->print();
    }
    for (int i = 0; i < SIZE; ++i) {
        if (shapes[i])
            delete shapes[i];
    }
    delete[] shapes;
}



