package service

import "fmt"

type Service struct{}

func (s *Service) Request(id int) {
	fmt.Printf("User with ID %d did something...\n", id)
}
