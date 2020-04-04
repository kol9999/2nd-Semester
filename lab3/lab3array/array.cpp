
#include"array.h"
#include <cmath>

using namespace std;



///Bapiant 6

Array::Array()
{
    size = 0;
}

Array::Array(int size)
{
    this->size = size;
    array = new int[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = 0;
    }
}

Array::Array(Array const& prevArray)
{
    size = prevArray.getSize();
    array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = prevArray.array[i];
    }
}

int Array::getSize() const
{
    return size;
}

int& Array::operator [] (int idx)
{
    if (idx < size && idx >= 0)
        return array[idx];
}

Array Array::operator + (Array array2)
{
    Array newArray(size + array2.getSize());
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }
    for (int i = 0; i < array2.getSize(); i++)
    {
        newArray[i + size] = array2[i];
    }
    return Array(newArray);
}

bool Array::operator==(const Array& array2) const
{
    return size == array2.getSize();
}

bool Array::operator>(const Array& array2) const
{
    return size > array2.getSize();
}

bool Array::operator<(const Array& array2) const
{
    return size < array2.getSize();
}

bool Array::operator!=(const Array& array2) const
{
    return size != array2.getSize();
}

Array::operator string()
{
    string result = "[";
    for (int i = 0; i < size - 1; i++) {
        result += to_string(array[i]) + ", ";
    }
    result += to_string(array[size - 1]) + "]";
    return result;
}
