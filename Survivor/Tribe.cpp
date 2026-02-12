#include <iostream>
#include <string.h>
#include "Tribe.h"
using namespace std;

char* Tribe::get_name(){
    return name;
}

int Tribe::get_max_survivors()
{
    return max_survivors;
}

Survivor** Tribe::get_Sur_arr() const
{
    return Sur_arr;
}

int Tribe::get_actual_survivors_num() const
{
    return actual_survivors_num;
}

bool Tribe::set_name(char* _name)
{
    delete[] name;
    name = new char[strlen(_name)+1];
    strcpy(name,_name);
    return true;
}

bool Tribe::set_max_survivors(int _max_survivors)
{
    max_survivors = _max_survivors;
    return true;
}

bool Tribe::set_Sur_arr(Survivor** _Sur_arr)
{
    Sur_arr = _Sur_arr;
    return true;
}

bool Tribe::set_actual_survivors_num(int t_actual_survivors_num)
{
    actual_survivors_num = t_actual_survivors_num;
    return true;
}

bool Tribe::addSurvivor(char* name, int age, Survivor::eStatus status, Bandana& band)
{
    if (get_actual_survivors_num() >= max_survivors) 
    {
        return false;
    }
    Sur_arr[get_actual_survivors_num()] = new Survivor(name, age, status, band, this);

    //Sur_arr[actual_survivors_num]->initialize_survivor(name, age);
    set_actual_survivors_num( get_actual_survivors_num() + 1);
    
    return true;
}


void Tribe::initialize_Tribe(char* _name, int _max)
{
    set_name(_name);
    set_max_survivors(_max);
    set_actual_survivors_num(0);
    set_Sur_arr(new Survivor*[get_max_survivors()]);

    // for(int i=0; i<get_max_survivors(); ++i)
    // {
    //     char response[5];
    //     cout << "would you like to add a new survivor to the tribe? \n";
    //     cin >> response;
        
    //     if (strcmp(response, "yes") == 0)
    //     {
    //         addSurvivor(name, age);
    //     }
    //     else { 
    //         break;
    //     }
    // }
}

ostream& operator<< (ostream& os, const Tribe& tribe)
{
    for(int i=0; i<tribe.get_actual_survivors_num(); i++)
    {
        cout << *tribe.get_Sur_arr()[i] ;
        os << tribe.name << endl;
    }
    return os;
}

// void Tribe::print_tribe()
// {
//     for(int i=0; i<get_actual_survivors_num(); i++)
//     {
//         get_Sur_arr()[i]->print_survivor();
//     }
// }

void Tribe::delete_tribe()
{
    for(int i=0; i<get_actual_survivors_num();++i)
    {
        delete get_Sur_arr()[i];
    }
    delete []get_Sur_arr();
    set_Sur_arr(nullptr);
    set_max_survivors(0);
    set_actual_survivors_num(0);
}


