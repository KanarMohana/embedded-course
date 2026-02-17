#include <iostream>
#include <string.h>
#include "article.h"
using namespace std;

article::article(const char* pub_date, const char* article_name, const char* magazine_name)
{
    this->pub_date=new char[strlen(pub_date)+1];
    strcpy(this->pub_date, pub_date);
    this->article_name=new char[strlen(article_name)+1];
    strcpy(this->article_name, article_name);
    this->magazine_name=new char[strlen(magazine_name)+1];
    strcpy(this->magazine_name, magazine_name);
}

article::article(const article& other)
{
    *this = other;
}

article::article(article&& other)
{
    this->pub_date=other.pub_date;
    other.pub_date=nullptr;
    this->article_name=other.article_name;
    other.article_name=nullptr;
    this->magazine_name=other.magazine_name;
    other.magazine_name=nullptr;
}

const article& article::operator=(const article &other)
{
    if(this != &other)
    {
        if(this->pub_date!=nullptr)
        {
            delete []this->pub_date;
        }
        this->pub_date = new char[strlen(other.pub_date)];
        strcpy(this->pub_date, other.pub_date);

        if(this->article_name!=nullptr)
        {
            delete []this->article_name;
        }
        this->article_name = new char[strlen(other.article_name)];
        strcpy(this->article_name, other.article_name);

        if(this->magazine_name!=nullptr)
        {
            delete []this->magazine_name;
        }
        this->magazine_name = new char[strlen(other.magazine_name)];
        strcpy(this->magazine_name, other.magazine_name);
    }
    return *this;
}
        
const char* article::get_pub_date() const
{
    return pub_date;
}

const char* article::get_article_name() const
{
    return article_name;
}

const char* article::get_magazine_name() const
{
    return magazine_name;
}

bool article::set_pub_date(const char* pub_date)
{
    delete this->pub_date;
    this->pub_date = new char[strlen(pub_date) + 1];
    strcpy(this->pub_date, pub_date);
    return true;
}

bool article::set_article_name(const char* article_name)
{
    delete this->article_name;
    this->article_name = new char[strlen(article_name) + 1];
    strcpy(this->article_name, article_name);
    return true;
}

bool article::set_magazine_name(const char* magazine_name)
{
    delete this->magazine_name;
    this->magazine_name = new char[strlen(magazine_name) + 1];
    strcpy(this->magazine_name, magazine_name);
    return true;
}

ostream &operator<<(ostream &os, const article &art)
{
    os<<"ARTICLE DETAILS: ";
    os << "Publish Date: " << art.get_pub_date() << "\n";
	os << "Article Name: " << art.get_article_name() << "\n";
	os << "Magazine Name: " << art.get_magazine_name() << "\n";
	return os;
}


article::~article()
{
    delete []pub_date;
    delete []article_name;
	delete []magazine_name;
}