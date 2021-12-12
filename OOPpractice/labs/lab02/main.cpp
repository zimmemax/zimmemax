#include <iostream>
#include "pokedex.h"
#include "pokemon.h"




int main(){
	
	string temp_array[] = {"hug", "jump", "sit", "eat"};
	string temp_array1[] = {"hug1", "jump1", "sit1", "eat"};
	
	pokemon first(4, "Maxasuar", "Water", temp_array);
	pokemon second(1, "Beau", "Cat", temp_array1);

	pokemon temp_pokemon_array[2] = {first, second};
	pokedex dex1("Max", 2, temp_pokemon_array);
	first.print_pokemon();
	second.print_pokemon();
	
	dex1.set_pokemon_array(first);
	dex1.set_pokemon_array(second);


	//first.print_pokemon();
	//second.print_pokemon();		


}
