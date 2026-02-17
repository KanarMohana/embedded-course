#ifndef __DOCTOR_H
#define __DOCTOR_H
#include <iostream>
#include <string.h>
#include "employee.h"

using namespace std;

class department;

class doctor : virtual public employee
{
    protected:
        
        string experties;
        department* departmentPtr;

    public:
        doctor(const string& person_name, const string& person_id, int worker_id, const string& experties);

        const string& get_exprities() const;
        department* get_departmentPtr() const;

        bool set_experties(const string& new_experties);
        bool set_departmentPtr(department* departmentPtr);
        
        friend ostream& operator<<(ostream& os, const doctor& dr);

        virtual ~doctor(){};
};

#endif