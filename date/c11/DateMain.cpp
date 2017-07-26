 
/*
 * filename: DateMain.cpp
 */
#include "Date.h"
#include <iostream>
using namespace std;
 
int main() {
    CreatePoints();
    for (auto d: dates) {
        d.print();
    }
    cout << "-------------" << endl;
     
    Sort();
    for (auto d: dates) {
        d.print();
    }
}