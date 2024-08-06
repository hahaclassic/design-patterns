package memento

type Memento struct {
	state string
}

func (m *Memento) GetState() string {
	return m.state
}
