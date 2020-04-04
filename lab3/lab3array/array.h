#pragma once
#include <string>
#include <fstream>
using namespace std;


/// Bapiant 6
class Array {
private:
    int* array;
    int size;
public:
    Array();
    Array(int size);
    Array(Array const& prevArray);
    int getSize() const;
    int& operator [] (int idx);
    Array operator + (Array array2);
    bool operator == (const Array& array2) const;
    bool operator > (const Array& array2) const;
    bool operator < (const Array& array2) const;
    bool operator != (const Array& array2) const;
    operator string();
};

