# include <iostream>
# include <memory>
# include <set>

using namespace std;

class Service
{
public:
	virtual ~Service() = default;

	virtual void Request(int id) = 0;
};

class RealService: public Service
{
public:
	void Request(int id) override;
};

void RealService::Request(int id) 
{
    cout << "User with ID " << id << " did something...\n";
}

class Proxy: public Service
{
protected:
	shared_ptr<RealService> service;

public:
	Proxy(shared_ptr<RealService> real): service(real) {}
};

class AuthProxy: public Proxy
{
private:
	set<int> allowedIDs;

public:
    using Proxy::Proxy;
    virtual void Request(int id) override;

    void AddIDs(initializer_list<int> ids);
    bool isAllowed(int id);
};

void AuthProxy::AddIDs(initializer_list<int> ids) 
{
    for (auto id : ids)
        allowedIDs.insert(id);
}

void AuthProxy::Request(int id) 
{
    if (!isAllowed(id)) 
        cout << "Proxy rejected request with ID " << id << endl;
    else
        service->Request(id);
}

bool AuthProxy::isAllowed(int id) 
{
    return allowedIDs.count(id) != 0;
}


int main()
{
	shared_ptr<RealService> service = make_shared<RealService>();
	shared_ptr<AuthProxy> authProxy = make_shared<AuthProxy>(service);
    authProxy->AddIDs({10, 20, 30});
	
    shared_ptr<Service> proxy = authProxy;
    proxy->Request(10);
    proxy->Request(11);
    proxy->Request(12);
    proxy->Request(20);

    return 0;
}