package filesystem

import "fmt"

type File struct {
	name string
}

func NewFile(name string) *File {
	return &File{name: name}
}

func (f *File) Search(key string) {
	fmt.Printf("Searching '%s' in file '%s'...\n", key, f.name)
}
