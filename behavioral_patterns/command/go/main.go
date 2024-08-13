package main

import "fmt"

type Command interface {
	Execute()
}

type SimpleCommand struct {
	r Object
}

func (s *SimpleCommand) Execute() {
	s.r.Action()
}

type Object interface {
	Action()
}

type ConObject struct{}

func (c *ConObject) Action() {
	fmt.Println("Run method")
}

func main() {
	obj := &ConObject{}

	var command Command = &SimpleCommand{obj}

	command.Execute()
}
