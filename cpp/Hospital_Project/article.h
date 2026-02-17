#ifndef __ARTICLE_H
#define __ARTICLE_H
#include <iostream>
using namespace std;

class article 
{
    private:
        char* pub_date;
        char* article_name;
        char* magazine_name;
    public:
        article(const char* pub_date, const char* article_name, const char* magazine_name);
        article(const article& other);
        article(article&& other);
        const article& operator=(const article &other);
        
        const char* get_pub_date() const;
        const char* get_article_name() const;
        const char* get_magazine_name() const;

        bool set_pub_date(const char* pub_date);
        bool set_article_name(const char* article_name);
        bool set_magazine_name(const char* magazine_name);

        friend ostream &operator<<(ostream &os, const article &art);


        ~article();
};

#endif