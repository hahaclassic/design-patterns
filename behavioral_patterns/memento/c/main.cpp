#include <iostream>
#include <string>
#include <memory>
#include <list>

class Memento
{
private:
    std::string state;
public:
    Memento(std::string state): state(state) {}

    std::string getState() { return state; }
};

class Originator
{
private:
    std::string state;
public:
    Originator(std::string s): state(s) {}

    void setState(std::string newState) { state = newState; } 

    std::string getState() const { return state; }

    std::unique_ptr<Memento> createMemento() { return std::make_unique<Memento>(state); }

    void restoreMemento(std::unique_ptr<Memento> memento) { state = memento->getState(); }
};

class Caretaker 
{
private:
    std::list<std::unique_ptr<Memento>> mementos;
public:
    void saveMemento(std::unique_ptr<Memento> memento) {
        mementos.push_back(std::move(memento));
    }

    std::unique_ptr<Memento> getMemento() { 
        if (mementos.empty()) {
            return nullptr;
        }
        
        std::unique_ptr<Memento> last = std::move(mementos.back());
        mementos.pop_back();
        return last;
    }
};


int main()
{
    auto caretaker = std::make_unique<Caretaker>();
    auto originator = std::make_unique<Originator>("");
    std::cout << "Current state: " << originator->getState() << std::endl;

    caretaker->saveMemento(originator->createMemento());
    originator->setState("Hello");
    std::cout << "Current state: " << originator->getState() << std::endl;

    caretaker->saveMemento(originator->createMemento());
    originator->setState("Hello world");
    std::cout << "Current state: " << originator->getState() << std::endl;

    originator->restoreMemento(caretaker->getMemento());
    std::cout << "Current state: " << originator->getState() << std::endl;

    originator->restoreMemento(caretaker->getMemento());
    std::cout << "Current state: " << originator->getState() << std::endl;

    return 0;
}
