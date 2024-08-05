package workers

import (
	"fmt"

	"github.com/hahaclassic/design-patterns/behavioral_patterns/chain_of_responsibility/go/model"
)

type Reception struct {
	next Department
}

func (r *Reception) Execute(p *model.Patient) {
	if p.RegistrationDone {
		fmt.Println("Patient registration already done")
		r.next.Execute(p)

		return
	}

	fmt.Println("Reception registering patient:", p.Name)
	p.RegistrationDone = true
	r.next.Execute(p)
}

func (r *Reception) SetNext(next Department) {
	r.next = next
}
