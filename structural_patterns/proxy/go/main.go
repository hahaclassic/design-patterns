package main

import (
	"github.com/hahaclassic/design-patterns/structural_patterns/proxy/go/proxy"
	"github.com/hahaclassic/design-patterns/structural_patterns/proxy/go/service"
)

func main() {
	s := &service.Service{}

	// Proxy implemented Service interface
	var proxy proxy.Service = proxy.NewAuthProxy(s, []int{10, 20, 30})

	proxy.Request(10) // OK
	proxy.Request(11) // rejected
	proxy.Request(12) // rejected
	proxy.Request(20) // OK
}
