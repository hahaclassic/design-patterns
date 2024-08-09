#include <iostream>

#include "shapes.h"
#include "visitor.h"
#include <math.h>
#include <vector>

// I couldn't figure out how to make a derived class from Visitor 
// have access to private Square fields, etc., 
// I made getter functions, but then the whole point of the visitor is lost(
// 
// This implies 2 things: 
// 1. A visitor is not needed, if there are such getters, you can do it without him. 
// 2. What if there were no getters? It would have been necessary to expand the existing class,
// and the visitor was invented just to solve this problem.
class AreaCalculator: public Visitor 
{
private: 
    double area;
public:
    void visit(Square &square) override { 
        area = square.getSide() * square.getSide(); 
        std::cout << "Area of square: " << area << std::endl;
    }

    void visit(Rectangle &rectangle) override { 
        area = rectangle.getSide1() * rectangle.getSide2(); 
        std::cout << "Area of rectangle: " << area << std::endl;
    }
    
    void visit(Circle &circle) override { 
        area = M_PI * circle.getRadius() * circle.getRadius(); 
        std::cout << "Area of circle: " << area << std::endl;
    }
};

class PerimeterCalculator: public Visitor 
{
private: 
    double p;
public:
    void visit(Square &square) override { 
        p = 4 * square.getSide(); 
        std::cout << "Perimeter of square: " << p << std::endl;
    }

    void visit(Rectangle &rectangle) override { 
        p = 2 * (rectangle.getSide1() + rectangle.getSide2()); 
        std::cout << "Perimeter of rectangle: " << p << std::endl;
    }
    
    void visit(Circle &circle) override { 
        p = 2 * M_PI * circle.getRadius(); 
        std::cout << "Perimeter of circle: " << p << std::endl;
    }
};

int main()
{
    std::shared_ptr<AreaCalculator> areaCalc = std::make_shared<AreaCalculator>();
    std::shared_ptr<PerimeterCalculator> perimeterCalc = std::make_shared<PerimeterCalculator>();

    std::vector<std::shared_ptr<Shape>> shapes;
    shapes.emplace_back(std::make_shared<Square>(10));
    shapes.emplace_back(std::make_shared<Rectangle>(5, 10));
    shapes.emplace_back(std::make_shared<Circle>(4));

    for (auto shape : shapes) {
        shape->accept(areaCalc);
        shape->accept(perimeterCalc);
        std::cout << std::endl;
    }

    return 0;
}
