#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H
#include <iostream>
using namespace std;
#include "person.h"

class employee : public person
{
    protected:
        int worker_id;
        employee(const string& person_name, const string& person_id, int worker_id);

    public:
        int get_worker_id() const;
        bool set_worker_id(int worker_id);
        friend ostream &operator<<(ostream &os, const employee &emp);
        virtual ~employee(){};
};

#endif