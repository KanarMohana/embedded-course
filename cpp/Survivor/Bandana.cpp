#include <iostream>
#include <string.h>
#include "Bandana.h"

using namespace std;

Bandana::Bandana(string color, int length)
{
    this->color = new char[strlen(color)+1];
    strcpy(this->color,color);
    this->length = length;
}

// Bandana::Bandana(const Bandana& other)
// {
//     if(this->color!=nullptr)
//     {
//         delete []this->color;
//     }
//     this->color = new char[strlen(other.color)+1];
//     strcpy(this->color, other.color);
//     this->length = other.length;
// }

Bandana::Bandana(const Bandana& other) : color(nullptr)
{
    *this=other;
}

Bandana::Bandana(Bandana&& other)
{
    this->color = other.color;
    other.color = nullptr;

    this->length = other.length;
}

void Bandana::operator=(const Bandana& other)
{
    if(this!=&other)
    {
        if(this->color!=nullptr)
        {
            delete []this->color;
        }
        this->color = new char[strlen(other.color)+1];
        strcpy(this->color, other.color);
        this->length = other.length;
    }
}

const string Bandana::get_color() const
{
    return color;
}

int Bandana::get_length() const
{
    return length;
}

Bandana::~Bandana()
{
    delete []color;
}

