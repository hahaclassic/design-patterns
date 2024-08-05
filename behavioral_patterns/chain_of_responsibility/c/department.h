#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <iostream>
#include <initializer_list>
#include <memory>
#include "patient.h"

class Department
{
	using PtrDepartment = std::shared_ptr<Department>;
protected:
	PtrDepartment next;

public:
	using Default = std::shared_ptr<Department>;

	virtual ~Department() = default;

	virtual void Execute(std::shared_ptr<Patient> patient) = 0;

	void SetNext(PtrDepartment node);
	void SetNext(std::initializer_list<PtrDepartment> list);
};

#endif