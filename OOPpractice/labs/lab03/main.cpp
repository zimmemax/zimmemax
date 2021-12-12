#include <iostream>
#include "pokedex.h"
#include "pokemon.h"




int main(int argc, char* argv[]){
	ifstream inFile;
	string file_name = argv[1];
	inFile.open(file_name.c_str());
	while(1){
		if(inFile.fail())
		{
			cout << "Enter proper filename: ";
			cin >> file_name;
			//test
			inFile.open(file_name.c_str());
		}
		else
		{
			break;
		}
	}

	pokedex dex(inFile);
	 // Search pokemom by dex number 37
    dex.search_by_dex_number(37);

    // Search pokemom by type Grass
    dex.search_by_type("Grass");

    // Search pokemom by dex number 133
    dex.search_by_dex_number(133);

    // Search pokemom by type Water
    dex.search_by_type("Water");

    return 0;
}
	
	
	
	/*string temp_array[] = {"hug", "jump", "sit", "eat"};
	string temp_array1[] = {"hug1", "jump1", "sit1", "eat"};
	
	pokemon first(4, "Maxasuar", "Water", temp_array);
	pokemon second(1, "Beau", "Cat", temp_array1);

	pokemon temp_pokemon_array[2] = {first, second};
	pokedex dex1("Max", 2, temp_pokemon_array);
	first.print_pokemon();
	second.print_pokemon();
	
	dex1.set_pokemon_array(first);
	dex1.set_pokemon_array(second);
	*/

	
		



