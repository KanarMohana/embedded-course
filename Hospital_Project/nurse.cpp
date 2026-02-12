#include <iostream>
#include <string.h>
#include "nurse.h"
#include "department.h"

using namespace std;

nurse::nurse(const employee& emp, int experience) : employee(emp)
{
    this->experience=experience;
    this->departmentPtr=nullptr;
}

nurse::nurse(const char* person_name, const char* person_id, int worker_id, int experience):employee(person_name, person_id, worker_id)
{
    this->experience=experience;
    this->departmentPtr=nullptr;
}

int nurse::get_experience() const
{
    return experience;
}

department* nurse::get_departmentPtr() const
{
    return departmentPtr;
}

bool nurse::set_experience(int experience)
{
    this->experience=experience;
    return true;
}

bool nurse::set_departmentPtr(department* departmentPtr)
{
    this->departmentPtr = departmentPtr;
    return true;
}

ostream& operator<<(ostream& os, const nurse& _nurse)
{
    os<<"NURSE DETAILS:\n";
    os<<(employee&)_nurse;
    os<<"Experience: "<<_nurse.experience<<endl;
    os<<"Department: "<<_nurse.departmentPtr->get_depName()<<endl;
    return os;
}