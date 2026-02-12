#ifndef __DOCTOR_RESEARCHER_H
#define __DOCTOR_RESEARCHER_H
#include <iostream>
#include "Doctor.h"
#include "researcher.h"
using namespace std;

class doctorResearcher : public doctor, public researcher
{
    public:
        doctorResearcher(const doctor& doc, const researcher& researcher);
        doctorResearcher(const char* person_name, const char* person_id, int worker_id, const char* experties);

        doctorResearcher(doctor&& d, researcher&& r);
        friend ostream &operator<<(ostream &os, const doctorResearcher &dr_res);


};

#endif