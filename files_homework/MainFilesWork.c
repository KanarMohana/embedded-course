#include <stdio.h>
#include "fileswork.h"

int main(){
    Person Persons[3];

    char str1[] = "Afeef", str2[]="Adam", str3[]="Melhem";
    Persons[0].m_id=111111111;
    strcpy(Persons[0].m_name,str1);
    Persons[0].education = 12;
    Persons[0].age = 25;

    Persons[1].m_id=222222222;
    strcpy(Persons[1].m_name,str2);;
    Persons[1].education = 7;
    Persons[1].age = 13;

    Persons[2].m_id=333333333;
    strcpy(Persons[2].m_name,str3);;
    Persons[2].education = 13;
    Persons[2].age = 24;
    int t = write_persons(Persons, 3);
    letter_freq("persons.data");
    word_freq("persons.data");

    int c = binary_write_persons(Persons, 3);
    printf("%d\n", c);
    Person buffer[3];
    int r = binary_read_persons(buffer, 3);
    
    int f = read_persons();

    int y=print_last_n("persons.data",2);
    
        printf("\n--- Persons read from binary file ---\n");
        for (int i = 0; i < 3; i++) {
            printf("%d %s %d %d\n",
                   buffer[i].m_id,
                   buffer[i].m_name,
                   buffer[i].education,
                   buffer[i].age);
        }
    
}