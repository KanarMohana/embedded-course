#include <iostream>
#include <string.h>
#include "employee.h"
using namespace std;


employee::employee(const string& person_name, const string& person_id, int worker_id):person(person_name, person_id)
{
    this->worker_id = worker_id;
}


int employee::get_worker_id() const
{
    return worker_id;
}

bool employee::set_worker_id(int worker_id)
{
    this->worker_id=worker_id;
    return true;
}

ostream &operator<<(ostream &os, const employee &emp)
{
    os << (person&)emp;
    os << "worker id: " << emp.worker_id << endl;
    return os;
}
