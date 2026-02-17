#ifndef __BANDANA_H
#define __BANDANA_H

class Bandana 
{
    public:
        Bandana(string color, int length);
        Bandana(const Bandana& other);
        Bandana(Bandana&& other);
        void operator=(const Bandana& other);

        const string get_color() const;
        int get_length() const;

        ~Bandana();


    private:
        string color;
        int length;

};

#endif