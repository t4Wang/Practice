#include "String.h"
#include <iostream>
using namespace std;

inline
String:: String(const char *cstr) {
	if (cstr) {
		m_data = new char[len(cstr) + 1];	// 先分配空间
		strcpy(m_data, cstr)// 将内容拷贝进来
	} else {
		m_data = new char[1];
		m_data[0] = '\0'
	}
}

inline
String:: String(const String &str) {
	// if (str) {
		m_data = new char[len(str.m_data) + 1];
		strcpy(m_data, str.m_data);
	// }
}

inline
String& String::operator=(const String &rhs) {
	if (this == &rhs) return *this;

	delete[] m_data;
	m_data = new char[len(rhs.m_data) + 1];
	strcpy(m_data, rhs.m_data);

	return *this;
}

inline
String:: ~String() {
	delete[] m_data;
}

inline
ostream& operator<< (ostream &os, const String &str) {
	return os << str.get_c_str();
}
