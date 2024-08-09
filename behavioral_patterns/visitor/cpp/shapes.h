#ifndef SHAPES_H
#define SHAPES_H

#include <string>
#include <memory>
#include "visitor.h"

class Shape
{
public:
    virtual ~Shape() = default;

    virtual void accept(std::shared_ptr<Visitor> visitor) = 0;
};

class Square: public Shape 
{
private:
    double side;
public:
    Square(double s): side(s) {}

    double getSide() { return side; } 

    void accept(std::shared_ptr<Visitor> visitor) override { return visitor->visit(*this); }

    // friend void Visitor::visit(Square &square);
};

class Rectangle: public Shape 
{
private:
    double side1, side2;
public:
    Rectangle(double s1, double s2): side1(s1), side2(s2) {}

    double getSide1() { return side1; } 

    double getSide2() { return side2; } 

    void accept(std::shared_ptr<Visitor> visitor) override { return visitor->visit(*this); }

    // friend void Visitor::visit(Rectangle &rect);
};

class Circle: public Shape 
{
private:
    double radius;
public:
    Circle(double r): radius(r) {}

    double getRadius() { return radius; } 

    void accept(std::shared_ptr<Visitor> visitor) override { return visitor->visit(*this); }

    // friend void Visitor::visit(Circle &circle);
};

#endif // SHAPES_H
