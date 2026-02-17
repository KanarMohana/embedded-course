#include <iostream>
#include <string.h>
#include "Tribe.h"
#include "Survivor.h"
using namespace std;

void delete_group(Survivor** group, int size)
{
    for(int i=0; i<size;++i)
    {
        delete group[i];
    }
    delete []group;
}



void fill_tribe(Tribe& tribe)
{
    while (tribe.get_actual_survivors_num() < tribe.get_max_survivors())
    {
        char response[10];
        cout << "would you like to add a new survivor to the tribe? (yes/no)\n";
        cin >> response;

        if(strcmp(response, "no") == 0) break;
        if(strcmp(response, "yes") != 0) continue;

        char name[50];
        char color[50];
        int age;
        int statusInt;
        int len;

        cout << "Enter The Survivor Name Please:\n";
        cin >> name;

        cout << "Enter The Survivor Age Please:\n";
        cin >> age;

        cout << "Choose your marital status:\n";
        cout << "Press 0 for Single\n";
        cout << "Press 1 for Married\n";
        cout << "Press 2 for In a relationship\n";
        cin >> statusInt;

        cout << "Enter the bandana's color:\n";
        cin >> color;

        cout << "Enter the bandana's len:\n";
        cin >> len;

        Bandana b(color, len);
        tribe.addSurvivor(name, age, (Survivor::eStatus)statusInt, b); 
    }
}



int main()
{
    cout << "start to create tribe 1\n";
    cout << "what is the name of the tribe?\n";
    char name[10];
    cin >> name;
    cout << "how many survivors can be in the tribe?\n";
    int max;
    cin >> max;
    Tribe tribe_a(name, max);

    //tribe_a.initialize_Tribe(name, max);
    fill_tribe(tribe_a);

    cout << "start to create tribe 2\n";
    cout << "what is the name of the tribe?\n";
    char name2[10];
    cin >> name2;
    cout << "how many survivors can be in the tribe?\n";
    int max2;
    cin >> max2;
    Tribe tribe_b(name2, max2);

    //tribe_b.initialize_Tribe(name2, max2);
    fill_tribe(tribe_b);

    cout << tribe_a;
    cout << tribe_b;

    // tribe_a.print_tribe();
    // tribe_b.print_tribe();

    // tribe_a.delete_tribe();
    // tribe_b.delete_tribe();


    // int group1_size, group2_size;
    // int survivors1=0, survivors2=0;
    // Survivor **group1, **group2;
    // cout << "how many survivors are in the first group?" << "\n";
    // cin >> group1_size;
    // cout << "how many survivors are in the second group?" << "\n";
    // cin >> group2_size;

    // group1=new Survivor*[group1_size];
    // group2=new Survivor*[group2_size];

    // for(int i=0; i<group1_size; ++i)
    // {
    //     char response[5];
    //     cout << "would you like to add a new survivor to group 1\n";
    //     cin >> response;
        
    //     if (strcmp(response, "yes") == 0)
    //     {
    //         survivors1++;
    //         group1[i]=new Survivor;
    //         initialize_survivor(*group1[i]);
    //     }
    //     else { 
    //         break;
    //     }
    // }

    // for(int i=0; i<group2_size; ++i)
    // {
    //     char response[5];
    //     cout << "would you like to add a new survivor to group 2\n";
    //     cin >> response;

    //     if (strcmp(response, "yes") == 0)
    //     {
    //         survivors2++;
    //         group2[i]=new Survivor;
    //         initialize_survivor(*group2[i]);
    //     }
    //     else { 
    //         break;
    //     }
    // }


    // for(int i=0; i<survivors1; ++i)
    // {
    //     print_survivor(*group1[i]);
    // }

    // for(int i=0; i<survivors2; ++i)
    // {
    //     print_survivor(*group2[i]);
    // }

    // delete_group(group1,survivors1);
    // delete_group(group2, survivors2);
}
