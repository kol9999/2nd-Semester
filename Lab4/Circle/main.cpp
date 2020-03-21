#include <iostream>
#include "interface.h"
#include "circle.h"
using namespace std;

int main()
{
    std::cout<<"::The Circles and the sets of Circle::\n"<<std::endl;
    Circle circle1 , circle2 , circle3;
    std::cout << " :: Entering Data for the first Circle ::" << std::endl;
    circle1.initFromDialog();
    std::cout << ":: Entering Data for the second Circle ::" << std::endl;
    circle2.initFromDialog();
    std::cout << ":: Entering Data for the second Circle ::" << std::endl;
    circle3.initFromDialog();

    CircleSet circleSet;
    circleSet.add(&circle1);
    circleSet.add(&circle2);
    circleSet.add(&circle3);
    std::cout << "\n:: Printing all details of all Circles ::" << std::endl;
    circleSet.displaySet();
    std::cout << std::endl;
    std::cout <<"The Perimeter Sum: " << circleSet.perimeterSum() << std::endl;
    std::cout <<"The Area Sum: " << circleSet.areaSum() << std::endl;
    std::cout <<"The Size in memory sum: " << circleSet.sizeSum() << std::endl;
    circleSet.sortByMass();
}
