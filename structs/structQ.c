#include <stdio.h>
#include <string.h>
//adt 
typedef struct Person 
{
    int m_id;
    char m_name[30];
    int education;
    int age;
} Person;

union Data{
    int i_data;
    char* s_data;
};

int swap(Person *p1, Person *p2){
    Person temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    return 0;
}

int Sort_by_age(Person *personPtr, int _Size){
    for(int i=0; i<_Size; ++i){
        for(int j=i; j<_Size; ++j){
            if(personPtr[i].age > personPtr[j].age){
                swap(&personPtr[i],&personPtr[j]);
            }
        }
    }
    return 0;
}

int Sort_by_name(Person *personPtr, int _Size){
    for(int i=0; i<_Size; ++i){
        for(int j=i; j<_Size; ++j){
            int comparation = strcmp(personPtr[i].m_name, personPtr[j].m_name);
            if(comparation > 0){
                swap(&personPtr[i],&personPtr[j]);
            }
        }
    }
    return 0;
}

int print_persons_arr(Person *PersonsPtr, int _Size){
    for(int i=0; i<_Size; ++i){
    printf("the id is %d\n", PersonsPtr[i].m_id);
    printf("the name is %s\n", PersonsPtr[i].m_name);
    printf("the education is %d\n", PersonsPtr[i].education);
    printf("the age is %d\n", PersonsPtr[i].age);
    }
}

int main(){
    union Data d1;
    d1.i_data=3;
    d1.s_data="three";

    printf("%p %p\n", (void* )&d1.i_data, (void* )&d1.s_data);
    Person P1, *P2;
    P2 = &P1;
    int sort2;
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

    //sort = Sort_by_age(Persons, 3);
    sort2 = Sort_by_name(Persons, 3);


    print_persons_arr(Persons, 3);



    printf("enter your ID number \n");
    scanf("%d", &(P2->m_id));
    printf("enter your name \n");
    scanf("%s", P2->m_name);
    printf("enter your education \n");
    scanf("%d",&P2->education);
    printf("enter your age \n");
    scanf("%d", &P2->age);

    printf("the id is %d\n", P2->m_id);
    printf("the name is %s\n", P2->m_name);
    printf("the education is %d\n", P2->education);
    printf("the age is %d\n", P2->age);

}