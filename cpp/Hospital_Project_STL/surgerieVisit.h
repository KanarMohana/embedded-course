#ifndef __SURGERIESVISIT_H
#define __SURGERIESVISIT_H
#include <iostream>
#include "employee.h"
#include "visit.h"
using namespace std;
class department;

class surgerieVisit :   public visit
{

private:

int numSurgerieRoom;
bool isFasting;

public:
    surgerieVisit(const string& visit_date,  patient *patientPtrc, const string& visit_purbose, department* dep,employee* res_emp , int numSurgerieRoom,bool isFasting);
    int get_numSurgerieRoom()const;
    bool get_isFasting() const;
    bool set_numSurgerieRoom(const int numSurgerieRoom);
    bool set_numSurgerieRoom(const bool isFasting);
    friend ostream &operator<<(ostream &os, const surgerieVisit &s);
};

#endif