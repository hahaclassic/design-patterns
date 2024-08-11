package main

import (
	"fmt"

	"github.com/hahaclassic/design-patterns/structural_patterns/decorator/go/pizza"
)

func main() {
	p := pizza.NewMargherita(100)

	pizzaWithTomato := pizza.NewTomatoTopping(p, 10)
	pizzaWithTomatoAndCheese := pizza.NewCheeseTopping(pizzaWithTomato, 15)

	fmt.Println("Pizza with Tomato:", pizzaWithTomato.GetPrice())
	fmt.Println("Pizza with Tomato and Cheese:", pizzaWithTomatoAndCheese.GetPrice())
}
