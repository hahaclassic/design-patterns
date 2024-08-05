package model

type Colleague interface {
	GetName() string
	SendMessage(text string)
	receivedMessage(sender Colleague, text string)
}

type Mediator interface {
	SendMessage(from Colleague, text string)
}
