#include "charmander.h"
#ifndef CHARMANDER_CPP
#define CHARMANDER_CPP

Charmander::Charmander():Pokemon()
{
    index = 0;
}

Charmander::Charmander(int index1, string name, string type, int health_points, int attack, int defense):Pokemon(name, type, health_points, attack, defense)
{
    index = index1;
}

void Charmander::set_index(int index1)
{
    index = index1;
}

int Charmander::get_index()
{
    return index;
}

void Charmander::set_values()
    {   
        set_name("Charmander");
        set_type("Fire");
        set_health_points(39);
        set_attack(52);
        set_defense(43);
    }

#endif