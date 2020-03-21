#include <iostream>
#include <string>
#include "array.h"

int main() {
    std::cout << "-----Task 6-----"<< std::endl;
    Array array1(5);
    array1[0] = 1;
    array1[1] = 2;
    array1[2] = 3;
    array1[3] = 4;
    array1[4] = 5;
    Array array2(5);
    array2[0] = 6;
    array2[1] = 7;
    array2[2] = 8;
    array2[3] = 9;

    std::cout << "Array 1 is " << (std::string) array1 << ", Array 2 is " << (std::string) array2 << std::endl;
    Array result = array1 + array2;
    std::cout << "Array 1 + Array 2 is " << (std::string) result << std::endl;

    if (array1 == array2) {
        std::cout << "Array 1 = Array 2";
    } else if (array1 < array2) {
        std::cout << "Array 1 < Array 2";
    }

    if (array1 > array2) {
        std::cout << "Array 1 > Array 2";
    }
}
