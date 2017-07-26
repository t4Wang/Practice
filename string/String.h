#ifndef SRTING_H
#define STRING_H

class String {
public:
	String(const char *cstr = 0);
	String(const String&);
	String &operator=(const String&);
	~String();
	char* get_c_str() const { return m_data; }
private:
	char* m_data;
}

#endif
