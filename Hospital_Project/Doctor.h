#ifndef __DOCTOR_H
#define __DOCTOR_H
#include <iostream>
#include "employee.h"

using namespace std;

class department;

class doctor : virtual public employee
{
    protected:
        // char* dr_name;
        // int worker_id;
        char* experties;
    

        department* departmentPtr;

    public:
        doctor(const employee& emp, const char* experties);
        doctor(const doctor& other);
        doctor(doctor&& other);
        const doctor& operator=(const doctor &other);
        
        doctor(const char* person_name, const char* person_id, int worker_id, const char* experties);

        //doctor(employee&& emp, const char* experties);

        // const char* get_dr_name() const;
        // int get_worker_id() const;
        const char* get_exprities() const;
        department* get_departmentPtr() const;
        // bool set_dr_name(char* new_name);
        // bool set_worker_id(int new_id);
        bool set_experties(char* new_experties);
        bool set_departmentPtr(department* departmentPtr);
        
        friend ostream& operator<<(ostream& os, const doctor& dr);

        ~doctor();
};

#endif