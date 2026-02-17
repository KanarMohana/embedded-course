#include <iostream>
#include <string.h>
#include "researchCenter.h"
using namespace std;


research_center::research_center(const string& research_name) 
{
    this->research_name= research_name;
}

const string& research_center::get_research_name() const
{
    return research_name;
}

bool research_center::set_research_name(const string& research_name)
{
    this->research_name=research_name;
    return true;
}

const list<article>& research_center::get_articles_arr()
{
    return this->articles_arr;
}

const list<researcher*>& research_center::get_researcher_arr()
{
    return this->researcher_arr;
}

bool research_center::add_researcher(researcher *researcherToAdd)
{
    researcher_arr.push_back(researcherToAdd);
    return true;
}

bool research_center::add_article(article *articleToAdd)
{
    articles_arr.push_back(*articleToAdd);
    return true;
}

ostream &operator<<(ostream &os, const research_center &r)
{
    os << "research name: " << r.get_research_name() << endl;

    os << "\n\n----- Research Center Employee List  ----- \n" << endl;

    list<researcher*>::const_iterator itr = r.researcher_arr.begin();
    list<researcher*>::const_iterator itrEnd = r.researcher_arr.end();

    if(itr==itrEnd)
    {
        return os;
    }

    for (; itr != itrEnd ; ++itr)
    {
        os<< **itr << endl;
    }
    return os;
}
