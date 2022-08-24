#ifndef STRING_H
#define STRING_H

#include <iostream>

namespace Lib
{
    class String
    {
    public:
        String () {_size = 0; _capacity = 1;_str = new char[_capacity];
                    _str[_size] = '\0';};
        String (int);
        String (const char*);
        String (const String&);
        String (String&&);
        ~String ();
    public:
        String& operator = (const String&);
        String& operator = (String&&);
        String& operator = (const char*);
        String operator + (const String&);
        String& operator += (const String&);
    public:
        friend std::ostream& operator << (std::ostream&, const String&);
        void push_back (const char);
        void pop_back ();
        void shrink_to_fit ();
        size_t size ();
        size_t length ();
        size_t capacity ();
    private:
        void resize ();
        size_t _size;
        size_t _capacity;
        char* _str;
        
    };
    std::ostream& operator << (std::ostream& os, const String& rhs)
    {
        for (int i = 0; i < rhs._size; ++i)
        {
            os << rhs._str[i];
        }
        return os;
    }
}

#endif //STRING_H