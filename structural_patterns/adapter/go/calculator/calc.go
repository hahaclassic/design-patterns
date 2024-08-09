package calculator

import "fmt"

type SumCalculator struct{}

func (s SumCalculator) SpecificRequest(a, b int) {
	fmt.Printf("Method SumCalculator: a + b = %d\n", a+b)
}
