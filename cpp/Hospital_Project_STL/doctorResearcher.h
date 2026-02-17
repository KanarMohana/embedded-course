#ifndef __DOCTOR_RESEARCHER_H
#define __DOCTOR_RESEARCHER_H
#include <iostream>
#include <string.h>
#include "Doctor.h"
#include "researcher.h"
using namespace std;

class doctorResearcher : public doctor, public researcher
{
    public:
        doctorResearcher(const string& person_name, const string& person_id, int worker_id, const string& experties);

        friend ostream &operator<<(ostream &os, const doctorResearcher &dr_res);


};

#endif