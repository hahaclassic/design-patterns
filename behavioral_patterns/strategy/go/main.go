package main

import "github.com/hahaclassic/design-patterns/behavioral_patterns/stategy/go/cache"

func main() {
	c := cache.Cache{}

	c.SetStategy(&cache.FIFO{})
	c.Evict()

	c.SetStategy(&cache.LRU{})
	c.Evict()

	c.SetStategy(&cache.LFU{})
	c.Evict()
}
