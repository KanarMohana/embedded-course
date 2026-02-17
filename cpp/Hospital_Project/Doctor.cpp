#include <iostream>
#include <string.h>
#include "Doctor.h"
#include "department.h"

using namespace std;

// const char* doctor::get_dr_name() const 
// {
//     return dr_name;
// }

// int doctor::get_worker_id() const
// {
//     return worker_id;
// }

const char* doctor::get_exprities() const
{
    return experties;
}

department* doctor::get_departmentPtr() const
{
    return departmentPtr;
}


// bool doctor::set_dr_name(char* new_name) 
// {
//     delete[] dr_name;
//     dr_name = new char[strlen(new_name)+1];
//     strcpy(dr_name,new_name);
//     return true;
// }

// bool doctor::set_worker_id(int new_id)
// {
//     worker_id=new_id;
//     return true;
// }

bool doctor::set_experties(char* new_experties)
{
    delete[] this->experties;
    this->experties = new char[strlen(new_experties)+1];
    strcpy(this->experties,new_experties);
    return true;
}

bool doctor::set_departmentPtr(department* departmentPtr)
{
    this->departmentPtr = departmentPtr;
    return true;
}


doctor::doctor(const employee& emp, const char* experties) : employee(emp), departmentPtr(nullptr)
{
    // this->dr_name= new char[strlen(dr_name)+1];
    // strcpy(this->dr_name, dr_name);
    this->experties = new char[strlen(experties)+1];
    strcpy(this->experties, experties);
    //this->worker_id=worker_id;
}

doctor::doctor(const char* person_name, const char* person_id, int worker_id, const char* experties):employee(person_name, person_id, worker_id), departmentPtr(nullptr)
{
    this->experties = new char[strlen(experties)+1];
    strcpy(this->experties, experties);
}


doctor::doctor(const doctor& other) : employee(other), departmentPtr(nullptr)
{
    *this = other;
}

doctor::doctor(doctor&& other) : employee(std::move(other)), departmentPtr(nullptr)
{
    this->experties = other.experties;
    other.experties=nullptr;
}

const doctor& doctor::operator=(const doctor &other)
{
    if(this!=&other)
    {
        employee::operator=(other);
        this->experties = new char[strlen(other.experties)+1];
        strcpy(this->experties, other.experties);
    }
    return *this;
}

doctor::~doctor()
{
    cout << "in destructor" << endl;
    delete []experties;
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

