#include "array.h"
#include <iostream>

Array::Array() {
    size = 0;
}

Array::Array(int size) {
    this->size = size;
    array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = 0;
    }
}

Array::Array(Array const &arr) {
    size = arr.getSize();
    array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = arr.array[i];
    }
}

Array::~Array() {
    delete[] array;
}

int Array::getSize() const {
    return size;
}

int &Array::operator[](int idx) {
    if (idx < size && idx >= 0)
        return array[idx];
    else
        std::cout << "Error: more than 100";
}

Array Array::operator+(Array array2) {
    if (size + array2.getSize() > 100)
        std::cout << "Array length more than 100";
    Array newArray(size + array2.getSize());
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }
    for (int i = 0; i < array2.getSize(); i++) {
        newArray[i + size] = array2[i];
    }
    return Array(newArray);
}

bool Array::operator==(const Array &array2) {
    return size == array2.getSize();
}

bool Array::operator!=(const Array &array2) {
    return size != array2.getSize();
}

bool Array::operator<(const Array &array2) {
    return size < array2.getSize();
}

bool Array::operator>(const Array &array2) {
    return size > array2.getSize();
}

Array::operator std::string() {
    std::string result = "[";
    for (int i = 0; i < size - 1; i++) {
        result += std::to_string(array[i]) + ",";
    }
    result += std::to_string(array[size - 1]) + "]";
    return result;
}