#include <iostream>
#include "base1.h"
#include "derived1.h"
#include "deal.h"
using namespace std;

int main()
{
    Deal<Derived1> d1;
    Deal<Base1> b1(d1); // no matching function for call to 'Deal<Base1>::Deal(Deal<Derived1>&)'|
    return 0;
}
