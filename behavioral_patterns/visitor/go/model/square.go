package model

type Square struct {
	a float64
}

func NewSquare(side float64) *Square {
	return &Square{
		a: side,
	}
}

func (s *Square) GetType() string {
	return "square"
}

func (s *Square) Accept(v Visitor) {
	v.visitForSquare(s)
}
