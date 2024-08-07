#ifndef VISITOR_H
#define VISITOR_H

class Square;
class Rectangle;
class Circle;

class Visitor
{
public:
    virtual ~Visitor() = default;
    virtual void visit(Square &square) = 0;
    virtual void visit(Rectangle &rectangle) = 0;
    virtual void visit(Circle &circle) = 0;
};

#endif // VISITOR_H
