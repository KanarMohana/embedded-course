#ifndef __RESEARCH_CENTER_H
#define __RESEARCH_CENTER_H
#include <iostream>
#include <string.h>
#include <list>
using namespace std;
#include "researcher.h"
#include "article.h"

class research_center 
{
private:
    string research_name;
    
    list<article> articles_arr;
    list<researcher*> researcher_arr;


public:
    research_center(const string& research_name);
    const string& get_research_name() const;
    bool set_research_name(const string& research_name);
    const int get_researcher_logical_size() const;
    

    const list<researcher*>& get_researcher_arr();
    const list<article>& get_articles_arr();
    
    bool add_researcher(researcher* researcherToAdd);
    bool add_article(article *articleToAdd);

    friend ostream &operator<<(ostream &os, const research_center &r);
};

#endif