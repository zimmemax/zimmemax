#include "bulbasaur.h"
#ifndef BULBASAUR_CPP
#define BULBASAUR_CPP

Bulbasaur::Bulbasaur():Pokemon()
{
    index = 2;
}

Bulbasaur::Bulbasaur(int index1, string name, string type, int health_points, int attack, int defense):Pokemon(name, type, health_points, attack, defense)
{
    index = index1;
}

void Bulbasaur::set_index(int index1)
{
    index = index1;
}

int Bulbasaur::get_index()
{
    return index;
}

void Bulbasaur::set_values()
    {
        set_name("Bulbasaur");
        set_type("Grass");
        set_health_points(45);
        set_attack(49);
        set_defense(49);
    }

#endif