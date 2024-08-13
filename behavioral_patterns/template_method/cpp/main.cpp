#include <memory>
#include <iostream>

using namespace std;

class AbstractClass
{
public: 
    ~AbstractClass() = default;

    void templateMethod()
    {
        operation1();
        operation2();
        hook();
    }
protected:
    virtual void operation1() = 0;
    virtual void operation2() { cout << "Base operation2\n"; }
    virtual void hook() { cout << "Base hook\n"; }
};

class ConClassA: public AbstractClass
{
protected:
    void operation1() override { cout << "operation1 A\n"; }
    void hook() override { cout << "hook A\n"; }
};

class ConClassB: public AbstractClass
{
protected:
    void operation1() override { cout << "operation1 B\n"; }
};

int main() {
    auto obj1 = make_shared<ConClassA>();
    auto obj2 = make_shared<ConClassB>();

    obj1->templateMethod();
    cout << endl;
    obj2->templateMethod();
}