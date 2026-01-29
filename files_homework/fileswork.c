#include <stdio.h>
#include <string.h>
#include "fileswork.h"
#define MAX_WORDS 100


typedef struct Person 
{
    int m_id;
    char m_name[30];
    int education;
    int age;
} Person;

int binary_write_persons(Person* _persons, int _Size){
    int c = 0;
    FILE *pdptr = fopen("persons.dat", "wb");
    if(pdptr == NULL){
        return 0;
    }

    else{
        c=fwrite(_persons, sizeof(Person), _Size, pdptr);
    }
    if(c==_Size){
        return 1;
    }
    fclose(pdptr);
}


int write_persons(Person *_persons, int Size){
    FILE *PDptr = fopen("persons.data", "w");
    if(PDptr == NULL){
        return 0;
    }
    else {
        for(int i=0; i<Size; ++i){
            fprintf(PDptr, "%s %d %d %d\n",
                 _persons[i].m_name,_persons[i].m_id,_persons[i].education,_persons[i].age );
        }
    }
    fclose(PDptr);
    return 0;
}

int binary_read_persons(Person* buffer, int size){
    FILE *fp = fopen("persons.dat", "r");
    if(fp == NULL){
        return 0;
    }

    int read = fread(buffer, sizeof(Person), size, fp);
    fclose(fp);

    return (read == (int)size) ? 1 : 0;
}


int read_persons(void){
    int id, education, age;
    char name[30];
    FILE *PDptr = fopen("persons.data", "r"); 

    if(PDptr == NULL){
        return 0;
    }

    else{
        fscanf(PDptr, "%s%d%d%d", name, &id, &education, &age);

        while(!feof(PDptr)){
            printf("%s  %d  %d  %d\n", name, id, education, age);
            fscanf(PDptr, "%s%d%d%d", name, &id, &education, &age);
            
        }
    }
    fclose(PDptr);
    return 1;
}

int print_last_n(char *filename, int _n){
    if(filename == NULL){
        return -1;
    }
    int count = 0;
    long pos;
    FILE *fptr= fopen(filename, "r");
    if(fptr == NULL){
        return 0;
    }
    fseek(fptr,0, SEEK_END);
    pos = ftell(fptr);
    
    while(pos>0 && count<_n+1){
        if(fgetc(fptr) == '\n'){
            count++;
        }
        pos--;
        fseek(fptr,pos,SEEK_SET);
    }
    char line[100];
    for(int i=0; i<=_n; i++){
        printf("%s", fgets(line, sizeof(line),fptr));
    }
    fclose(fptr);

} 

int my_wc(char *filename){
    int line_count = 0, word_count = 0;
    FILE *fptr = fopen(filename, "r");
    long pos;

    if(fptr == NULL){
        return 0;
    }

    fseek(fptr,0,SEEK_SET);
    while (!feof(fptr)){
        if(fgetc(fptr) == '\n'){
            line_count++;
        }

        if(fgetc(fptr) == ' '){
            fseek(fptr,-1,SEEK_CUR);
            if(fgetc(fptr)!=' '){
                fseek(fptr,2,SEEK_CUR);
                if(fgetc(fptr)!=' '){
                    word_count++;
                }
            }
        }
    }
}

int letter_freq(char *filename){
    FILE *fptr= fopen(filename, "r");
    int c;
    if(fptr == NULL){
        return 0;
    }

    int freq[255]={0};
    while(!feof(fptr)){
        c = fgetc(fptr);
        if(c>65 && c<122){
            freq[c]++;
        }
    }
    fclose(fptr);
    
    //print the frequences
    for(int i=65; i<122; i++){
        if(freq[i]!=0){
            printf("%c  %d\n",(char)i, freq[i]);
        }
    }
}

typedef struct freq {
    char word[20];
    int freq;
}freq;

int print_words_freq(freq *arr, int size){
    for (int i=0; i<size; ++i){
        printf("%s    %d\n",arr[i].word, arr[i].freq);
    }
}

int word_freq(char *filename){
    FILE *fptr = fopen(filename, "r");
    freq words[MAX_WORDS];
    char buffer[20];
    int words_num = 0;

    if (fptr == NULL){
        return 0;
    }
    else{
        while(fscanf(fptr, "%s", buffer) == 1){
            int exist = 0;

            for(int i=0; i<words_num; ++i){
                if(strcmp(words[i].word,buffer)==0){
                    words[i].freq++;
                    exist++;
                    break;
                }
            }
            if(exist==0){
                strcpy(words[words_num].word,buffer);
                words[words_num].freq = 1;
                words_num++;
            }
        }

        print_words_freq(words,words_num);
    }
}

