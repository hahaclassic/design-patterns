package main

import (
	"github.com/hahaclassic/design-patterns/structural_patterns/adapter/go/adapter"
	"github.com/hahaclassic/design-patterns/structural_patterns/adapter/go/calculator"
)

type Adapter interface {
	Request(a, b string) bool
}

func main() {
	var calcAdapter Adapter

	calc := calculator.SumCalculator{}
	calcAdapter = adapter.New(calc)

	calcAdapter.Request("10", "15")
}
