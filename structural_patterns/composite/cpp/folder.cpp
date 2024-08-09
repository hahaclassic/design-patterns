#include "folder.h"

void Folder::search(std::string key) {
    std::cout << "Searching '" << key << "' in folder '" << name << "':\n";

    for (auto elem : components) {
		elem->search(key);
    }
}

bool Folder::add(std::initializer_list<PtrComponent> list)
{
	for(auto elem : list)
		components.push_back(elem);
	
	return true;
}
