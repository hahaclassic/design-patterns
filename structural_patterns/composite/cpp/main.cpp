#include <iostream>
#include "component.h"
#include "file.h"
#include "folder.h"

int main()
{
    using Default = std::shared_ptr<Component>;

    auto file1 = std::make_shared<File>("component.go");
    auto file2 = std::make_shared<File>("file.go");
    auto file3 = std::make_shared<File>("folder.go");
    auto file4 = std::make_shared<File>("main.go");

    auto folder1 = std::make_shared<Folder>("file_system");
    folder1->add({file1, file2, file3, file4});

    auto folder2 = std::make_shared<Folder>("go");
    folder2->add({folder1});

    folder2->search("hello");
    std::cout << std::endl;

    IteratorComponent it = folder1->begin();
    folder1->remove(++it); // С помощью итератора удаляем второй файл в папке

    folder2->search("hello");

    return 0;
}
