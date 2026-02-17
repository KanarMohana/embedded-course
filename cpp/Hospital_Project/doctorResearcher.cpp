#include <iostream>
#include <string.h>
#include "doctorResearcher.h"
using namespace std;

// doctorResearcher::doctorResearcher(const doctor& doc, const researcher& res):employee(person(doc.get_person_name(), doc.get_person_id()),doc.get_worker_id()),
//                                                                                     doctor(doc), researcher(res)
// {
// }

doctorResearcher::doctorResearcher(const char *doctor_researcher_name, const char *doctor_researcher_id, int idCounter,const char *experties): 
employee(doctor_researcher_name,doctor_researcher_id,idCounter),
doctor(doctor_researcher_name,doctor_researcher_id,idCounter, experties),
researcher(doctor_researcher_name,doctor_researcher_id,idCounter)
{
}

// doctorResearcher::doctorResearcher(doctor&& d, researcher&& r) 
//     : employee(person( d.get_person_name(),d.get_person_id()), d.get_worker_id()),
//       doctor(std::move(d)),
//       researcher(std::move(r))
// {
// }

ostream &operator<<(ostream &os, const doctorResearcher &dr_res)
{
    os << "DOCTOR RESEARCHER DETAILS" << endl;
    os << (doctor&)dr_res;
    os << (researcher&)dr_res;
    return os;
}