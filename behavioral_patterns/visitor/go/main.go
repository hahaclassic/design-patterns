package main

import (
	"fmt"

	"github.com/hahaclassic/design-patterns/behavioral_patterns/visitor/go/model"
)

func main() {
	square := model.NewSquare(10)
	rect := model.NewRectangle(5, 10)
	circle := model.NewCircle(4)

	area := &model.AreaCalculator{}
	perimeter := &model.PerimeterCalculator{}

	square.Accept(area)
	rect.Accept(area)
	circle.Accept(area)
	fmt.Println()

	square.Accept(perimeter)
	rect.Accept(perimeter)
	circle.Accept(perimeter)
}
