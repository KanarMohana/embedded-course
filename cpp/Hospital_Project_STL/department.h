#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H
#include <iostream>
#include <string.h>
#include <list>
#include "Doctor.h"
#include "nurse.h"
#include "surgeon.h"
using namespace std;

class department 
{
    private:
        string depName;
        list<doctor*> doctors; 
        list<nurse> nurses;        

    public:
        department(const string& dep_name);
        const string& get_depName() const;
        const list<doctor*>& get_doctors() const;
        const list<nurse>& get_nurses() const;
        
        bool set_depName(const string& depName);
        
        bool add_doc_to_dep(doctor& doctor);
        bool add_nurse_to_dep(nurse& nurse);
        friend ostream& operator<<(ostream& os, const department& dep);
    };

#endif
