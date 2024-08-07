package model

type Rectangle struct {
	a, b float64
}

func NewRectangle(a, b float64) *Rectangle {
	return &Rectangle{
		a: a,
		b: b,
	}
}

func (r *Rectangle) GetType() string {
	return "rectangle"
}

func (r *Rectangle) Accept(v Visitor) {
	v.visitForRectangle(r)
}
