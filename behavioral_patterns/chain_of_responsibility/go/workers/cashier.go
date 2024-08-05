package workers

import (
	"fmt"

	"github.com/hahaclassic/design-patterns/behavioral_patterns/chain_of_responsibility/go/model"
)

type Cashier struct {
	next Department
}

func (c *Cashier) Execute(p *model.Patient) {
	if p.PaymentDone {
		fmt.Println("Payment Done")

		return
	}

	fmt.Println("Cashier getting money from patient:", p.Name)
}

func (c *Cashier) SetNext(next Department) {
	c.next = next
}
