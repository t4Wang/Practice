#ifndef STR_H
#define STR_H

class str
{
    public:
        str(const char* cstr = 0);
        virtual ~str();
        str(const str& other);
        str& operator=(const str& other);
        const char* get_c_str() const { return m_data; }
    private:
        char* m_data;
};

#endif // STR_H
