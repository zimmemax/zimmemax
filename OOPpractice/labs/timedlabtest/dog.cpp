#ifndef DOG_CPP
#define DOG_CPP

#include "dog.h"
#include "pet.h"


Dog::Dog()
{
    breed = "";
}

Dog::Dog(string breed1)
{
    breed =  breed1;
}

void Dog::set_breed(string breed1)
{
    breed = breed1;
}

string Dog::get_breed()
{
    return breed;
}

string Dog::get_lifespan()
{
    if(weight > 100)
        return "approx 7 years";
    else
        return "approx 13 years";
}

#endif