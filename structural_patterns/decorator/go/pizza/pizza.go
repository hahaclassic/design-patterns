package pizza

type Pizza interface {
	GetPrice() int
}

type Margherita struct {
	price int
}

func NewMargherita(price int) *Margherita {
	return &Margherita{
		price: price,
	}
}

func (m *Margherita) GetPrice() int {
	return m.price
}

type TomatoTopping struct {
	price int
	pizza Pizza
}

func NewTomatoTopping(pizza Pizza, tomatoPrice int) *TomatoTopping {
	return &TomatoTopping{
		pizza: pizza,
		price: tomatoPrice,
	}
}

func (t *TomatoTopping) GetPrice() int {
	return t.pizza.GetPrice() + t.price
}

type CheeseTopping struct {
	price int
	pizza Pizza
}

func NewCheeseTopping(pizza Pizza, cheesePrice int) *CheeseTopping {
	return &CheeseTopping{
		pizza: pizza,
		price: cheesePrice,
	}
}

func (c *CheeseTopping) GetPrice() int {
	return c.pizza.GetPrice() + c.price
}
