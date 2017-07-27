/* 为下面的 Rectangle 和 Circle 类重写 getArea 虚函数。然后创建一个数组。 使用一个循环,生成 10 个
Rectangle、10 个 Circle,根据循环遍历顺序为它 们设置 no 编号,位置、长、宽、半径等其他信息取随机 1~10 之间的整数值,
然后将它们加入到创建好的数组中。最后,将这个长度为 20 的数组中所有面 积小于 50 的形状删除。将剩下的形状组成一个新的数组返回。



注意: 1. 补齐任务所需的其他函数。2. 考虑正确的内存管理。3. 使用原生数 组,不使用 vector 等容器。

*/
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

    Shape** shapes = new Shape*[SIZE];
    for (int i = 0; i < 10; i++) {
        // 生成一个Rectangle
        shapes[i] = new Rectangle(u(e), u(e), u(e), u(e), u(e));
        // 生成一个Circle
        shapes[i + 10] = new Circle(u(e), u(e), u(e), u(e));
    }
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


