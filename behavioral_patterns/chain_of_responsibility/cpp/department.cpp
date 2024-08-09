#include "department.h"

// Alternative like golang version
// void Department::SetNext(PtrDepartment node) 
// {
//     next = node;
// }

// This version allows you to add multiple handlers at once
void Department::SetNext(PtrDepartment node) 
{
    if (next) 
        next->SetNext(node);
    else
        next = node;
}

void Department::SetNext(std::initializer_list<PtrDepartment> list)
{
    for (auto node : list)
    {
        SetNext(node);
    }
}