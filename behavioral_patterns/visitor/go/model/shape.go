package model

type Visitor interface {
	visitForSquare(s *Square)
	visitForRectangle(r *Rectangle)
	visitForCircle(c *Circle)
}

type Shape interface {
	GetType() string
	Accept(v Visitor)
}
