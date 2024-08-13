package template

import "fmt"

type ConcreteA struct{}

func (c *ConcreteA) operation1() {
	fmt.Println("operation1 A")
}

func (c *ConcreteA) operation2() {
	fmt.Println("operation2 A")
}

func (c *ConcreteA) hook() {
	fmt.Println("hook A")
}

type ConcreteB struct{}

func (c *ConcreteB) operation1() {
	fmt.Println("operation1 B")
}

func (c *ConcreteB) operation2() {
	fmt.Println("operation2 B")
}

func (c *ConcreteB) hook() {
	fmt.Println("hook B")
}
