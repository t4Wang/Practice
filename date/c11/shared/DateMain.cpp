 
/*
 * filename: DateMain.cpp
 */
#include "Date.h"
#include <iostream>
using namespace std;
 
int main() {
    auto dates = CreatePoints();
    for (int i = 0; i < 10; i++) {
        dates[0].print();
    }
    cout << "-------------" << endl;
     
    dates = Sort(dates);
    for (int i = 0; i < 10; i++) {
        dates[0].print();
    }
}