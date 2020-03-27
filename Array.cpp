#include "Array.h"


template<class T>
Array<T>::Array(int s) {
    arr = new T[s];
    size = s;
}

template<class T>
Array<T>::~Array() {
    delete arr;
}

template<class T>
void Array<T>::insertElement(int position, T element) {
    try {
        if(position < 0 || position >= size) {
            throw 99;
        }
        arr[position] = element;
    } catch (int h) {
        std::cout << "Invalid Position! ERROR NUMBER #" << h << std::endl;
    }
}

template<class T>
T Array<T>::getElement(int position) {
    try {
        if(position < 0 || position >= size) {
            throw 88;
        }
        return arr[position];
    } catch (int h) {
        std::cout << "Invalid Position! ERROR NUMBER #" << h << std::endl;
        return 0;
    }
}
