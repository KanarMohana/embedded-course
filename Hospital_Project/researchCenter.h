#ifndef __RESEARCH_CENTER_H
#define __RESEARCH_CENTER_H
#include <iostream>
using namespace std;
#include "researcher.h"
#include "article.h"

class research_center 
{
private:
    char* research_name;
    researcher ** researcher_arr;
    int researcher_logical_size;
    int researcher_physical_size;
    int article_logical_size;
    int article_physical_size;
    article **articles_arr;


public:
    research_center(const char* research_name);
    const char* get_research_name() const;
    bool set_research_name(const char* research_name);
    int get_researcher_logical_size();
    int get_researcher_physical_size();
    bool set_researcher_logical_size(int researcher_logical_size);
    bool set_researcher_physical_size(int researcher_physical_size);

    researcher ** get_researcher_arr();
    article **get_articles_arr();
    
    bool set_article_logical_size(int article_logical_size);
    bool set_article_physical_size(int article_physical_size);
    int get_article_logical_size();
    int get_article_physical_size();
    bool add_researcher(researcher* researcherToAdd);
    bool add_article(article *articleToAdd);

    ~research_center();
    friend ostream &operator<<(ostream &os, const research_center &r);

};

#endif