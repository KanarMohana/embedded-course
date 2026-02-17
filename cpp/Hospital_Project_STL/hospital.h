#ifndef __HOSPITAL_H
#define __HOSPITAL_H
#include <string.h>
#include "Doctor.h"
#include "department.h"
#include "researchCenter.h"
#include "patient.h"
#include "visit.h"
#include "nurse.h"
#include "researcher.h"
#include "doctorResearcher.h"
#include "surgeon.h"
#include "surgerieVisit.h"
#include <list>

class hospital 
{
private:
    string hospital_name;
    static int id_count;
    list<department> departments_arr;
    list<patient> patient_arr;
    list<visit*> visit_arr;
    list<employee*> employee_arr;
    
    int patient_logical_size;
    int patient_physical_size;
    int visit_logical_size;
    int visit_physical_size;

	int employee_physical_size; 
	int employee_logical_size; 
    research_center hospital_research;

public:
    hospital(const string& hospital_name, const string& hospital_research);
    const string& get_hospital_name() const;
    
    const list<department>& get_department_arr() const;

    const list<patient>& get_patient_arr() const;

    bool set_hospital_name(string& hospital_name);
    
    department *check_department_exist(const string &departmentName);
    patient *find_patient_byId(const string &patient_id);
    employee *find_employee_byId(const string &employeeId);

    bool add_department_to_hospital(const string& department_name);
    bool add_doctor_to_hospital(const string& dr_name, const string& dr_id, const string& dr_experties, const string& dr_department);
    bool add_nurse_to_hospital(const string& nurse_name, const string& nurse_id, int nurse_experience, const string& nurse_department);
    bool add_researcher_to_hospital(const string& researcher_name, const string& researcher_id);
    bool add_doctor_researcher_to_hospital(const string& d_r_name, const string& d_r_id, const string& dr_experties, const string& dr_department);
    bool add_article( const string& pupDate, const string& articleName, const string& magazineName, const string& researcherId);
    bool add_patient_to_hospital(const string& patient_id, const string& patient_name, const int year, const string& gender);
    bool add_surgeon_to_hospital(const string &doctorName, const string &doctorId, const string &experties, const string &departmentName, int numberOfSurgeries);
    bool add_visit(const string& visitDate, const string& patientId, const string& visit_purbose, const string& dep_name, const string& employee_in_charge);
    bool add_surgerieVisit(const string &visitDate, const string &patientId,int numSurgerieRoom,bool isFasting, const string& visit_purbose, const string& dep_name, const string& employee_in_charge);
    friend ostream& operator<<(ostream& os, const hospital& hospital);
    ~hospital();
};

#endif