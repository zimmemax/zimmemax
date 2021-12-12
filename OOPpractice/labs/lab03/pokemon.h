#include <iostream>
#ifndef POKEMON_H
#define POKEMON_H
#include <cstring>
#include <string>
#include <fstream>
using namespace std;



class pokemon {

	private:
		int dex_number;
		string name;
		string type;

	public:	
		//default
		pokemon();
		//parameter
		pokemon(int, string, string);

		//setter
		void set_dex(int); 
		void set_name(string);
		void set_type(string);
		//void set_moves(string[]);

		//getter
		int get_dex();
		string get_name();
		string get_type();
		//string get_moves();
		
		void print_pokemon();

};	



#endif
