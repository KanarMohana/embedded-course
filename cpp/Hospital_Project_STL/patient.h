#ifndef __PATIENT_H
#define __PATIENT_H
#include <iostream>
#include <string.h>
#include <list>
#include "person.h"
using namespace std;

class visit;

class patient : public person 
{

private:
    int year;
    string gender;
    list<visit> visitsP_arr;

public:
    patient(const string& person_name, const string& person_id,int year, const string& gender);

    int get_year() const;
    const string& get_gender() const;
    const list<visit>& get_visitP() const;
    bool set_year(int year);
    bool set_gender(const string& gender);
    bool add_visit_patient(visit* visitPtr);

    friend ostream &operator<<(ostream &os, const patient &p);
};

#endif