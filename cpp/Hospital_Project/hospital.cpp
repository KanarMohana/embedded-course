#include <iostream>
#include "hospital.h"

int hospital::id_count=0;

hospital::hospital(const char* hospital_name, const char* hospital_research) :  hospital_research(hospital_research), dr_logical_size(0), dr_physical_size(2), 
                                                                dep_logical_size(0),dep_physical_size(2)
                                                                , patient_logical_size(0), patient_physical_size(2),
                                                                               visit_logical_size(0), visit_physical_size(2)
                                                                               ,nurse_logical_size(0), nurse_physical_size(2)
                                                                               ,employee_physical_size(2), employee_logical_size(0) 
{
    this->hospital_name = new char[strlen(hospital_name)+1];
    strcpy(this->hospital_name,hospital_name);
    //this->hospital_research = *(new research_center(hospital_research));
    doctors_arr = new doctor*[dr_physical_size];
    for(int i=0; i<dr_physical_size; ++i)
    {
        doctors_arr[i]=nullptr;
    }
    departments_arr = new department*[dep_physical_size];
    for(int i=0; i<dep_physical_size; ++i)
    {
        departments_arr[i]=nullptr;
    }
    this->patient_arr = new patient *[patient_physical_size];
    for (int i = 0; i < patient_physical_size; i++)
    {
        this->patient_arr[i] = nullptr;
    }
    this->visit_arr = new visit *[visit_physical_size];
    for (int i = 0; i < visit_physical_size; i++)
    {
        this->visit_arr[i] = nullptr;
    }
    this->nurse_arr = new nurse *[nurse_physical_size];
    for (int i = 0; i < nurse_physical_size; i++)
    {
        this->nurse_arr[i] = nullptr;
    }
    this->employee_arr = new employee * [employee_physical_size]; //
	for (int i = 0; i < employee_physical_size; i++)
	{
		employee_arr[i] = nullptr;
	}
}

const char* hospital::get_hospital_name() const
{
    return hospital_name;
}

doctor** hospital::get_doctors_arr() const
{
    return doctors_arr;
}

department** hospital::get_department_arr() const
{
    return departments_arr;
}

int hospital::get_dr_logical_size() const
{
    return dr_logical_size;
}

int hospital::get_dep_logical_size() const
{
    return dep_logical_size;
}

int hospital::get_dr_physical_size() const
{
    return dr_physical_size;
}

int hospital::get_dep_physical_size() const
{
    return dep_physical_size;
}

int hospital::get_patient_logical_size() const
{
    return patient_logical_size;
}

int hospital::get_patient_physical_size() const
{
    return patient_physical_size;
}

int hospital::get_visit_logical_size() const
{
    return visit_logical_size;
}

int hospital::get_visit_physical_size() const
{
    return visit_physical_size;
}

int hospital::get_nurse_logical_size() const
{
    return nurse_logical_size;
}

int hospital::get_nurse_physical_size() const
{
    return nurse_physical_size;
}

bool hospital::set_hospital_name(char* hospital_name)
{
    delete[] this->hospital_name;
    this->hospital_name = new char[strlen(hospital_name)+1];
    strcpy(this->hospital_name,hospital_name);
    return true;
}

bool hospital::set_dr_logical_size(int dr_logical_size)
{
    this->dr_logical_size=dr_logical_size;
    return true;
}

bool hospital::set_dep_logical_size(int dep_logical_size)
{
    this->dep_logical_size=dep_logical_size;
    return true;
}

bool hospital::set_dr_physical_size(int dr_physical_size)
{
    this->dr_physical_size=dr_physical_size;
    return true;
}

bool hospital::set_dep_physical_size(int dep_physical_size)
{
    this->dep_physical_size=dep_physical_size;
    return true;
}

bool hospital::set_patient_logical_size(int patient_logical_size)
{
    this->patient_logical_size = patient_logical_size;
    return true;
}

bool hospital::set_patient_physical_size(int patient_physical_size)
{
    this->patient_physical_size = patient_physical_size;
    return true;
}

bool hospital::set_visit_logical_size(int visit_logical_size)
{
    this->visit_logical_size = visit_logical_size;
    return true;
}

bool hospital::set_visit_physical_size(int visit_physical_size)
{
    this->visit_physical_size = visit_physical_size;
    return true;
}

bool hospital::set_nurse_logical_size(int nurse_logical_size)
{
    this->nurse_logical_size = nurse_logical_size;
    return true;
}

bool hospital::set_nurse_physical_size(int nurse_physical_size)
{
    this->nurse_physical_size = nurse_physical_size;
    return true;
}

bool hospital::add_department_to_hospital(const char* department_name)
{
    for(int i=0; i<dep_logical_size; ++i)
    {
        if (strcmp((departments_arr[i])->get_depName(), department_name)==0)
        {
            cout << "the hospital already have department"<< department_name <<endl;
            return true;
        }
    }
    department* dep = new department(department_name);
    if (dep_physical_size==dep_logical_size)
    {
        dep_physical_size*=2;
        department** tmp=new department*[dep_physical_size];
        for(int i=0;i<dep_logical_size;i++)
        {
            tmp[i]=this->departments_arr[i];
        }
        delete []this->departments_arr;
        this->departments_arr = tmp;
    }
    this->departments_arr[dep_logical_size] = dep;
    dep_logical_size++;
    return true;
}

bool hospital::add_doctor_to_hospital(const char* doctor_name, const char* dr_id,const char* dr_experties, const char* department_name)
{
    int flag=0;
    department* our_dep;
    for(int i=0; i<dep_logical_size; i++)
    {
        if (strcmp((departments_arr[i])->get_depName(), department_name)==0)
        {
            flag = 1;
            our_dep = departments_arr[i];
        }
    } 

    if(flag==0)
    {
        cout << "the hospital does not have department"<< department_name <<endl;
        cout << "cant add this doctor to our hospital"<<endl;
        return false;
    }
    // person* p = new person(doctor_name, dr_id);
    // employee* emp = new employee(*p, id_count++);
    // doctor* doctor_in_hos = new doctor(*emp, dr_experties);
    doctor* doctor_in_hos = new doctor(doctor_name, dr_id,id_count++,dr_experties);
    // if (dr_physical_size==dr_logical_size)
    // {
    //     dr_physical_size*=2;
    //     doctor** tmp=new doctor*[dr_physical_size];
    //     for(int i=0;i<dr_logical_size;i++)
    //     {
    //         tmp[i]=this->doctors_arr[i];
    //     }
    //     delete []this->doctors_arr;
    //     this->doctors_arr = tmp;
    // }
    // this->doctors_arr[dr_logical_size] = doctor_in_hos;
    // our_dep->add_doc_to_dep(*doctor_in_hos);
    // dr_logical_size++;

    if (employee_logical_size < employee_physical_size) 
	{
		employee_arr[employee_logical_size] = doctor_in_hos;
		employee_logical_size++;
	} else
	{
		employee_physical_size *= 2;
		employee** temp = new employee * [employee_physical_size];
		for (int i = 0; i < employee_logical_size; i++)
		{
			temp[i] = employee_arr[i];
		}
		delete[] employee_arr;
		this->employee_arr = temp;
		employee_arr[employee_logical_size] = doctor_in_hos;
		employee_logical_size++; 
	}
	our_dep->add_doc_to_dep(*doctor_in_hos);
    return true;
}

bool hospital::add_researcher_to_hospital(const char* researcher_name, const char* researcher_id)
{
    // person* p = new person(researcher_name, researcher_id);
    // employee* emp = new employee(researcher_name, researcher_id, id_count++);
    researcher* researcher_in_hos = new researcher(researcher_name, researcher_id, id_count++);
    if (employee_logical_size < employee_physical_size) //
	{
		employee_arr[employee_logical_size] = researcher_in_hos;
		employee_logical_size++;
	} else
	{
		employee_physical_size *= 2;
		employee** temp = new employee * [employee_physical_size];
		for (int i = 0; i < employee_logical_size; i++)
		{
			temp[i] = employee_arr[i];
		}
		delete[] employee_arr;
		this->employee_arr = temp;
		employee_arr[employee_logical_size] = researcher_in_hos;
		employee_logical_size++; //
	}
    this->hospital_research.add_researcher(researcher_in_hos);

    //cout << "researcher: "<< *researcher_in_hos;
    return true;
}

bool hospital::add_article(const char *pupDate, const char *articleName, const char *magazineName, const char *researcherId)
{
    researcher *researcher_article = nullptr;
    int flag = 0;
    for (int i = 0; i < this->hospital_research.get_researcher_logical_size(); i++)
    {

        if (strcmp(researcherId, this->hospital_research.get_researcher_arr()[i]->get_person_id()) == 0)
        {
            researcher_article = hospital_research.get_researcher_arr()[i];
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "Cant add this aticle, researcher doesnt exist";
        return false;
    }
    article * articleToAdd=new article(pupDate,articleName,magazineName);
    this->hospital_research.add_article(articleToAdd);
    researcher_article->add_article_to_researcher(articleToAdd);
    return true;
}


bool hospital::add_patient_to_hospital(const char *patient_id, const char *patient_name, const int year, const char *gender)
{
    for (int i = 0; i < patient_logical_size; i++)
    {
        if (strcmp(patient_arr[i]->get_person_id(), patient_id) == 0)
        {
            cout << "This patient" << patient_name << " already exists in the hospital.";
            return false;
        }
    }

    //person* p1 = new person(patient_name, patient_id);
    patient *patient_in_hospital = new patient(patient_name, patient_id, year, gender);
    if (patient_logical_size < patient_physical_size)
    {
        patient_arr[patient_logical_size] = patient_in_hospital;
        set_patient_logical_size(patient_logical_size + 1);
    }
    else
    {
        patient_physical_size *= 2;
        patient **temp = new patient *[patient_physical_size];
        for (int i = 0; i < patient_physical_size; i++)
        {
            temp[i] = patient_arr[i];
        }
        delete[] patient_arr;
        this->patient_arr = temp;
        patient_arr[patient_logical_size] = patient_in_hospital;
        set_patient_logical_size(patient_logical_size + 1);
    }

    return true;
}

bool hospital::add_doctor_researcher_to_hospital(const char* d_r_name, const char* d_r_id, const char* dr_experties, const char* dr_department)
{
    int flag=0;
    department* our_dep;
    for(int i=0; i<dep_logical_size; i++)
    {
        if (strcmp((departments_arr[i])->get_depName(), dr_department)==0)
        {
            flag = 1;
            our_dep = departments_arr[i];
            break;
        }

    } 

    if(flag==0)
    {
        cout << "the hospital does not have department"<< dr_department <<endl;
        cout << "cant add this doctor to our hospital"<<endl;
        return false;
    }
    
    doctorResearcher* d_r = new doctorResearcher (d_r_name, d_r_id, id_count++, dr_experties);
    if (employee_logical_size < employee_physical_size) //
	{
		employee_arr[employee_logical_size] = d_r;
		employee_logical_size++;
	} else
	{
		employee_physical_size *= 2;
		employee** temp = new employee * [employee_physical_size];
		for (int i = 0; i < employee_logical_size; i++)
		{
			temp[i] = employee_arr[i];
		}
		delete[] employee_arr;
		this->employee_arr = temp;
		employee_arr[employee_logical_size] = d_r;
		employee_logical_size++; //
	}
	d_r->set_departmentPtr(our_dep);
    our_dep->add_doc_to_dep(*d_r);
    this->hospital_research.add_researcher(d_r);
    //cout << "***********************88" << *d_r;
    // cout << "***********************88" <<endl;
    // if (dr_physical_size==dr_logical_size)
    // {
    //     dr_physical_size*=2;
    //     doctor** tmp=new doctor*[dr_physical_size];
    //     for(int i=0;i<dr_logical_size;i++)
    //     {
    //         tmp[i]=this->doctors_arr[i];
    //     }
    //     delete []this->doctors_arr;
    //     this->doctors_arr = tmp;
    // }
    // this->doctors_arr[dr_logical_size] = doctor_in_hos;
    // our_dep->add_doc_to_dep(*doctor_in_hos);
    // dr_logical_size++;
    return true;
}


bool hospital::add_nurse_to_hospital(const char* nurse_name, const char* nurse_id,int nurse_experience, const char* department_name)
{
    int flag=0;
    department* our_dep;
    for(int i=0; i<dep_logical_size; i++)
    {
        if (strcmp((departments_arr[i])->get_depName(), department_name)==0)
        {
            flag = 1;
            our_dep = departments_arr[i];
        }

    } 

    if(flag==0)
    {
        cout << "the hospital does not have department"<< department_name <<endl;
        cout << "cant add this nurse to our hospital"<<endl;
        return false;
    }
   /* person* p = new person(nurse_name, nurse_id);
    employee* emp = new employee(*p, id_count++);
    nurse* nurse_in_hos = new nurse(*emp, nurse_experience);*/
    // if (nurse_physical_size==nurse_logical_size)
    // {
    //     nurse_physical_size*=2;
    //     nurse** tmp=new nurse*[nurse_physical_size];
    //     for(int i=0;i<nurse_logical_size;i++)
    //     {
    //         tmp[i]=this->nurse_arr[i];
    //     }
    //     delete []this->nurse_arr;
    //     this->nurse_arr = tmp;
    // }
    nurse* nurse_in_hos = new nurse(nurse_name, nurse_id, id_count++, nurse_experience);
    if (employee_logical_size < employee_physical_size) 
	{
		employee_arr[employee_logical_size] = nurse_in_hos;
	} else
	{
		employee_physical_size *= 2;
		employee** temp = new employee * [employee_physical_size];
		for (int i = 0; i < employee_logical_size; i++)
		{
			temp[i] = employee_arr[i];
		}
		delete[] employee_arr;
		this->employee_arr = temp;
		employee_arr[employee_logical_size] = nurse_in_hos;
		employee_logical_size++; 
	}
	our_dep->add_nurse_to_dep(*nurse_in_hos);
    return true;
}

bool hospital::add_visit(const char *visitDate, const char *patientId)
{
    int flag = 0;
    patient *patientVisit = nullptr;
    for (int i = 0; i < patient_logical_size; i++)
    {
        if (strcmp(patientId, patient_arr[i]->get_person_id()) == 0)
        {
            flag = 1;
            patientVisit = patient_arr[i];
        }
    }
    if (flag == 1)
    {
        visit *visit_in_hospital = new visit(visitDate, patientVisit);
        if (visit_logical_size < visit_physical_size)
        {
            visit_arr[visit_logical_size] = visit_in_hospital;
            set_visit_logical_size(visit_logical_size + 1);
        }
        else
        {
            visit_physical_size *= 2;
            visit **temp = new visit *[visit_physical_size];
            for (int i = 0; i < visit_physical_size; i++)
            {
                temp[i] = visit_arr[i];
            }
            delete[] visit_arr;
            this->visit_arr = temp;
            visit_arr[visit_logical_size] = visit_in_hospital;
            set_visit_logical_size(visit_logical_size + 1);
        }
        patientVisit->add_visit_patient(visit_in_hospital);

        return true;
    }
    return false;
}


ostream& operator<<(ostream& os, const hospital& hos)
{
    os << "HOSPITAL DETAILS:"<<endl;
    os << "hospital name: "<< hos.hospital_name<<endl;
    os << "hospital research: "<<hos.hospital_research<<endl;
    for (int i=0; i<hos.dep_logical_size; i++)
    {
        os << *hos.departments_arr[i] << endl;
    }
    for (int i = 0; i < hos.patient_logical_size; i++)
    {
        os << *(hos.patient_arr[i]);
    }

    for(int i=0;i<hos.visit_logical_size;i++)
    {
        os << *(hos.visit_arr[i]);
    }
    for(int i=0;i<hos.employee_logical_size;i++)
    {
        os << *(hos.employee_arr[i]);
    }
    return os;
}



hospital::~hospital()
{
    delete []hospital_name;
    for(int i=0; i<dr_logical_size; i++)
    {
        delete doctors_arr[i];
    }
    delete []doctors_arr;

    for(int i=0; i<dep_logical_size; i++)
    {
        delete departments_arr[i];
    }
    delete []departments_arr;

    for(int i=0; i<visit_logical_size; i++)
    {
        delete visit_arr[i];
    }
    delete []visit_arr;

    for(int i=0; i<nurse_logical_size; i++)
    {
        delete nurse_arr[i];
    }
    delete []nurse_arr;
}