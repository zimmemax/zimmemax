#include "squirtle.h"
#ifndef SQUIRTLE_CPP
#define SQUIRTLE_CPP

Squirtle::Squirtle():Pokemon()
{
    index = 1;
}

Squirtle::Squirtle(int index1, string name, string type, int health_points, int attack, int defense):Pokemon(name, type, health_points, attack, defense)
{
    index = index1;
}

void Squirtle::set_index(int index1)
{
    index = index1;
}

int Squirtle::get_index()
{
    return index;
}

void Squirtle::set_values()
    {
        set_name("Squirtle");
        set_type("Water");
        set_health_points(44);
        set_attack(48);
        set_defense(65);
    }

#endif