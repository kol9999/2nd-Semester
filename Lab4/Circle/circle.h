#pragma once

#include "interface.h"

class Circle: public IGeoFig, IPhysObject, IPrintable, IDialogInitiable, BaseCObject {
public:
    double area() override;
    double perimeter() override;
    double mass() const override;
    CVector2D position() override;
    bool operator== (const IPhysObject& ob) override;
    bool operator< (const IPhysObject& ob) override;
    void draw() override;
    void initFromDialog() override;
    const char * classname() override;
    unsigned int size() override;
private:
    CVector2D point1{}, point2{}, point3{};
    double mas{};
};

class CircleSet {
public:
    CircleSet();
    void add(Circle *point);
    void displaySet();
    double areaSum();
    double perimeterSum();
    double sizeSum();
    CVector2D totalPosition();
    static void swap(Circle& a, Circle& b);
    void sortByMass();
private:
    Circle *set[100]{};
    int size;
};
