/*
win10 64位系统
Fruit: 4 + 8 + 1 + 16 =  29byte--向上取8的整数倍--32byte
Apple: 32 + 4 + 1 = 37 byte--向上取8的整数倍--40byte

*/
#include <iostream>
using namespace std;

class Fruit{
   int no;
   double weight;
   char key;
public:
   void print() {   }
   virtual void process(){   }
};
   
class Apple: public Fruit{
   int size;
   char type;
public:
   void save() {   }
   virtual void process(){   }
};

int main() {
	Fruit f;
	Apple a;
	cout << "int" << sizeof(int) << endl;
	cout << "double" << sizeof(double) << endl;
	cout << "char" << sizeof(char) << endl;
	cout << "method" << sizeof(&a.process) << endl;
	cout << sizeof(f) << endl;		// 32
	cout << sizeof(a) << endl;		// 40
}

