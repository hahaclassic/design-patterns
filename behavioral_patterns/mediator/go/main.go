package main

import (
	"fmt"

	"github.com/hahaclassic/design-patterns/behavioral_patterns/mediator/go/model"
)

func main() {
	m := &model.СorporateMessenger{}

	bob := model.NewLeader("Bob", m)
	paul := model.NewLeader("Paul", m)
	sam := model.NewDeveloper("Sam", m)
	carl := model.NewDeveloper("Carl", m)

	m.AddColleagues([]model.Colleague{
		bob, sam, carl, paul,
	})

	bob.SendMessage("Hello everyone!")
	fmt.Println()
	sam.SendMessage("Hello?")
}
