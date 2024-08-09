#include <iostream>
#include <memory>
#include <string>

class Adapter
{
public:
	virtual ~Adapter() = default;

	virtual bool request(std::string a, std::string b) = 0;
};

class BaseAdaptee
{
public:
	virtual ~BaseAdaptee() = default;

	virtual void specificRequest(int a, int b) = 0;
};

class ConAdapter : public Adapter
{
private:
	std::shared_ptr<BaseAdaptee>  adaptee;

public:
	ConAdapter(std::shared_ptr<BaseAdaptee> ad) : adaptee(ad) {}

	virtual bool request(std::string a, std::string b) override;
};

class ConAdaptee : public BaseAdaptee
{
public:
	virtual void specificRequest(int a, int b) override { std::cout << "Method ConAdaptee: a + b = " << a + b << std::endl; }
};

#pragma region Methods
bool ConAdapter::request(std::string a, std::string b)
{
	std::cout << "Adapter: ";

    try {
        if (adaptee)
        {
            int numA = std::stoi(a);
            int numB = std::stoi(b);
            adaptee->specificRequest(numA, numB);

            return true;
        } else {
            std::cout << "Empty!" << std::endl;
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range: " << e.what() << std::endl;
    }

    return false;
}

#pragma endregion


int main()
{
	std::shared_ptr<BaseAdaptee> adaptee =  std::make_shared<ConAdaptee>();
	std::shared_ptr<Adapter> adapter = std::make_shared<ConAdapter>(adaptee);

	adapter->request("10", "s");
}