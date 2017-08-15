#include <iostream>
using namespace std;

class Fruit{
   int no;
   double weight;
   char key;
public:
   Fruit() { cout << "Fruit constructor" << endl; }
   ~Fruit() { cout << "Fruit destructor" << endl; }
   void print() {   }
   virtual void process(){   }
};
   
class Apple: public Fruit{
   int size;
   char type;
public:
   Apple() { cout << "Apple constructor" << endl; }
   Apple() { cout << "Apple destructor" << endl; }
   void save() {   }
   virtual void process(){   }
   Apple& operator new(size_t size) {
      cout << "new apple" << endl;
   }
   Apple& operator delete() {
      cout << "delete apple" << endl;
   }
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