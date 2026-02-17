#include <iostream>
#include <string.h>
#include "Doctor.h"
#include "department.h"
using namespace std;


const string& doctor::get_exprities() const
{
    return experties;
}

department* doctor::get_departmentPtr() const
{
    return departmentPtr;
}

bool doctor::set_experties(const string& new_experties)
{
    this->experties=new_experties;
    return true;
}

bool doctor::set_departmentPtr(department* departmentPtr)
{
    this->departmentPtr = departmentPtr;
    return true;
}

doctor::doctor(const string& person_name, const string& person_id, int worker_id, const string& experties):employee(person_name, person_id, worker_id), departmentPtr(nullptr)
{
    this->experties= experties;
}

ostream& operator<<(ostream& os, const doctor& dr)
{
    os<<"doctor details:\n";
    os<<(employee&)dr;
    os<<"Experties: "<<dr.experties<<endl;
    if (dr.departmentPtr)
    {
        os << dr.departmentPtr->get_depName() << "\n";
    }
    return os;
}