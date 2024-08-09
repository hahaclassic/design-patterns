#ifndef FOLDER_H
#define FOLDER_H

#include "component.h"

class Folder: public Component 
{
private:
    std::string name;
    VectorComponent components;
public:
    Folder();
    explicit Folder(std::string name): name(name) {}

    bool isComposite() { return true; }
    
    void search(std::string key) override;

    virtual bool add(std::initializer_list<PtrComponent> list) override;
	virtual bool remove(const IteratorComponent& it) override { components.erase(it); return true; }
	virtual IteratorComponent begin() const override { return components.begin(); }
	virtual IteratorComponent end() const override { return components.end(); }
};

#endif
