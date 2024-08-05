#ifndef PATIENT_H
#define PATIENT_H
#include <iostream>

class Patient
{
private:
    std::string name;
public:
    Patient(std::string name): name(name) {};

    std::string GetName()
    {
        return name;
    }
};

#endif