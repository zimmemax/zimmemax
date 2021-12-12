#include "pokemon.h"



class pokedex {

	private:
		int num_pokemon;
		pokemon *pokemon_array;

	public:
		//default
		
		~pokedex(); //Delete memory dynamically allocated for array of Pokemon
		pokedex(ifstream &file_name); //Read in the number of Pokemon and dynamically allocate memory for them
		void get_pokemon_info(ifstream &file_name); //Read in Pokemon data from file into array
		void search_by_dex_number(int); //Look through Pokemon array for one that matches the number passed in. If found, print to file. If not found, display an error message.
		void search_by_type(string); //Look through Pokemon array for ones that match the type passed in. If found, print to file. If not found, display an error message.
		void search_by_name(string);
		void add_pokemon(int, string, string, string, string, string, string);
		void menu(); //menu to interact with the user
		//stuff for file option
		void file_menu(string); //menu to interact with user if they choose to output into to file
		void search_by_dex_number_file(int, string); //Look through Pokemon array for one that matches the number passed in. If found, print to file. If not found, display an error message.
		void search_by_type_file(string, string); //Look through Pokemon array for ones that match the type passed in. If found, print to file. If not found, display an error message.
		void search_by_name_file(string, string);
		void add_pokemon_file(int, string, string, string, string, string, string, string);
	

};