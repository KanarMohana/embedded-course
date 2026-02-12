#ifndef __SURVIVOR_H
#define __SURVIVOR_H
#include <iostream>
#include "Bandana.h"
using namespace std;

class Tribe;

class Survivor
{
    public:
        enum class eStatus
        {
            SINGLE,
            MARRIED,
            INRELATIONSHIP
        };

        //Survivor() {}

        Survivor(char *nameS, int ageS, eStatus statusS, Bandana& band, Tribe* tribe) : name(nullptr), bandana(band)
        {
            name = new char[strlen(nameS)+1];
            strcpy(name, nameS);
            age = ageS;
            status = statusS;
            id=counter++;
            this->tribe = tribe;
        }
        Survivor(Survivor& s)=delete;
        char* get_name();
        int get_age();
        bool set_name(char* name);
        bool set_age(int age);
        int get_id();
        Tribe* get_tribe();
        bool set_tribe(Tribe* tribe);
        const Bandana& get_bandana() const;

        //void initialize_survivor(char* _name, int _age, eStatus status, Bandana& band, Tribe* tribe);
        //void print_survivor();
        friend ostream& operator<< (ostream& os, const Survivor& sur);
        eStatus getStatus();
        bool setStatus(eStatus newStatus);
        ~Survivor(){ delete[] name; }


    private:
        Tribe* tribe;
        char* name;
        int age;
        eStatus status;
        Bandana bandana;
        static int counter;
        int id;

};

#endif


