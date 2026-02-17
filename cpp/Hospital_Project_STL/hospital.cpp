#include <iostream>
#include "Doctor.h"
#include "employee.h"
#include "hospital.h"
#include "patient.h"
#include <string.h>
using namespace std;

int hospital::id_count=0;

hospital::hospital(const string& hospital_name, const string& hospital_research) :  hospital_research(hospital_research)
{
    this->hospital_name=hospital_name;
}

const string& hospital::get_hospital_name() const
{
    return hospital_name;
}


const list<department>& hospital::get_department_arr() const
{
    return departments_arr;
}

bool hospital::set_hospital_name(string& hospital_name)
{
    this->hospital_name=hospital_name;
    return true;
}

department *hospital::check_department_exist(const string &departmentName)
{

    list<department>::iterator itr = this->departments_arr.begin();
    list<department>::iterator itrEnd = this->departments_arr.end();
    for (; itr != itrEnd; ++itr)
    {
        if (departmentName == itr->get_depName())
        {
            return &(*itr);
        }
    }
    return nullptr;
}

patient *hospital::find_patient_byId(const string &patient_id)
{

    list<patient>::iterator itr = this->patient_arr.begin();
    list<patient>::iterator itrEnd = this->patient_arr.end();
    for (; itr != itrEnd; ++itr)
    {
        if (patient_id == itr->get_person_id())
        {
            return &(*itr);
        }
    }
    return nullptr;
}

employee *hospital::find_employee_byId(const string &employeeId)
{
    list<employee *>::iterator itr = this->employee_arr.begin();
    list<employee *>::iterator itrEnd = this->employee_arr.end();
    for (; itr != itrEnd; ++itr)
    {
        if ((*itr)->get_person_id() == employeeId)
            return &(**itr);
    }
    return nullptr;
}

bool hospital::add_department_to_hospital(const string &departmentName)
{
    list<department>::iterator itr = this->departments_arr.begin();
    list<department>::iterator itrEnd = this->departments_arr.end();

    for (; itr != itrEnd; ++itr)
    {
        if (departmentName == itr->get_depName())
        {
            cout << "Already have department: " << departmentName << "in the hospital, cant add";
            return true;
        }
    }
    department department_in_hospital =  department(departmentName);
    departments_arr.push_back(department_in_hospital);
    return true;
}

bool hospital::add_doctor_to_hospital(const string& doctor_name, const string& dr_id,const string& dr_experties, const string& department_name)
{
    int flag=0;
    list<department>::iterator itr = this->departments_arr.begin();
    list<department>::iterator itrEnd = this->departments_arr.end();

    department *our_dep = check_department_exist(department_name);
    if (our_dep == nullptr)
    {
        cout << "The hospital dosent have department: " << department_name << "cant add this doctor to our hospita";
        return false;
    }
    
    doctor* doctor_in_hos = new doctor(doctor_name, dr_id,id_count++,dr_experties);
    employee_arr.push_back(doctor_in_hos);
	our_dep->add_doc_to_dep(*doctor_in_hos);
    return true;
}

bool hospital::add_researcher_to_hospital(const string& researcher_name, const string& researcher_id)
{
    researcher* researcher_in_hos = new researcher(researcher_name, researcher_id, id_count++);
    employee_arr.push_back(researcher_in_hos);
    this->hospital_research.add_researcher(researcher_in_hos);
    return true;
}

bool hospital::add_article(const string& pupDate, const string& articleName, const string& magazineName, const string& researcherId)
{
    researcher *researcher_article = nullptr;
    int flag = 0;
    list<researcher*>::const_iterator itr = this->hospital_research.get_researcher_arr().begin();
    list<researcher*>::const_iterator itrEnd = this->hospital_research.get_researcher_arr().end();

    if(itr==itrEnd)
    {
        return false;
    }

    for (; itr != itrEnd; ++itr)
    {
        if (researcherId == (*itr)->get_person_id())
        {
            researcher_article = *itr;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "Cant add this aticle, researcher doesnt exist";
        return false;
    }
    article articleToAdd=article(pupDate,articleName,magazineName);
    this->hospital_research.add_article(&articleToAdd);
    researcher_article->add_article_to_researcher(&articleToAdd);
    return true;
}


bool hospital::add_patient_to_hospital(const string& patient_id, const string& patient_name, int year, const string& gender)
{
    list<patient>::iterator itr = this->patient_arr.begin();
    list<patient>::iterator itrEnd = this->patient_arr.end();

    for (; itr != itrEnd; ++itr)
    {
        if (itr->get_person_id() == patient_id)
        {
            cout << "This patient" << patient_name << " already exists in the hospital.";
            return false;
            
        }
    }

    patient patient_in_hospital = patient(patient_name, patient_id, year, gender);
    patient_arr.push_back(patient_in_hospital);
    return true;
}

bool hospital::add_doctor_researcher_to_hospital(const string& d_r_name, const string& d_r_id, const string& dr_experties, const string& dr_department)
{
    int flag=0;
    list<department>::iterator itr = this->departments_arr.begin();
    list<department>::iterator itrEnd = this->departments_arr.end();
    
    department *our_dep = check_department_exist(dr_department);
    if (our_dep == nullptr)
    {
        cout << "The hospital dosent have department: " << dr_department << "cant add this doctor to our hospita";
        return false;
    }
    
    doctorResearcher* d_r = new doctorResearcher (d_r_name, d_r_id, id_count++, dr_experties);
    employee_arr.push_back(d_r);
	d_r->set_departmentPtr(our_dep);
    our_dep->add_doc_to_dep(*d_r);
    this->hospital_research.add_researcher(d_r);
    return true;
}

bool hospital::add_surgeon_to_hospital(const string &doctorName, const string &doctorId, const string &experties, const string &departmentName, int numberOfSurgeries)
{
    department *departmentDoctor = check_department_exist(departmentName);
    if (departmentDoctor == nullptr)
    {
        cout << "The hospital dosent have department: " << departmentName << "cant add this doctor to our hospita";
        return false;
    }
    surgeon *surgeon_in_hospital = new surgeon(doctorName,doctorId, id_count++, experties, numberOfSurgeries);
    departmentDoctor->add_doc_to_dep(*surgeon_in_hospital);
    this->employee_arr.push_back(surgeon_in_hospital);
    return true;
}



bool hospital::add_nurse_to_hospital(const string& nurse_name, const string& nurse_id,int nurse_experience, const string& department_name)
{
    int flag=0;
    list<department>::iterator itr = this->departments_arr.begin();
    list<department>::iterator itrEnd = this->departments_arr.end();
    department* our_dep;
    
    for (; itr != itrEnd; ++itr)
    {
        if (department_name == itr->get_depName())
        {
            flag = 1;
            our_dep = &(*itr); 
        }
    } 

    if(flag==0)
    {
        cout << "the hospital does not have department"<< department_name <<endl;
        cout << "cant add this nurse to our hospital"<<endl;
        return false;
    }

    nurse* nurse_in_hos = new nurse(nurse_name, nurse_id, id_count++, nurse_experience);
    employee_arr.push_back(nurse_in_hos);
	our_dep->add_nurse_to_dep(*nurse_in_hos);
    return true;
}

bool hospital::add_visit(const string& visitDate, const string& patientId, const string& visit_purbose, const string& dep_name, const string& employee_in_charge)
{
    int flag = 0;
    patient *patientVisit = nullptr;

    list<patient>::iterator itr = this->patient_arr.begin();
    list<patient>::iterator itrEnd = this->patient_arr.end();

    for (; itr != itrEnd; ++itr)
    {
        if (itr->get_person_id() == patientId)
        {
            flag = 1;
            patientVisit = &(*itr);
            break;
            
        }
    }

    department* dep =check_department_exist(dep_name);
    if(dep==nullptr)
    {
        return false;
    }
    employee* res_emp = find_employee_byId(patientId);
    if(res_emp==nullptr)
    {
        return false;
    }

    if (flag == 1)
    {
        visit *visit_in_hospital = new visit(visitDate, patientVisit, visit_purbose, dep, res_emp);
        visit_arr.push_back(visit_in_hospital);
        patientVisit->add_visit_patient(visit_in_hospital);
    }
    return true;
}

bool hospital::add_surgerieVisit(const string &visitDate, const string &patientId, int numSurgerieRoom, bool isFasting, const string& visit_purbose, const string& dep_name, const string& employee_in_charge)
{
    patient *patientVisit = find_patient_byId(patientId);
    if (patientVisit == nullptr)
    {
        cout << "The patient dos'nt exist in the hospital, cant add the visit.";
        return false;
    }
    department* dep =check_department_exist(dep_name);
    if(dep==nullptr)
    {
        return false;
    }
    employee* res_emp = find_employee_byId(patientId);
    if(res_emp==nullptr)
    {
        return false;
    }
    surgerieVisit *visit_in_hospital = new surgerieVisit(visitDate, patientVisit, visit_purbose, dep,res_emp, numSurgerieRoom, isFasting);
    patientVisit->add_visit_patient(visit_in_hospital);
    visit_arr.push_back(visit_in_hospital);
    return true;
}


ostream& operator<<(ostream& os, const hospital& hos)
{
    os << "------------------------- HOSPITAL DETAILS ------------------------------"<<endl;
    os << "hospital name: "<< hos.hospital_name<<endl<<endl;
    os << "***HOSPITAL RESEARCH***" << endl;
    os << hos.hospital_research<<endl;
    
    os << "----- HOSPITAL DEPARTMENTS -----" << endl << endl;

    list<department>::const_iterator itr_dep = hos.departments_arr.begin();
    list<department>::const_iterator itrEnd_dep = hos.departments_arr.end();

    if(itr_dep==itrEnd_dep)
    {
        return os;
    }

    for (; itr_dep != itrEnd_dep ; ++itr_dep)
    {
        os<< *itr_dep << endl;
    }

    list<patient>::const_iterator itr_p = hos.patient_arr.begin();
    list<patient>::const_iterator itrEnd_p = hos.patient_arr.end();

    if(itr_p==itrEnd_p)
    {
        return os;
    }

    for (; itr_p != itrEnd_p ; ++itr_p)
    {
        os<< *itr_p << endl;
    }

    list<visit*>::const_iterator itr_v = hos.visit_arr.begin();
    list<visit*>::const_iterator itrEnd_v = hos.visit_arr.end();

    if(itr_v==itrEnd_v)
    {
        return os;
    }

    for (; itr_v != itrEnd_v ; ++itr_v)
    {
        os<< **itr_v << endl;
    }

    return os;
}

hospital::~hospital()
{
    list<visit*>::const_iterator itr = visit_arr.begin();
    list<visit*>::const_iterator itrEnd = visit_arr.end();
    for (; itr != itrEnd ; ++itr)
    {
        delete *itr;
    }

    list<employee*>::const_iterator itr_emp = employee_arr.begin();
    list<employee*>::const_iterator itrEnd_emp = employee_arr.end();
    for (; itr_emp != itrEnd_emp ; ++itr_emp)
    {
        delete *itr_emp;
    }

}

