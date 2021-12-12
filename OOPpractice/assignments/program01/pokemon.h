#include <iostream>
#ifndef POKEMON_H
#define POKEMON_H
#include <cstring>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;



class pokemon {

	private:
		int dex_number;
		string name;
		string type;
		string move1;
		string move2;
		string move3;
		string move4;

	public:	
		//default
		pokemon();
		//parameter
		pokemon(int, string, string, string, string, string, string);

		//setter
		void set_dex(int); 
		void set_name(string);
		void set_type(string);
		void set_moves(string, string, string, string);

		//getter
		int get_dex();
		string get_name();
		string get_type();
		string get_moves1();
		string get_moves2();
		string get_moves3();
		string get_moves4();
		
		void print_pokemon();

};	



#endif
