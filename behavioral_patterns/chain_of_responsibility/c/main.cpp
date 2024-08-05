#include <iostream>
#include <initializer_list>
#include <memory>
#include "department.h"
#include "patient.h"

class Reception: public Department
{
public:
    Reception() { std::cout << "Constructor Reception" << std::endl; }
    ~Reception() override { std::cout << "Destructor Reception" << std::endl; }

    void Execute(std::shared_ptr<Patient>);
};

void Reception::Execute(std::shared_ptr<Patient> patient)
{
    std::cout << "Patient " << patient->GetName() << " passed reception\n";
    
    if (next) 
        next->Execute(patient);
}

class Doctor: public Department
{
public:
    Doctor() { std::cout << "Constructor Doctor" << std::endl; }
    ~Doctor() override { std::cout << "Destructor Doctor" << std::endl; }

    void Execute(std::shared_ptr<Patient>);
};

void Doctor::Execute(std::shared_ptr<Patient> patient)
{
    std::cout << "Patient " << patient->GetName() << " passed doctor\n";

    if (next) 
        next->Execute(patient);
}

class Cashier : public Department
{
public:
    Cashier() { std::cout << "Constructor Cashier" << std::endl; }
    ~Cashier() override { std::cout << "Destructor Cashier" << std::endl; }

    void Execute(std::shared_ptr<Patient>);
};

void Cashier::Execute(std::shared_ptr<Patient> patient)
{
    std::cout << "Patient " << patient->GetName() << " passed cashier\n";
    
    if (next) 
        next->Execute(patient);
}


int main()
{
	std::shared_ptr<Department> reception = std::make_shared<Reception>();

    reception->SetNext({
        std::make_shared<Doctor>(),
        std::make_shared<Cashier>()
    });

    reception->Execute(std::make_shared<Patient>("Bob"));
}