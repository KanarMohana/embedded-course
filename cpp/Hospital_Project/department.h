#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H
#include <iostream>
#include <string.h>
#include "Doctor.h"
#include "nurse.h"
using namespace std;

class department 
{
    private:
        char* depName;
        doctor **doctors;
        nurse **nurses;
        int physical_size;
        int logical_size;
        int nurse_physical_size;
        int nurse_logical_size;

    public:
        department(const char* dep_name);
        const char* get_depName() const;
        doctor** get_doctors() const;
        nurse** get_nurses() const;
        int get_physical_size() const;
        int get_logical_size() const;
        int get_nurse_physical_size() const;
        int get_nurse_logical_size() const;
        bool set_depName(char* depName);
        //bool set_doctors(doctor** doctors);
        bool set_physical_size(int physical_size);
        bool set_logical_size(int logical_size);
        bool set_nurse_physical_size(int physical_size);
        bool set_nurse_logical_size(int logical_size);
        ~department();
        bool add_doc_to_dep(doctor& doctor);
        bool add_nurse_to_dep(nurse& nurse);
        friend ostream& operator<<(ostream& os, const department& dep);
};

#endif
