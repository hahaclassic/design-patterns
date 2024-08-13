package cache

import "fmt"

type Cache struct {
	eviction EvictionStategy
}

func (c *Cache) SetStategy(e EvictionStategy) {
	c.eviction = e
}

func (c *Cache) Evict() {
	c.eviction.Evict(*c)
}

// Strategy.
type EvictionStategy interface {
	Evict(c Cache)
}

// Concrete stategies.
type FIFO struct{}

func (f *FIFO) Evict(_ Cache) {
	fmt.Println("FIFO eviction")
}

type LRU struct{}

func (l *LRU) Evict(_ Cache) {
	fmt.Println("LRU eviction")
}

type LFU struct{}

func (l *LFU) Evict(_ Cache) {
	fmt.Println("LFU eviction")
}
