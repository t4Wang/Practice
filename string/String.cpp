#include "String.h"
#include "str.h"
#include <iostream>
using std::ostream;



inline
ostream& operator<< (ostream &os, const String &s) {
	return os << s.get_c_str();
}
