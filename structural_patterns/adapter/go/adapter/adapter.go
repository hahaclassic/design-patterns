package adapter

import (
	"fmt"
	"strconv"
)

type Calculator interface {
	SpecificRequest(a, b int)
}

type SumAdapter struct {
	calc Calculator
}

func New(c Calculator) *SumAdapter {
	return &SumAdapter{
		calc: c,
	}
}

func (s *SumAdapter) Request(a, b string) bool {
	numA, errA := strconv.Atoi(a)
	numB, errB := strconv.Atoi(b)

	if errA != nil || errB != nil {
		fmt.Println("Invalid argument")

		return false
	}

	s.calc.SpecificRequest(numA, numB)

	return true
}
