#include<iostream>
#include<math.h>
#include <string>
#include"array.h"

using namespace std;
int main() {



    /// Bapiant 6
    cout << endl << "6/ Array:" << endl;
    Array array1(5);
    array1[0] = 1;
    array1[1] = 2;
    array1[2] = 3;
    array1[3] = 4;
    array1[4] = 5;
    Array array2(6);
    array2[0] = 6;
    array2[1] = 7;
    array2[2] = 8;
    array2[3] = 9;
    array2[4] = 10;
    array2[5] = 11;
    cout << "Array 1 is " << (string)array1 << ", array 2 is " << (string)array2 << endl;
    Array result = array1 + array2;
    cout << "1. Result = array 1 + array 2 is " << (string)result << endl;

    cout << "2. Array 1 == array 2? ";
    if (array1 == array2)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "3. Array 1 != array 2? ";
    if (array1 != array2)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "4. Array > array 2? ";
    if (array1 > array2)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "5. Array 1 < array 2? ";
    if (array1 < array2)
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}
