package main

import (
	"fmt"

	"github.com/hahaclassic/design-patterns/behavioral_patterns/template_method/go/template"
)

func main() {
	abs := &template.Abstract{}
	abs.Set(&template.ConcreteA{})
	abs.TemplateMethod()

	fmt.Println()

	abs.Set(&template.ConcreteB{})
	abs.TemplateMethod()
}
