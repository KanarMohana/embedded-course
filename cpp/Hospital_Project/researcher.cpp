#include <iostream>
#include <string.h>
using namespace std;
#include "researcher.h"

researcher::researcher(const employee &emp): employee(emp) , article_logical_size(0), article_physical_size(2)
{
    this->articles_arr=new article* [article_physical_size];
    for (int i=0;i<article_physical_size;i++)
    {
        articles_arr[i]=nullptr;
    }
}

researcher::researcher(const char* person_name, const char* person_id, int worker_id):employee(person_name, person_id, worker_id) , article_logical_size(0), article_physical_size(2)
{
    this->articles_arr=new article* [article_physical_size];
    for (int i=0;i<article_physical_size;i++)
    {
        articles_arr[i]=nullptr;
    }
}


researcher::researcher(employee &&e) : employee(std::move(e)), article_logical_size(0), article_physical_size(2)
{
    cout << "move researcher";

    this->articles_arr = new article *[article_physical_size];
    for (int i = 0; i < article_physical_size; i++)
    {
        articles_arr[i] = nullptr;
    }
}


article** researcher::get_articles_arr() const
{
    return articles_arr;
}

int researcher::get_article_logical_size() const
{
    return article_logical_size;
}

int researcher::get_article_physical_size() const
{
    return article_physical_size;
}

bool researcher::set_article_logical_size(int article_logical_size)
{
    this->article_logical_size=article_logical_size;
    return true;
}

bool researcher::set_article_physical_size(int article_physical_size)
{
    this->article_physical_size=article_physical_size;
    return true;
}

bool researcher::add_article_to_researcher(article *articlePtr)
{
    if (article_logical_size < article_physical_size)
    {
      this->articles_arr[article_logical_size] = articlePtr;
      set_article_logical_size(article_logical_size+1);
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
        articles_arr[article_logical_size] = articlePtr;
        set_article_logical_size(article_logical_size+1);
    }
    return true;
}

ostream& operator<<(ostream &os, const researcher &r)
{
    os << "RESEARCHER DETAILS:\n";
    os << (employee&)r;

    for (int i = 0; i < r.article_logical_size; i++)
    {
        os << "article " << (i+1) << ": ";
        if (r.articles_arr[i] == nullptr)
            os << "(null)\n";
        else
            os << *(r.articles_arr[i]) << "\n";
    }
    return os;
}

researcher::~researcher()
{
    if (!articles_arr) return;
    for (int i = 0; i < article_logical_size; ++i)
    {
        delete articles_arr[i];
    }
    cout << "researcher dtor, articles_arr=" << (void*)articles_arr << endl;

    delete[] articles_arr;
}