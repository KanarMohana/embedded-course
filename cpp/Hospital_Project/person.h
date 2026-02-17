#ifndef __PERSON_H
#define __PERSON_H
#include <iostream>
using namespace std;

class person 
{
    protected:
        char* name;
        char* person_id;
        person(const char* name, const char* person_id);
        person(const person& other);
        person(person&& other);
        ~person();

    public:
        const char* get_person_id() const;
        const char* get_person_name() const;
        bool set_person_id(const char* person_id);
        bool set_person_name(const char* name);

        friend ostream &operator<<(ostream &os, const person &p);
        const person& operator=(const person &other);

};

#endif