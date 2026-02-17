#include <iostream>
#include <string.h>
#include "department.h"
#include "doctorResearcher.h"
using namespace std;

department::department(const string& dep_name)
{
    this->depName=dep_name;
}

const string& department::get_depName() const
{
    return depName;
}

const list<doctor*>& department::get_doctors() const
{
    return doctors;
}

const list<nurse>& department::get_nurses() const
{
    return nurses;
}

bool department::set_depName(const string& depName)
{
    this->depName=depName;
    return true;
}

bool department::add_doc_to_dep(doctor& _doctor)
{
    doctors.push_back(&_doctor);
    doctors.back()->set_departmentPtr(this);
    return true;
}

bool department::add_nurse_to_dep(nurse& _nurse)
{
    nurses.push_back(_nurse);
    nurses.back().set_departmentPtr(this);
    return true;
}

ostream& operator<<(ostream& os, const department& dep)
{
    os << "Department details :\n";
    os << "Department name: " << dep.depName << endl;

    os << "Doctors:\n";

    list<doctor*>::const_iterator itr = dep.doctors.begin();
    list<doctor*>::const_iterator itrEnd = dep.doctors.end();

    if(itr==itrEnd)
    {
        return os;
    }

    for (; itr != itrEnd ; ++itr)
    {
        if (typeid(**itr) == typeid(surgeon))
      {
         os << (surgeon &)(**itr);
      } else if (typeid(**itr) == typeid(doctorResearcher))
      {
         os << (doctorResearcher &)(**itr);
      } else
      {
         os << **itr << endl;
      }
    }

    os << "Nurses:\n";

    list<nurse>::const_iterator itr2 = dep.nurses.begin();
    list<nurse>::const_iterator itrEnd2 = dep.nurses.end();

    if(itr2==itrEnd2)
    {
        return os;
    }

    for (; itr2 != itrEnd2 ; ++itr2)
    {
        os<< *itr2 << endl;
    }
    
    return os;
}
