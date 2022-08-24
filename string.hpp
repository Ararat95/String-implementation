#include "string.h"
Lib::String::String (int capacity)
{
    _capacity = capacity;
    _size = 0;
    _str = new char[_capacity];
    _str[_size] = '\0';
}

Lib::String::String (const char* rhs)
{
    _size = 0;
    _capacity = 1;
    _str = new char [_capacity];
    for (int i = 0; rhs[i] != '\0'; ++i)
    {
        _str[i] = rhs[i];
        ++_size;
        if (_size >= _capacity)
        {
            resize();
        }
    }
    _str[_size] = '\0';
}

Lib::String::String (const String& rhs)
{
    _size = rhs._size;
    _capacity = rhs._capacity;
    if (rhs._size == 0)
    {
        _str[0] = '\0';
    }
    else
    {
        _str = new char[_capacity];
        for (int i = 0; i < _size; ++i)
        {
            _str[i] = rhs._str[i];
        }
        _str[_size] = '\0';
    }
}
Lib::String::String (String &&rhs)
{
    _size = rhs._size;
    _capacity = rhs._capacity;
    _str = rhs._str;
    rhs._str = nullptr;
    rhs._size = 0;
    rhs._capacity = 0;
}
Lib::String::~String()
{
    delete[] _str;
}
Lib::String& Lib::String::operator = (const String &rhs)
{
    _size = rhs._size;
    _capacity = rhs._capacity;
    if (*(rhs._str) == '\0')
    {
        *_str = '\0';
    }
    else
    {
        delete[] _str;
        _str = new char[_capacity];
        for (int i = 0; i < _size; ++i)
        {
            _str[i] = rhs._str[i];
        }
    }
    return *this;
}
Lib::String& Lib::String::operator = (String &&rhs)
{
    _size = rhs._size;
    _capacity = rhs._capacity;
    delete[] _str;
    _str = rhs._str;
    rhs._str = nullptr;
    rhs._size = 0;
    rhs._capacity = 0;

    return *this;
}

Lib::String& Lib::String::operator = (const char* rhs)
{
    for (int i = 0; rhs[i] != '\0'; ++i)
    {
        _str[i] = rhs[i];
        ++_size;
        if (_size >= _capacity)
        {
            resize();
        }
    }
    _str[_size] = '\0';
    return *this;
}

Lib::String& Lib::String::operator += (const String &rhs)
{
    int i = _size;
    _size += rhs._size;
    if (_size >= _capacity)
    {
        do
        {
            resize();
        } while (_capacity <= _size);
    }
    for (int j = 0; j <= rhs._size; ++i, ++j)
    {
        _str[i] = rhs._str[j];
    }
    return *this;
}
void Lib::String::resize ()
{
    if (_str == nullptr)
    {
        _capacity = 1;
        _str = new char[_capacity];
        _str[_size] = '\0';
    }
    else
    {
        _capacity *= 2;
        char *tmp = new char[_capacity];
        for (int i = 0; i < _size; ++i)
        {
            tmp[i] = _str[i];
        }
        delete[] _str;
        _str = tmp;
        _str[_size] = '\0';
        tmp = nullptr;
    }
}
Lib::String Lib::String::operator + (const String &rhs)
{
    Lib::String tmp(_capacity + rhs._capacity);
    tmp._size = _size + rhs._size;
    for (int i = 0, j = 0, y = 0; i < tmp._size; ++i, ++j)
    {
        if (j < _size)
        {
            tmp._str[i] = _str[j];
        }
        else
        {
            tmp._str[i] = rhs._str[y];
            ++y;
        }
    }
    return tmp;
}
size_t Lib::String::length ()
{
    return _size;
}
size_t Lib::String::size ()
{
    return _size;
}
void Lib::String::push_back (const char chr)
{
    if ((_size) >= _capacity)
    {
        resize();
    }
    _str[_size] = chr;
    ++_size;
    _str[_size] = '\0';
}
void Lib::String::pop_back ()
{
    if (_size == 0 || _str == nullptr)
    {
        return;
    }
    --_size;
    _str[_size] = '\0';
}
void Lib::String::shrink_to_fit ()
{
    if (_size == 0 || _str == nullptr)
    {
        return;
    }
    char* tmp = new char[_size];
    for (int i = 0; i < _size; ++i)
    {
        tmp[i] = _str[i];
    }
    delete[] _str;
    _str = tmp;
    tmp = nullptr;
}

size_t Lib::String::capacity ()
{
    return _capacity;
}