package template

type Operations interface {
	operation1()
	operation2()
	hook()
}

type Abstract struct {
	op Operations
}

func (a *Abstract) Set(op Operations) {
	a.op = op
}

func (a *Abstract) TemplateMethod() {
	a.op.operation1()
	a.op.operation2()
	a.op.hook()
}
