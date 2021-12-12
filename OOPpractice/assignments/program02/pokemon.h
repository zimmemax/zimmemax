#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#ifndef POKEMON_H
#define POKEMON_H

using namespace std;

class Pokemon {

	public:	
		string name;
		string type;
        int health_points;
        int attack;
        int defense;

	
		//default
		Pokemon();
		//parameter
		Pokemon(string, string, int, int, int);

		//setter 
		void set_name(string);
		void set_type(string);
		void set_health_points(int);
        void set_attack(int);
        void set_defense(int);

		//getter
		string get_name();
		string get_type();
        int get_health_points();
        int get_attack();
        int get_defense();

		


};	
#endif