#ifndef __ARTICLE_H
#define __ARTICLE_H
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class article 
{
    private:
        string pub_date;
        string article_name;
        string magazine_name;
    public:
        article(const string& pub_date, const string& article_name, const string& magazine_name);
                
        const string& get_pub_date() const;
        const string& get_article_name() const;
        const string& get_magazine_name() const;

        bool set_pub_date(const string& pub_date);
        bool set_article_name(const string& article_name);
        bool set_magazine_name(const string& magazine_name);

        friend ostream &operator<<(ostream &os, const article &art);

};

#endif