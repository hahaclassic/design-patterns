package main

import filesystem "github.com/hahaclassic/design-patterns/structural_patterns/composite/go/file_system"

func main() {
	folder1 := filesystem.NewFolder("go")
	folder2 := filesystem.NewFolder("file_system")
	file1 := filesystem.NewFile("component.go")
	file2 := filesystem.NewFile("file.go")
	file3 := filesystem.NewFile("folder.go")
	file4 := filesystem.NewFile("main.go")

	folder1.Add(folder2)
	folder2.Add(file1)
	folder2.Add(file2)
	folder2.Add(file3)
	folder1.Add(file4)

	folder1.Search("hello")
}
