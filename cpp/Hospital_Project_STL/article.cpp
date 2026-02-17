#include <iostream>
#include <string.h>
#include "article.h"
using namespace std;

article::article(const string& pub_date, const string& article_name, const string& magazine_name)
{
    this->pub_date=pub_date;
    this->article_name=article_name;
    this->magazine_name=magazine_name;
}
        
const string& article::get_pub_date() const
{
    return pub_date;
}

const string& article::get_article_name() const
{
    return article_name;
}

const string& article::get_magazine_name() const
{
    return magazine_name;
}

bool article::set_pub_date(const string& pub_date)
{
    this->pub_date = pub_date;
    return true;
}

bool article::set_article_name(const string& article_name)
{
    this->article_name = article_name;
    return true;
}

bool article::set_magazine_name(const string& magazine_name)
{
    this->magazine_name = magazine_name;
    return true;
}

ostream &operator<<(ostream &os, const article &art)
{
    os<<"ARTICLE DETAILS: "<<endl;
    os << "Publish Date: " << art.get_pub_date() << "\n";
	os << "Article Name: " << art.get_article_name() << "\n";
	os << "Magazine Name: " << art.get_magazine_name() << "\n";
	return os;
}

