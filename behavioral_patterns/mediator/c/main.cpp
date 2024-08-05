#include <iostream>
#include <memory>
#include <list>
#include <vector>

class Mediator;

class Colleague
{
protected:
    std::string name;
	std::weak_ptr<Mediator> mediator;

public:
    explicit Colleague(std::string name): name(name) {};
	virtual ~Colleague() = default;

    std::string getName() const { return name; }
	void setMediator(std::shared_ptr<Mediator> mdr) { mediator = mdr; }

	virtual void sendMessage(std::string text) = 0; 
	virtual void receiveMessage(const Colleague *from, std::string text) = 0;
};

class Mediator
{
protected:
	std::list<std::shared_ptr<Colleague>> colleagues;

public:
	virtual ~Mediator() = default;

	virtual void sendMessage(const Colleague *colleague, std::string text) = 0;

	static void addColleagues(std::shared_ptr<Mediator> mediator, std::initializer_list<std::shared_ptr<Colleague>> list);
};

void Mediator::addColleagues(std::shared_ptr<Mediator> mediator, std::initializer_list<std::shared_ptr<Colleague>> list) {
	if (!mediator || list.size() == 0) return;

	for (auto elem : list)
	{
		mediator->colleagues.push_back(elem);
		elem->setMediator(mediator);
	}
}

class Developer: public Colleague
{
public:
    explicit Developer(std::string name): Colleague(name) {}

    virtual void sendMessage(std::string text) override
    {
        std::cout << this->getName() << "[dev] sended message '" << text << "'\n"; 

        std::shared_ptr<Mediator> mdr = mediator.lock();

	    if (mdr)
            mdr->sendMessage(this, text);
    }

	virtual void receiveMessage(const Colleague *from, std::string text) override 
    { 
        std::cout << "-> " << this->getName() << "[dev] received message '" << text << "' from " << from->getName() << std::endl;
    }
};

class Leader: public Colleague
{
public:
    explicit Leader(std::string name) : Colleague(name) {}

	virtual void sendMessage(std::string text) override
    {
        std::cout << this->getName() << "[lead] sended message '" << text << "'\n"; 

        std::shared_ptr<Mediator> mdr = mediator.lock();

	    if (mdr)
            mdr->sendMessage(this, text);
    }

	virtual void receiveMessage(const Colleague *from, std::string text) override 
    { 
        std::cout << "-> " << this->getName() << "[lead] received message '" << text << "' from " << from->getName() << std::endl;
    }
};

class CorporateMessager: public Mediator
{
public:
	virtual void sendMessage(const Colleague *sender, std::string text) override
    {
        for (auto& col : colleagues)
        {
            if (!dynamic_cast<const Leader*>(sender) && dynamic_cast<const Leader*>(col.get()) || sender == col.get())
            {
                continue;
            }

            col->receiveMessage(sender, text);
        }
    }
};


int main()
{
	std::shared_ptr<Mediator> mediator = std::make_shared<CorporateMessager>();

	std::shared_ptr<Colleague> bob = std::make_shared<Leader>("Bob");
	std::shared_ptr<Colleague> paul = std::make_shared<Leader>("Paul");
    std::shared_ptr<Colleague> sam = std::make_shared<Developer>("Sam");
    std::shared_ptr<Colleague> carl = std::make_shared<Developer>("Carl");

	Mediator::addColleagues(mediator, { bob, paul, sam, carl });

	bob->sendMessage("Hello everyone!");
    std::cout << std::endl;
	sam->sendMessage("Hello?");
}