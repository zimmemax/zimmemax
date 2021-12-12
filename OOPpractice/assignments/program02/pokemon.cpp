#include "pokemon.h"
#ifndef POKEMON_CPP
#define POKEMON_CPP

Pokemon::Pokemon(){

	name = "";
	type = "";
    health_points = 0;
    attack = 0;
    defense = 0;
	
}




Pokemon::Pokemon(string ename, string etype, int ehealth_points, int eattack, int edefense){

	name = ename;
	type = etype;
    health_points = ehealth_points; 
    attack = eattack;
    defense = edefense;
	
	


}



void Pokemon::set_type(string etype){

	type = etype;

}



void Pokemon::set_name(string ename){

	name = ename;

}

void Pokemon::set_health_points(int ehealth_points)
{
    health_points = ehealth_points;
}

void Pokemon::set_attack(int eattack)
{
    attack = eattack;
}
void Pokemon::set_defense(int edefense)
{
    defense = edefense;
}


string Pokemon::get_name(){

	return name;
}

string Pokemon::get_type(){

	return type;

}
int Pokemon::get_health_points()
{
    return health_points;
}

int Pokemon::get_attack()
{
    return attack;
}
int Pokemon::get_defense()
{
    return defense;
}

#endif
