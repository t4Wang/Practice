/*
	static
*/
#include <iostream>
using namespace std;

class Static_test {
	int a;
	static int b;
public:
	int getB() { return b; }
};

int main() {
	Static_test s;
	cout << s.getB() << endl;
	return 0;
}
