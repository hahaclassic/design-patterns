#ifndef COMPONENT_H
#define COMPONENT_H

# include <iostream>
# include <initializer_list>
# include <memory>
# include <vector>
# include <iterator>

class Component;

using PtrComponent = std::shared_ptr<Component>;
using VectorComponent = std::vector<PtrComponent>;
using IteratorComponent = VectorComponent::const_iterator;

class Component
{
public:
    virtual ~Component() = default;
    virtual bool isComposite() { return false; }
    virtual void search(std::string key) = 0;

    virtual bool add(std::initializer_list<PtrComponent> comp) { return false; }
    virtual bool remove(const IteratorComponent& it) { return false; }
	virtual IteratorComponent begin() const { return IteratorComponent(); }
	virtual IteratorComponent end() const { return IteratorComponent(); }
};

#endif // COMPONENT_H