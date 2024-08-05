package workers

import (
	"fmt"

	"github.com/hahaclassic/design-patterns/behavioral_patterns/chain_of_responsibility/go/model"
)

type Doctor struct {
	next Department
}

func (d *Doctor) Execute(p *model.Patient) {
	if p.DoctorCheckUpDone {
		fmt.Println("Doctor checkup already done")
		d.next.Execute(p)

		return
	}

	fmt.Println("Doctor checking patient:", p.Name)
	p.DoctorCheckUpDone = true
	d.next.Execute(p)
}

func (d *Doctor) SetNext(next Department) {
	d.next = next
}
