#include <iostream>
#include <string.h>
#include "Survivor.h"
//#include "Tribe.h"
using namespace std;

int Survivor::counter=0;

string Survivor::get_name()
{
    return name;
}

int Survivor::get_age()
{
    return age;
}

Survivor::eStatus Survivor::getStatus()
{
    return status;
}

int Survivor::get_id()
{
    return id;
}

Tribe* Survivor::get_tribe()
{
    return tribe;
}

const Bandana& Survivor::get_bandana() const
{
    return bandana;
}

bool Survivor::set_name(string _name)
{
    if(_name == nullptr) return false;
    delete[] name;
    name = new char[strlen(_name)+1];
    strcpy(name, _name);
    return false;

}


bool Survivor::set_age(int _age)
{
    if(_age>0)
    {
        age = _age;
        return true;
    }
    return false;
}

bool Survivor::setStatus(eStatus newStatus)
{
    status = newStatus;
    return 1;
}

bool Survivor::set_tribe(Tribe* tribe)
{
    this->tribe = tribe;
    return 1;
}


// void Survivor::initialize_survivor(string _name, int _age, eStatus status, Bandana& band, Tribe* tribe)
// {
//     set_name(_name);
//     set_age(_age);
//     setStatus(status);
//     bandana(band);
//     set_tribe(tribe);
// }

ostream& operator<< (ostream& os, const Survivor& sur)
{
    os << "Survivor ID: " << sur.id << "\n";
    os << "Name: " << sur.name << "\n";
    os << "Age: " << sur.age << "\n";

    os << "Status: ";
    switch (sur.status)
    {
        case Survivor::eStatus::SINGLE:
            os << "Single";
            break;
        case Survivor::eStatus::MARRIED:
            os << "Married";
            break;
        case Survivor::eStatus::INRELATIONSHIP:
            os << "In a relationship";
            break;
    }
    os << "\n";

    os << "Bandana color: " << sur.get_bandana().get_color() << "\n";
    os << "Bandana length: " << sur.get_bandana().get_length() << "\n";

    return os;
}

// void Survivor::print_survivor()
// {
//     cout << "Survivor ID: " << id << "\n";
//     cout << "Name: " << name << "\n";
//     cout << "Age: " << age << "\n";

//     cout << "Status: ";
//     switch (status)
//     {
//         case eStatus::SINGLE:
//             cout << "Single";
//             break;
//         case eStatus::MARRIED:
//             cout << "Married";
//             break;
//         case eStatus::INRELATIONSHIP:
//             cout << "In a relationship";
//             break;
//     }
//     cout << "\n";

//     cout << "Bandana color: " << bandana.get_color() << "\n";
//     cout << "Bandana length: " << bandana.get_length() << "\n";

//     cout << "Tribe: " << get_tribe()->get_name() << "\n";

// }


