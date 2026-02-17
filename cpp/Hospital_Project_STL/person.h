#ifndef __PERSON_H
#define __PERSON_H
#include <iostream>
#include <string.h>
using namespace std;

class person 
{
    protected:
        string name;
        string person_id;
        person(const string& name, const string& person_id);

    public:
        const string& get_person_id() const;
        const string& get_person_name() const;
        bool set_person_id(const string& person_id);
        bool set_person_name(const string& name);

        friend ostream &operator<<(ostream &os, const person &p);

};

#endif