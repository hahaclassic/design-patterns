package model

import "fmt"

type Developer struct {
	name string
	m    Mediator
}

func NewDeveloper(name string, mediator Mediator) *Developer {
	return &Developer{
		name: name,
		m:    mediator,
	}
}

func (d *Developer) GetName() string {
	return d.name
}

func (d *Developer) SendMessage(text string) {
	fmt.Printf("%s[dev] sended message '%s'\n", d.name, text)
	d.m.SendMessage(d, text)
}

func (d *Developer) receivedMessage(from Colleague, text string) {
	fmt.Printf("-> %s[dev] received message '%s' from %s\n", d.name, text, from.GetName())
}
