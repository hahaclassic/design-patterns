package main

import (
	"github.com/hahaclassic/design-patterns/behavioral_patterns/chain_of_responsibility/go/model"
	"github.com/hahaclassic/design-patterns/behavioral_patterns/chain_of_responsibility/go/workers"
)

func main() {
	reception := &workers.Reception{}
	doctor := &workers.Doctor{}
	cashier := &workers.Cashier{}

	reception.SetNext(doctor)
	doctor.SetNext(cashier)

	reception.Execute(&model.Patient{
		Name: "Sam",
	})
}
