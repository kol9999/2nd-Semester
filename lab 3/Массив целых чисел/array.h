#pragma once
#include <string>

class Array {
private:
    int* array;
    int size;
public:
    Array();
    explicit Array(int size);
    Array(Array const &arr);
    ~Array();
    int getSize() const;
    int& operator[](int idx);
    Array operator + (Array array2);
    bool operator == (const Array& array2);
    bool operator > (const Array& array2);
    bool operator < (const Array& array2);
    bool operator != (const Array& array2);
    explicit operator std::string();
};