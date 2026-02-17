#include <iostream>
#include <string.h>
using namespace std;
#include "researcher.h"


researcher::researcher(const string& person_name, const string& person_id, int worker_id):employee(person_name, person_id, worker_id) 
{
    // this->articles_arr=new article* [article_physical_size];
    // for (int i=0;i<article_physical_size;i++)
    // {
    //     articles_arr[i]=nullptr;
    // }
}


list<article> researcher::get_articles_arr() const
{
    return articles_arr;
}


bool researcher::add_article_to_researcher(article *articlePtr)
{
    articles_arr.push_back(*articlePtr);
    // if (article_logical_size < article_physical_size)
    // {
    //   this->articles_arr[article_logical_size] = articlePtr;
    //   ++article_logical_size;
    // }
    // else if (article_logical_size == article_physical_size)
    // {
    //     article_physical_size *= 2;
    //     article **temp = new article *[article_physical_size];
    //     for (int i = 0; i < article_logical_size; i++)
    //     { 
    //         temp[i] = articles_arr[i];
    //     }
    //     delete[] articles_arr;
    //     this->articles_arr = temp;
    //     articles_arr[article_logical_size] = articlePtr;
    //     ++article_logical_size;
    // }
    return true;
}

int researcher::researchers_num=1;

ostream& operator<<(ostream &os, const researcher &r)
{
    os << "RESEARCHER " << r.researchers_num++ <<" DETAILS:\n" << endl;
    os << (employee&)r;

    list<article>::const_iterator itr = r.articles_arr.begin();
    list<article>::const_iterator itrEnd = r.articles_arr.end();
   
    for (; itr != itrEnd; ++itr)
    {
        os << *itr;
        //os << "article " << itr->get_article_name();
    }
    return os;
}

