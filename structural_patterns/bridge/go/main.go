package main

import "fmt"

type Implementor interface {
	OperationImp()
}

type Abstraction interface {
	Operation()
}

type ConImplementor struct{}

func (c *ConImplementor) OperationImp() {
	fmt.Println("Implementor")
}

type Entity struct {
	implementor Implementor
}

func NewEntity(impl Implementor) *Entity {
	return &Entity{
		implementor: impl,
	}
}

func (e *Entity) Operation() {
	fmt.Println("Entity")
	e.implementor.OperationImp()
}

func main() {
	var impl Implementor = &ConImplementor{}

	var abstraction Abstraction = NewEntity(impl)

	abstraction.Operation()
}
