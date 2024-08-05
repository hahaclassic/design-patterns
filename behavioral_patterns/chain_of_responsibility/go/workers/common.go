package workers

import "github.com/hahaclassic/design-patterns/behavioral_patterns/chain_of_responsibility/go/model"

type Department interface {
	Execute(*model.Patient)
	SetNext(Department)
}