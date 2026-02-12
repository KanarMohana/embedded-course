#ifndef __HOSPITAL_H
#define __HOSPITAL_H
#include "Doctor.h"
#include "department.h"
#include "researchCenter.h"
#include "patient.h"
#include "visit.h"
#include "nurse.h"
#include "researcher.h"
#include "doctorResearcher.h"

class hospital 
{
private:
    char* hospital_name;
    static int id_count;
    doctor** doctors_arr;
    department** departments_arr;
    patient **patient_arr;
    nurse** nurse_arr;
    visit **visit_arr;
    int dr_logical_size;
    int dr_physical_size;
    int dep_logical_size;
    int dep_physical_size;
    int patient_logical_size;
    int patient_physical_size;
    int visit_logical_size;
    int visit_physical_size;
    int nurse_logical_size;
    int nurse_physical_size;
    employee** employee_arr; 
	int employee_physical_size; 
	int employee_logical_size; 
    research_center hospital_research;

public:
    hospital(const char* hospital_name, const char* hospital_research);
    const char* get_hospital_name() const;
    doctor** get_doctors_arr() const;
    department** get_department_arr() const;
    nurse** get_nurse_arr() const;
    int get_dr_logical_size() const;
    int get_dep_logical_size() const;
    int get_nurse_logical_size() const;
    int get_dr_physical_size() const;
    int get_dep_physical_size() const;
    int get_nurse_physical_size() const;
    int get_patient_logical_size() const;
    int get_patient_physical_size() const;
    int get_visit_logical_size() const;
    int get_visit_physical_size() const;

    bool set_hospital_name(char* hospital_name);
    bool set_dr_logical_size(int dr_logical_size);
    bool set_dep_logical_size(int dep_logical_size);
    bool set_dr_physical_size(int dr_physical_size);
    bool set_dep_physical_size(int dep_physical_size);
    bool set_patient_logical_size(int patient_logical_size);
    bool set_patient_physical_size(int patient_physical_size);
    bool set_visit_logical_size(int visit_logical_size);
    bool set_visit_physical_size(int visit_physical_size);
    bool set_nurse_physical_size(int nurse_physical_size);
    bool set_nurse_logical_size(int nurse_logical_size);

    bool add_department_to_hospital(const char* department_name);
    bool add_doctor_to_hospital(const char* dr_name, const char* dr_id, const char* dr_experties, const char* dr_department);
    bool add_nurse_to_hospital(const char* nurse_name, const char* nurse_id, int nurse_experience, const char* nurse_department);
    bool add_researcher_to_hospital(const char* researcher_name, const char* researcher_id);
    bool add_doctor_researcher_to_hospital(const char* d_r_name, const char* d_r_id, const char* dr_experties, const char* dr_department);
    bool add_article( const char *pupDate, const char *articleName, const char *magazineName, const char* researcherId);
    bool add_patient_to_hospital(const char *patient_id, const char *patient_name, const int year, const char *gender);
    bool add_visit(const char* visitDate, const char* patientId);

    friend ostream& operator<<(ostream& os, const hospital& hospital);


    ~hospital();

};

#endif