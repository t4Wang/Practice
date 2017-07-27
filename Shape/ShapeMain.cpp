/* Ϊ����� Rectangle �� Circle ����д getArea �麯����Ȼ�󴴽�һ�����顣 ʹ��һ��ѭ��,���� 10 ��
Rectangle��10 �� Circle,����ѭ������˳��Ϊ�� ������ no ���,λ�á��������뾶��������Ϣȡ��� 1~10 ֮�������ֵ,
Ȼ�����Ǽ��뵽�����õ������С����,���������Ϊ 20 �������������� ��С�� 50 ����״ɾ������ʣ�µ���״���һ���µ����鷵�ء�



ע��: 1. �����������������������2. ������ȷ���ڴ����3. ʹ��ԭ���� ��,��ʹ�� vector ��������

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
    // ���������
    static default_random_engine e;
    static uniform_int_distribution<unsigned> u(1, 10);

    Shape** shapes = new Shape*[SIZE];
    for (int i = 0; i < 10; i++) {
        // ����һ��Rectangle
        shapes[i] = new Rectangle(i, u(e), u(e), u(e), u(e));
        // ����һ��Circle
        shapes[i + 10] = new Circle(i +10, u(e), u(e), u(e));
    }

    return shapes;
}

// �����������С�� 50 ��ͼ��
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


