#include <iostream>
using std::cout;
using std::endl;
class A {
	int i1;
	const int ci2;
public:
	A():i1(1), ci2(2) {}
	void a1(const int& arg) { cout << arg << endl; }
	// void a2(const int& arg) { arg = 5; }	// assignment of read-only reference 'arg'
	const int& b1() { return i1; }
	const int& b2() { return ci2; }
	// void c1() const { cout << "const" << endl; }
	void c1() { cout << "non-const" << endl; }
	// void c2() const { i1 = 5; }				// assignment of member 'A::i1' in read-only object
};

int main() {
	A a;
	int i = 1;
	a.a1(i);
	i = 2;
	a.a1(i);
	// a.a2(2);

	int i1 = a.b1();
	int i2 = a.b2();		// 非const变量i2可以接收了const int类型的返回值
	// int& i3 = a.b1();		// 报错binding 'const int' to reference of type 'int&' discards qualifiers
	const int i4 = a.b1();	// i4可以接收了非const的函数返回值
	const int& i5 = a.b1();	// 
	const int& i6 = a.b1();

	cout << i1 << endl;
	cout << i2 << endl;
	i2 = 1;
	cout << i2 << endl;		// 1
	cout << a.b2() << endl;	// 2 虽然返回的是const引用，但是i2改变并没有改变a对象内部ci2的值,i2改变也没有
	// cout << i3 << endl;
	cout << i4 << endl;
	cout << i5 << endl;
	cout << i6 << endl;

	a.c1();
	// a.c2();
	const A b;
	b.c1();
}
