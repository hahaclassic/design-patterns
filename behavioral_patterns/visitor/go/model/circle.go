package model

type Circle struct {
	radius float64
}

func NewCircle(radius float64) *Circle {
	return &Circle{
		radius: radius,
	}
}

func (c *Circle) GetType() string {
	return "circle"
}

func (c *Circle) Accept(v Visitor) {
	v.visitForCircle(c)
}
