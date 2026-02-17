#ifndef __NURSE_H
#define __NURSE_H
#include <iostream>
#include "employee.h"
using namespace std;

class department;

class nurse : public employee
{
    private:
        int experience;
        department* departmentPtr;

    public:
        nurse(const employee& emp, int experience);
        nurse(const char* person_name, const char* person_id, int worker_id, int experience);

        int get_experience() const;
        department* get_departmentPtr() const;

        bool set_experience(int experience);
        bool set_departmentPtr(department* departmentPtr);

        friend ostream& operator<<(ostream& os, const nurse& nurse);
};

#endif