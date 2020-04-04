#include "circle.h"
#include<cmath>
double Circle::area()
{
    return M_PI*((point1.x - point2.x) * (point1.x - point2.x) + (point1.y - point2.y)*(point1.y - point2.y))*((point1.x - point2.x) * (point1.x - point2.x) + (point1.y - point2.y)*(point1.y - point2.y));
}
double Circle::perimeter()
{
   return 2*M_PI*((point1.x - point2.x) * (point1.x - point2.x) + (point1.y - point2.y) * (point1.y - point2.y));
}
double Circle::mass() const{
    return mas;
}
CVector2D Circle::position(){
    CVector2D pos{};
    pos.x = (point2.x + point3.x)/2;
    pos.y = (point2.y + point3.y)/2;
    return pos;
}
bool Circle::operator==(const IPhysObject &ob)
{
    return this->mass() == ob.mass();
}
bool Circle::operator < (const IPhysObject &ob)
{
    return this->mass() < ob.mass();
}
void Circle::draw()
{
    std::cout<<"Point1 / Center : ("<<point1.x <<" , "<<point1.y<<")"<<std::endl;
    std::cout<<"Point2  : ("<<point2.x <<" , "<<point2.y<<")"<<std::endl;
    std::cout<<"Point3  : ("<<point3.x <<" , "<<point3.y<<")"<<std::endl;
    std::cout << "Area: " << area() << std::endl;
    std::cout << "Perimeter: " << perimeter() << std::endl;
    std::cout << "Mass: " << mass() << std::endl;
    std::cout << "Size in Memory: " << size() << std::endl;
}

void Circle::initFromDialog() {
    std::cout << "Enter x and y for the first point: \n";
    std::cin >> point1.x >> point1.y;
    std::cout << "Enter x and y for the second point: \n";
    std::cin >> point2.x >> point2.y;
    std::cout << "Enter x and y for the third point: \n";
    std::cin >> point3.x >> point3.y;
    std::cout << "Enter the mass: \n";
    std::cin >> mas;
}

const char *Circle::classname() {
    return "Circle";
}

unsigned int Circle::size() {
    return sizeof(Circle);
}


CircleSet::CircleSet() {
    size = 0;
}
void CircleSet::add(Circle *Circle) {
    set[size++] = Circle;
}

void CircleSet::displaySet() {
    for (int i = 0; i < size; i++)
        set[i]->draw();
}

double CircleSet::areaSum() {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += set[i]->area();
    }
    return sum;
}
double CircleSet::perimeterSum() {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += set[i]->perimeter();
    }
    return sum;
}

double CircleSet::sizeSum() {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += set[i]->size();
    }
    return sum;
}
CVector2D CircleSet::totalPosition() {
    CVector2D pos{};
    pos.x = 0;
    pos.y = 0;
    for (int i = 0; i < size; i++) {
        pos.x += set[i]->position().x;
        pos.y += set[i]->position().y;
    }
    pos.x /= size;
    pos.y /= size;
    return pos;
}

void CircleSet::swap(Circle &a, Circle &b) {
    Circle temp = a;
    a = b;
    b = temp;
}
void CircleSet::sortByMass() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (set[j]->mass() > set[j + 1]->mass())
                swap(*set[j], *set[j + 1]);
        }
    }
    std::cout << "Sorted according to mass: " << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << set[i]->mass() << " ";
    }
}
