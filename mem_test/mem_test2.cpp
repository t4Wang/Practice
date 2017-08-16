#include <iostream>
#include <malloc.h>
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
   ~Apple() { cout << "Apple destructor" << endl; }
   void save() {   }
   virtual void process(){   }
   void* operator new(size_t size) {
      Apple* pa = (Apple*) malloc(size);
      cout << "new apple" << endl;
      return pa;
   }
   void operator delete(void* pdead, size_t size) {
      cout << "delete apple" << endl;
      free(pdead);
   }
};

int main() {
	//Fruit f;
	//Apple a;

   Fruit *pf = new Apple();
   delete pf;
}

/*
Fruit constructor
Fruit constructor
Apple constructor
Apple destructor
Fruit destructor
Fruit destructor
*/

/*
new apple
Fruit constructor
Apple constructor
Fruit destructor
*/
