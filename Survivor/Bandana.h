#ifndef __BANDANA_H
#define __BANDANA_H

class Bandana 
{
    public:
        Bandana(char* color, int length);
        Bandana(const Bandana& other);
        Bandana(Bandana&& other);
        void operator=(const Bandana& other);

        const char* get_color() const;
        int get_length() const;

        ~Bandana();


    private:
        char* color;
        int length;

};

#endif