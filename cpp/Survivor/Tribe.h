#ifndef __TRIBE_H
#define __TRIBE_H

#include <iostream>
#include "Survivor.h"
using namespace std;

class Tribe
{
    public:
        Tribe(char *nameT, int maxnum) : name(nameT)
        {
            name = new char[strlen(nameT)+1];
            strcpy(name, nameT);
            max_survivors = maxnum;
            Sur_arr = new Survivor *[maxnum];
            actual_survivors_num=0;
        }
        Tribe(Tribe &t) = delete;
        ~Tribe()
        {
            for (int i = 0; i < actual_survivors_num; i++)
            {
                //delete []Sur_arr[i]->get_name();
                delete Sur_arr[i];
            }
            delete []Sur_arr;
            delete []name;
        }

        string get_name();
        int get_max_survivors();
        Survivor** get_Sur_arr() const;
        int get_actual_survivors_num() const;

        bool set_name(string name);
        bool set_max_survivors(int max_survivors);
        bool set_Sur_arr(Survivor** Sur_arr);
        bool set_actual_survivors_num(int actual_survivors_num);
        
        void initialize_Tribe(string _name, int _max);
        friend ostream& operator<< (ostream& os, const Tribe& tribe);
        //void print_tribe();
        void delete_tribe();
        bool addSurvivor(string name, int age, Survivor::eStatus status, Bandana& band);

    private:
        string name;
        int max_survivors;
        Survivor **Sur_arr;
        int actual_survivors_num;
};

#endif
