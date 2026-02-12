#include <iostream>
#include <string.h>
#include "department.h"
using namespace std;

department::department(const char* dep_name):physical_size(2),logical_size(0)
                                                ,nurse_physical_size(2),nurse_logical_size(0)
{
    this->depName = new char[strlen(dep_name)+1];
    strcpy(this->depName,dep_name);
    doctors = new doctor*[physical_size];
    for(int i=0; i<physical_size; ++i)
    {
        doctors[i]=nullptr;
    }
    nurses = new nurse*[nurse_physical_size];
    for(int i=0; i<nurse_physical_size; ++i)
    {
        nurses[i]=nullptr;
    }
}

const char* department::get_depName() const
{
    return depName;
}

doctor** department::get_doctors() const
{
    return doctors;
}

nurse** department::get_nurses() const
{
    return nurses;
}

int department::get_physical_size() const
{
    return physical_size;
}

int department::get_logical_size() const
{
    return logical_size;
}

int department::get_nurse_physical_size() const
{
    return nurse_physical_size;
}

int department::get_nurse_logical_size() const
{
    return nurse_logical_size;
}

bool department::set_depName(char* depName)
{
    delete[] this->depName;
    this->depName = new char[strlen(depName)+1];
    strcpy(this->depName,depName);
    return true;
}

bool department::set_physical_size(int physical_size)
{
    this->physical_size=physical_size;
    return true;
}

bool department::set_logical_size(int logical_size)
{
    this->logical_size = logical_size;
    return true;
}

bool department::set_nurse_physical_size(int nurse_physical_size)
{
    this->nurse_physical_size=nurse_physical_size;
    return true;
}

bool department::set_nurse_logical_size(int nurse_logical_size)
{
    this->nurse_logical_size = nurse_logical_size;
    return true;
}

bool department::add_doc_to_dep(doctor& _doctor)
{
    if (physical_size==logical_size)
    {
        physical_size*=2;
        doctor** tmp=new doctor*[physical_size];
        for(int i=0;i<logical_size;i++)
        {
            tmp[i]=this->doctors[i];
        }
        delete []this->doctors;
        this->doctors = tmp;
    }
    this->doctors[logical_size] = &_doctor;
    _doctor.set_departmentPtr(this);
    logical_size++;
    return true;
}

bool department::add_nurse_to_dep(nurse& _nurse)
{
    if (nurse_physical_size==nurse_logical_size)
    {
        nurse_physical_size*=2;
        nurse** tmp=new nurse*[nurse_physical_size];
        for(int i=0;i<nurse_logical_size;i++)
        {
            tmp[i]=this->nurses[i];
        }
        delete []this->nurses;
        this->nurses = tmp;
    }
    this->nurses[nurse_logical_size] = &_nurse;
    _nurse.set_departmentPtr(this);
    nurse_logical_size++;
    return true;
}

ostream& operator<<(ostream& os, const department& dep)
{
    os << "Department details :\n";
    os << "Department name: " << dep.depName << endl;
    os << "physical size: " << dep.physical_size << endl;
    os << "logical size: " << dep.logical_size << endl;

    os << "Doctors:\n";
    for (int i=0; i<dep.logical_size; i++)
    {
        if(dep.doctors[i]!=nullptr)
        {
            os << *dep.doctors[i];
        }
    }

    os << "Nurses:\n";
    for (int i=0; i<dep.nurse_logical_size; i++)
    {
        if(dep.nurses[i]!=nullptr)
        {
            os << *dep.nurses[i];
        }
    }
    return os;
}


department::~department()
{
    delete []depName;
    // for(int i=0; i<logical_size; i++)
    // {
    //     delete doctors[i];
    // }
    delete []doctors;
    delete []nurses;
}
