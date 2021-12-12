#include "pokedex.h"



class pokedex {

	private:
		string trainer;
		int pokemon_amount;
		pokemon* pokemon_array;
		int pokemon_index;
		int initial_amount;

	public:
		//default
		pokedex();
		pokedex(string, int, pokemon[]);
		//setters
		void set_index(int);
		void set_trainer(string);
		void set_pokemon_amount(int);
		void set_pokemon_array(pokemon);
		void set_pokemon_index(int);
		
		//getter
		int get_index();
		string get_trainer();
		int get_pokemon_amount();
		pokemon* get_pokemon_array();
		int get_pokemon_index();


	

};
