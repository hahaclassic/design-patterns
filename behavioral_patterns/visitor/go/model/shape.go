package model

type Visitor interface {
	visitForSquare(s *Square)
	visitForRectangle(r *Rectangle)
	visitForCircle(c *Circle)
}

type Shape interface {
	getType() string
	accept(v Visitor)
}
