#include <iostream>
#include <string.h>
#include "doctorResearcher.h"
using namespace std;


doctorResearcher::doctorResearcher(const string& doctor_researcher_name, const string& doctor_researcher_id, int idCounter,const string& experties): 
employee(doctor_researcher_name,doctor_researcher_id,idCounter),
doctor(doctor_researcher_name,doctor_researcher_id,idCounter, experties),
researcher(doctor_researcher_name,doctor_researcher_id,idCounter)
{
}



ostream &operator<<(ostream &os, const doctorResearcher &dr_res)
{
    os << "DOCTOR RESEARCHER DETAILS" << endl;
    os << (doctor&)dr_res;
    os << (researcher&)dr_res;
    return os;
}