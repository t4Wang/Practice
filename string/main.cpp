#include <iostream>
#include "String.h"
using namespace std;

int main()
{
    String s;
    s = String("666");
    String s1 = s;
    cout << s1.get_c_str();

    return 0;
}
