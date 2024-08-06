package main

import (
	"fmt"

	"github.com/hahaclassic/design-patterns/behavioral_patterns/memento/go/memento"
)

func main() {
	caretaker := &memento.Caretaker{}

	originator := &memento.Originator{}
	fmt.Println("Current state:", originator.GetState())

	// 1. User entered word and we saved last state
	caretaker.SaveMemento(originator.CreateMemento())
	originator.SetState("Hello")
	fmt.Println("Current state:", originator.GetState())

	// 2.
	caretaker.SaveMemento(originator.CreateMemento())
	originator.SetState("Hello world")
	fmt.Println("Current state:", originator.GetState())

	// 3. User decided to delete the last word
	originator.RestoreMemento(caretaker.GetMemento())
	fmt.Println("Current state:", originator.GetState())

	// 4. User decided to delete one more world
	originator.RestoreMemento(caretaker.GetMemento())
	fmt.Println("Current state:", originator.GetState())
}
