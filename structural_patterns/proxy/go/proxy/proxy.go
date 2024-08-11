package proxy

import "fmt"

type Service interface {
	Request(id int)
}

type AuthProxy struct {
	service    Service
	allowedIDs map[int]struct{}
}

func NewAuthProxy(service Service, allowedID []int) *AuthProxy {
	IDs := make(map[int]struct{}, len(allowedID))
	for i := range allowedID {
		IDs[allowedID[i]] = struct{}{}
	}

	return &AuthProxy{
		service:    service,
		allowedIDs: IDs,
	}
}

func (auth *AuthProxy) Request(id int) {
	if !auth.isAllowed(id) {
		fmt.Println("Proxy rejected request with ID", id)

		return
	}

	auth.service.Request(id)
}

func (auth *AuthProxy) isAllowed(id int) bool {
	_, ok := auth.allowedIDs[id]

	return ok
}
