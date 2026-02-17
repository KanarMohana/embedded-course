#include <iostream>
#include <string.h>
#include "Doctor.h"
#include "department.h"
#include "hospital.h"
using namespace std;

int main()
{
    hospital hos("haifa", "research1");
    hos.add_department_to_hospital("kids");
    hos.add_doctor_to_hospital("kanar","123456", "lev", "kids");
    hos.add_nurse_to_hospital("sarah","1234567", 3, "kids");
    hos.add_patient_to_hospital("123456789", "Samya Faris", 1998, "Female");
    hos.add_patient_to_hospital("207570843", "Bsel Faris", 1998, "Female");
    hos.add_researcher_to_hospital("weaam", "111111");
    hos.add_doctor_researcher_to_hospital("melhem","222222", "lev", "kids");
    hos.add_article("2/2/2026", "news", "N12", "222222");
    hos.add_article("1/1/2026", "Sport", "N12", "111111");
    hos.add_visit("12/12/26", "123456789");
    hos.add_visit("13/07/26", "123456789");
    hos.add_visit("25/08/26", "207570843");
    cout << hos;
    // doctor d("kanar", 1, "women");
    // doctor d2("samya", 2, "heart department");
    // doctor d3("sarah", 3, "kids department");
    // department dep("dep1");
    // dep.add_doc_to_dep(d);
    // dep.add_doc_to_dep(d2);
    // dep.add_doc_to_dep(d3);
    // cout<<dep;
    // cout<<d;
    // return 0;
}