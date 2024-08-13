package main

import (
	"fmt"
	"slices"
)

type Subscriber interface {
	Method()
}

type ConSub1 struct{}

func (c *ConSub1) Method() {
	fmt.Println("method 1")
}

type ConSub2 struct{}

func (c *ConSub2) Method() {
	fmt.Println("method 2")
}

type Publisher struct {
	subs []Subscriber
}

func (p *Publisher) indexOf(s Subscriber) int {
	return slices.Index(p.subs, s)
}

func (p *Publisher) Subscribe(s Subscriber) bool {
	if p.indexOf(s) != -1 {
		return false
	}

	p.subs = append(p.subs, s)

	return true
}

func (p *Publisher) Unsubscribe(s Subscriber) bool {
	idx := p.indexOf(s)

	if idx == -1 {
		return false
	}

	p.subs = slices.Delete(p.subs, idx, idx)

	return true
}

func (p *Publisher) Run() {
	fmt.Println("Run:")
	for _, sub := range p.subs {
		sub.Method()
	}
}

func main() {
	p := &Publisher{}
	p.Subscribe(&ConSub1{})
	p.Subscribe(&ConSub2{})

	p.Run()
}
