#include <iostream>
#include <string.h>
#include "researchCenter.h"
using namespace std;

const char* research_center::get_research_name() const
{
    return research_name;
}

bool research_center::set_research_name(const char* research_name)
{
    delete[] this->research_name;
    this->research_name = new char[strlen(research_name)+1];
    strcpy(this->research_name,research_name);
    return true;
}

research_center::research_center(const char* research_name) : researcher_logical_size(0), researcher_physical_size(2)
{
    this->research_name= new char[strlen(research_name)+1];
    strcpy(this->research_name, research_name);
    this->researcher_arr = new researcher *[researcher_physical_size];
    for (int i = 0; i < researcher_physical_size; i++)
    {
        researcher_arr[i] = nullptr;
    }
}

int research_center::get_researcher_logical_size()
{
    return this->researcher_logical_size;
}

int research_center::get_researcher_physical_size()
{
    return this->researcher_physical_size;
}

int research_center::get_article_logical_size()
{
    return this->article_logical_size;
}

int research_center::get_article_physical_size()
{
    return this->article_physical_size;
}

article **research_center::get_articles_arr()
{
    return this->articles_arr;
}

bool research_center::set_article_logical_size(int article_logical_size)
{
    this->article_logical_size = article_logical_size;
    return true;
}
bool research_center::set_article_physical_size(int article_physical_size)
{
    this->article_physical_size = article_physical_size;
    return true;
}

bool research_center::set_researcher_logical_size(int researcher_logical_size)
{
    this->researcher_logical_size = researcher_logical_size;
    return true;
}

bool research_center::set_researcher_physical_size(int researcher_physical_size)
{
    this->researcher_physical_size = researcher_physical_size;
    return true;
}

researcher **research_center::get_researcher_arr()
{
    return this->researcher_arr;
}

bool research_center::add_researcher(researcher *researcherToAdd)
{
    if (researcher_logical_size < researcher_physical_size)
    {

        this->researcher_arr[researcher_logical_size] = researcherToAdd;
        set_researcher_logical_size(researcher_logical_size + 1);
    }
    else if (researcher_logical_size == researcher_physical_size)
    {
        researcher_physical_size *= 2;
        researcher **temp = new researcher *[researcher_physical_size];
        for (int i = 0; i < researcher_logical_size; i++)
        {
            temp[i] = researcher_arr[i];
        }
        delete[] researcher_arr;
        this->researcher_arr = temp;
        researcher_arr[researcher_logical_size] = researcherToAdd;
        set_researcher_logical_size(researcher_logical_size + 1);
    }
    return true;
}

bool research_center::add_article(article *articleToAdd)
{
    if (article_logical_size < article_physical_size)
    {

        this->articles_arr[article_logical_size] = articleToAdd;
        set_article_logical_size(article_logical_size + 1);
    }
    else if (article_logical_size == article_physical_size)
    {
        article_physical_size *= 2;
        article **temp = new article *[article_physical_size];
        for (int i = 0; i < article_logical_size; i++)
        {
            temp[i] = articles_arr[i];
        }
        delete[] articles_arr;
        this->articles_arr = temp;
        articles_arr[article_logical_size] = articleToAdd;
        set_article_logical_size(article_logical_size + 1);
    }
    return true;
}

research_center::~research_center()
{
    delete []research_name;
}

ostream &operator<<(ostream &os, const research_center &r)
{
    os <<  r.get_research_name();
    os << "----- Research Center Employee List  ----- \n";
    for (int i=0;i<r.researcher_logical_size;i++)
    {
        os<<*r.researcher_arr[i]<<"\n";
    }
    return os;
}
