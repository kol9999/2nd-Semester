#include <iostream>
#include "Array.h"
#include "Array.cpp"

template <class any>

any findMin(any a, any b) {
    return (a<b?a:b);
}

int main() {
    // Function template test
    char x = '@', y = '$';
    std::cout << findMin(x, y) << std::endl;

    double q = 64.2289 , w = 54.1723;
    std::cout << findMin(q, w) << std::endl;

    std::cout << std::endl;

    // Class template and exception test
    Array<char> black(10);

    black.insertElement(5, '5');
    black.insertElement(2, 'd');
    black.insertElement(12, 'y');



    std::cout << "\nThe values within the positions: " << std::endl;
    std::cout << black.getElement(2) << std::endl;
    std::cout << black.getElement(5) << std::endl;
    std::cout << black.getElement(17) << std::endl;


    return 0;
}
