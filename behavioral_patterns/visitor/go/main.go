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

	shapes := []model.Shape{square, rect, circle}
	for _, s := range shapes {
		s.Accept(area)
		s.Accept(perimeter)
		fmt.Println()
	}
}
