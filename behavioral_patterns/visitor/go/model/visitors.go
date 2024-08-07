package model

import (
	"fmt"
	"math"
)

// Concrete visitor #1.
type AreaCalculator struct {
	area float64
}

// Perhaps a method is needed here to get the dimensions. But then an identical problem arises,
// which we initially solved with the help of the visitor: it is necessary to add dimension
// functions to all objects. And if there aren't any?
// Example: square.GetSize() float64.
func (c *AreaCalculator) visitForSquare(square *Square) {
	c.area = square.a * square.a

	fmt.Println("Square area calculated:", c.area)
}

func (c *AreaCalculator) visitForRectangle(rect *Rectangle) {
	c.area = rect.a * rect.b

	fmt.Println("Rect area calculated:", c.area)
}

func (c *AreaCalculator) visitForCircle(circle *Circle) {
	c.area = math.Pi * circle.radius * circle.radius

	fmt.Println("Circle area calculated:", c.area)
}

// Concrete visitor #2.
type PerimeterCalculator struct {
	perimeter float64
}

func (c *PerimeterCalculator) visitForSquare(square *Square) {
	numOfSides := 4.
	c.perimeter = square.a * numOfSides

	fmt.Println("Square perimeter calculated:", c.perimeter)
}

func (c *PerimeterCalculator) visitForRectangle(rect *Rectangle) {
	numOfSides := 2.0
	c.perimeter = numOfSides * (rect.a + rect.b)

	fmt.Println("Rectangle perimeter calculated:", c.perimeter)
}

func (c *PerimeterCalculator) visitForCircle(circle *Circle) {
	k := 2.0
	c.perimeter = k * math.Pi * circle.radius

	fmt.Println("Circle perimeter calculated:", c.perimeter)
}
