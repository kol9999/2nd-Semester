#pragma once

#include <iostream>

template <class T>
class Array {
public:
    explicit Array(int s);
    ~Array();

    void insertElement(int position, T element);
    T getElement(int position);
private:
    int size;
    T *arr;
};