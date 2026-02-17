#ifndef __RESEARCHER_H
#define __RESEARCHER_H
#include "article.h"
#include "employee.h"
#include <string.h>
#include <list>
using namespace std;

class researcher : virtual public employee
{
    protected:
        static int researchers_num;
        list<article> articles_arr;
        //article** articles_arr;

    public:
        researcher(const string& person_name, const string& person_id, int worker_id);

        list<article> get_articles_arr() const;

        bool add_article_to_researcher(article* articlePtr);
        friend ostream &operator<<(ostream &os, const researcher &research);

};

#endif