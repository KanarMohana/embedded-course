#include <iostream>
#include <string.h>
#include "person.h"
using namespace std;


person::person(const string& name, const string& person_id)
{
    this->name= name;
    this->person_id= person_id;
}

const string& person::get_person_id() const
{
    return person_id;
}

const string& person::get_person_name() const
{
    return name;
}

bool person::set_person_id(const string& person_id)
{
    this->person_id= person_id;
    return true;
}

bool person::set_person_name(const string& name)
{
    this->name= name;
    return true;
}

ostream &operator<<(ostream &os, const person &p)
{
    os << "name: " << p.name << endl;
    os << "ID: " << p.person_id << endl;
    return os;
}

