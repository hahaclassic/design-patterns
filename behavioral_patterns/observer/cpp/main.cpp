# include <iostream>
# include <memory>
# include <vector>

using namespace std;

class Subscriber;

class Publisher
{
    using Action = void(Subscriber::*)();
    using Pair = pair<shared_ptr<Subscriber>, Action>;
private:
    vector<Pair> subs;

    int indexOf(shared_ptr<Subscriber> sub);

public:
    bool subscribe(shared_ptr<Subscriber> s, Action a);
	bool unsubscribe(shared_ptr<Subscriber> s);
	void run();
};

class Subscriber
{
public:
	virtual ~Subscriber() = default;

	virtual void method() = 0;
};

class ConSubscriber1 : public Subscriber
{
public:
	virtual void method() override { cout << "method 1" << endl; }
};

class ConSubscriber2 : public Subscriber
{
public:
	virtual void method() override { cout << "method 2" << endl; }
};

bool Publisher::subscribe(shared_ptr<Subscriber> s, Action a) 
{
    if (indexOf(s) != -1) { return false; }

    Pair pr(s, a);

    subs.push_back(pr);
    return true;
}

bool Publisher::unsubscribe(shared_ptr<Subscriber> s)
{
    int pos = indexOf(s);

	if (pos != -1)
		subs.erase(subs.begin() + pos);

	return pos != -1;
}

void Publisher::run()
{
	cout << "Run:" << endl;
	for (auto elem : subs)
		((*elem.first).*(elem.second))();
}

int Publisher::indexOf(shared_ptr<Subscriber> r)
{
	int i = 0;
	for (auto it = subs.begin(); it != subs.end() && r != (*it).first; i++, ++it);

	return i < subs.size() ? i : -1;
}

int main() 
{
    shared_ptr<Publisher> p = make_shared<Publisher>();
    shared_ptr<Subscriber> s1 = make_shared<ConSubscriber1>();
    shared_ptr<Subscriber> s2 = make_shared<ConSubscriber2>();

    p->subscribe(s1, &Subscriber::method);
    p->subscribe(s2, &Subscriber::method);

    p->run();

    p->unsubscribe(s1);

    p->run();

    return 0;
}