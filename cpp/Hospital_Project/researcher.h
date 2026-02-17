#ifndef __RESEARCHER_H
#define __RESEARCHER_H
#include "article.h"
#include "employee.h"
#include <string.h>
using namespace std;

class researcher : virtual public employee
{
    protected:
        article** articles_arr;
        int article_logical_size;
        int article_physical_size;

    public:
        researcher(const employee& emp);
        researcher(employee &&e);
        researcher(const char* person_name, const char* person_id, int worker_id);

        
        article** get_articles_arr() const;
        int get_article_logical_size() const;
        int get_article_physical_size() const;

        bool set_article_logical_size(int article_logical_size);
        bool set_article_physical_size(int article_physical_size);

        bool add_article_to_researcher(article* articlePtr);
        friend ostream &operator<<(ostream &os, const researcher &research);

        ~researcher();
};

#endif