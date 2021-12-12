#ifndef DOG_H
#define DOG_H

#include "pet.h"


class Dog : public Pet
{
    private:
        string breed;

    public:
        Dog();
        Dog(string);
        string get_breed();
        void set_breed(string);
        string get_lifespan();

};

#endif