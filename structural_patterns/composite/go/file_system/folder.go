package filesystem

import "fmt"

type Folder struct {
	components []component
	name       string
}

func NewFolder(name string) *Folder {
	return &Folder{name: name}
}

func (f *Folder) Search(key string) {
	fmt.Printf("Searching '%s' in folder '%s':\n", key, f.name)

	for _, component := range f.components {
		component.Search(key)
	}
}

func (f *Folder) Add(comp component) {
	f.components = append(f.components, comp)
}
