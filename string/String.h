#ifndef SRTING_H
#define STRING_H

#include "str.h"

class String {
public:
	String(const char *cstr = 0):m_str(new str(cstr)) {}
	String(const String &other):m_str(new str(*other.m_str)) {}
	String &operator=(const String&);
	~String() { delete m_str; }
	const char* get_c_str() const { return m_str->get_c_str(); }
private:
	str *m_str;
};

inline
String& String::operator=(const String &rhs) {
	if (this == &rhs) return *this;

	delete m_str;
	m_str = new str(*rhs.m_str);

	return *this;
}

#endif
