#ifndef __VISIT_H
#define __VISIT_H
#include "Doctor.h"
#include "department.h"
#include <iostream>
#include <string.h>
using namespace std;

class patient;

class visit
{
private:
    string visit_date;
    string visit_purbose;
    department* depPtr;
    employee* employee_in_charge;
    const patient *patientPtr;

public:
    visit(const string& visit_date, const patient* patientPtr, const string& visit_purbose, department* depPtr, employee* employee_in_charge);
    const string& get_visit_date() const;
    const string& get_visit_purbose() const;
    const patient*  get_patientPtr() const;
    const department* get_depPtr() const;
    const employee* get_employee_in_charge() const;
    bool set_visit_date(const string& visit_date);
    bool set_visit_purbose(const string& visit_purbose);
    bool set_patientPtr(patient *patientPtr);
    bool set_employee_in_charge(employee* employee_in_charge);
    bool set_departmentPtr(department* depPtr);
   
    friend ostream &operator<<(ostream &os, const visit &v);
    virtual ~visit() {};
};

#endif