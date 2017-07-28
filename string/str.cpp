#include "str.h"
#include <cstring>

str::str(const char *cstr)
{
    if (cstr) {
		m_data = new char[strlen(cstr) + 1];	// 先分配空间
		strcpy(m_data, cstr);               // 将内容拷贝进来
	} else {
		m_data = new char[1];
		m_data[0] = '\0';
	}
}

str::~str()
{
    delete[] m_data;
}

str::str(const str& other)
{
    m_data = new char[strlen(other.m_data) + 1];
    strcpy(m_data, other.m_data);
}

str& str::operator=(const str& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    delete[] m_data;
	m_data = new char[strlen(rhs.m_data) + 1];
	strcpy(m_data, rhs.m_data);

    return *this;
}
