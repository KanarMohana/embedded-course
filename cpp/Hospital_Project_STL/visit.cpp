#include <iostream>
using namespace std;
#include <string.h>
#include "visit.h"
#include "patient.h"

visit::visit(const string& visit_date, const patient *patientPtr, const string& visit_purbose, department* depPtr, employee* employee_in_charge)
{
    this->visit_date = visit_date;
    this->patientPtr = patientPtr;
    this->visit_purbose = visit_purbose;
    this->depPtr = depPtr;
    this->employee_in_charge = employee_in_charge;
}
const string& visit::get_visit_date() const
{
    return visit_date;
}

const string& visit::get_visit_purbose() const
{
    return visit_purbose;
}

const patient *visit::get_patientPtr() const
{
    return patientPtr;
}

const department* visit::get_depPtr() const
{
    return depPtr;
}

const employee* visit::get_employee_in_charge() const
{
    return employee_in_charge;
}

bool visit::set_visit_date(const string& visit_date)
{
    this->visit_date= visit_date;
    return true;
}

bool visit::set_patientPtr(patient *patientPtr)
{
    this->patientPtr = patientPtr;
    return true;
}

bool visit::set_visit_purbose(const string& visit_purbose)
{
    this->visit_purbose = visit_purbose;
    return true;
}

bool visit::set_employee_in_charge(employee* employee_in_charge)
{
    this->employee_in_charge = employee_in_charge;
    return true;
}

bool visit::set_departmentPtr(department* depPtr)
{
    this->depPtr =depPtr;
    return true;
}


ostream &operator<<(ostream &os, const visit &v)
{
    os << "Visit Details: \n";
    os << "Visit Date: " << v.visit_date << "\n";
    os << "Visit Purbose: " << v.visit_purbose << endl;
    os << "Patient Name: " << v.patientPtr->get_person_name() << "\n";
    os << "department: " << v.depPtr->get_depName() << endl;
    os << "responsable employee: " << v.employee_in_charge->get_person_name() << endl;
    return os;

}