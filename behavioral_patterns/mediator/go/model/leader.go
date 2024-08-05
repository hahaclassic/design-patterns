package model

import "fmt"

type Leader struct {
	name string
	m    Mediator
}

func NewLeader(name string, mediator Mediator) *Leader {
	return &Leader{
		name: name,
		m:    mediator,
	}
}

func (l *Leader) GetName() string {
	return l.name
}

func (l *Leader) SendMessage(text string) {
	fmt.Printf("%s[lead] sended message '%s'\n", l.name, text)
	l.m.SendMessage(l, text)
}

func (d *Leader) receivedMessage(from Colleague, text string) {
	fmt.Printf("-> %s[lead] received message '%s' from %s\n", d.name, text, from.GetName())
}
