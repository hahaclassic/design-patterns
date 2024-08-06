package memento

type Caretaker struct {
	mementos []*Memento
}

func (c *Caretaker) SaveMemento(m *Memento) {
	c.mementos = append(c.mementos, m)
}

func (c *Caretaker) GetMemento() *Memento {
	defer func() {
		c.mementos = c.mementos[:len(c.mementos)-1]
	}()

	return c.mementos[len(c.mementos)-1]
}
