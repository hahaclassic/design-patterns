#ifndef FILE_H
#define FILE_H

#include "component.h"

class File: public Component 
{
private:
    std::string name;
public:
    explicit File(std::string name): name(name) {}

    void search(std::string key) override;
};

#endif