#include <iostream>
#include <string.h>
#include "person.h"
using namespace std;


person::person(const char* name, const char* person_id): name(nullptr), person_id(nullptr)
{
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
    this->person_id = new char[strlen(person_id)+1];
    strcpy(this->person_id, person_id);
}

person::person(const person& other) : name(nullptr), person_id(nullptr)
{
    *this = other;
}

person::person(person&& other)
{
    this->name = other.name;
    other.name=nullptr;

    this->person_id = other.person_id;
    other.person_id=nullptr;
}

person::~person()
{
    cout << "in person destructor" << endl;
    delete []name;
    delete []person_id;
}

const char* person::get_person_id() const
{
    return person_id;
}

const char* person::get_person_name() const
{
    return name;
}

bool person::set_person_id(const char* person_id)
{
    delete []this->person_id;
    this->person_id = new char[strlen(person_id) + 1];
    strcpy(this->person_id, person_id);
    return true;
}

bool person::set_person_name(const char* name)
{
    delete []this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    return true;
}

ostream &operator<<(ostream &os, const person &p)
{
    os << "PERSONAL DETAILS: " << endl;
    os << "name: " << p.name << endl;
    os << "ID: " << p.person_id << endl;
    return os;
}

const person& person::operator=(const person &other)
{
    if(this != &other)
    {
        if(this->person_id!=nullptr)
        {
            delete []this->person_id;
        }
        this->person_id = new char[strlen(other.person_id)+1];
        strcpy(this->person_id, other.person_id);

        if(this->name!=nullptr)
        {
            delete []this->name;
        }
        this->name = new char[strlen(other.name)+1];
        strcpy(this->name, other.name);
    }
    return *this;
}
