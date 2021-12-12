#ifndef PET_CPP
#define PET_CPP

#include "pet.h"






Pet::Pet()
{
    weight = 0;
    name = "";
}

Pet::Pet(string name1, int weight1)
{
    name = name1;
    weight = weight1;
}

int Pet::get_weight()
{
    return weight;
}

string Pet::get_name()
{
    return name;
}

void Pet::set_name(string name1)
{
    name = name1;
}

void Pet::set_weight(int weight1)
{
    weight = weight1;
}

string Pet::get_lifespan()
{
    return "unkown lifespan";
}

#endif