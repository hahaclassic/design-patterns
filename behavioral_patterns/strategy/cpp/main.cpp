#include <memory>
#include <iostream>

using namespace std;

class Cache;

class EvictionStrategy
{
public:
    virtual ~EvictionStrategy() = default;

    virtual void Evict() = 0;
};

class FIFO : public EvictionStrategy
{
public:
    void Evict() override { cout << "FIFO eviction\n"; }
};

class LRU : public EvictionStrategy
{
public:
    void Evict() override { cout << "LRU eviction\n"; }
};

class LFU : public EvictionStrategy
{
public:
    void Evict() override { cout << "LFU eviction\n"; }
};

class Cache
{
public:
    virtual void Evict(shared_ptr<EvictionStrategy> s) = 0;
};

class ConCache : public Cache
{
public:
    void Evict(shared_ptr<EvictionStrategy> strategy = make_shared<LRU>()) override
    {
        strategy->Evict();
    }
};

int main()
{
    shared_ptr<Cache> c = make_shared<ConCache>();
    c->Evict(make_shared<FIFO>()); 

    c->Evict(make_shared<LRU>());

    c->Evict(make_shared<LFU>());

    return 0;
}
