#include "pokedex.h"

// Constructor that read pokemon data from the 
// given file and populate the pokemon_array list
pokedex::pokedex(ifstream &file) {
    int num, num_pokemon, i = 0;
    string name;
    string type;

    // Read number of pokemon_array
    file >> num_pokemon;

    // Allocate memory
    pokemon_array = new pokemon[num_pokemon];

    // Read the file until EOF
    while(!file.eof()) {
        // Read dex number
        file >> num;

        // Read pokemon name
        file >> name;

        // Read pokemon type
        file >> type;

        // Create a pokemon
        pokemon p(num, name, type);

        // Add to the list
        pokemon_array[i] = p;

        i++;
    }

    // Close the file
    file.close();

    this->num_pokemon = i;
}

// Destrctor to free memory
pokedex::~pokedex() {
    delete[] pokemon_array;
}

// Read pokemon data from the given file and
// populate the pokemon_array list
void pokedex::get_pokemon_info(ifstream &file) {
    int num, num_pokemon, i = 0;
    string name;
    string type;

    // Read number of pokemon_array
    file >> num_pokemon;

    // Allocate memory
    pokemon_array = new pokemon[num_pokemon];

    // Read the file until EOF
    while(!file.eof()) {
        // Read dex number
        file >> num;

        // Read pokemon name
        file >> name;

        // Read pokemon type
        file >> type;

        // Create a pokemon
        pokemon p(num, name, type);

        // Add to the list
        pokemon_array[i] = p;

        i++;
    }

    // Close the file
    file.close();

    this->num_pokemon = i;
}

// Search for pokemon having specified dex number
void pokedex::search_by_dex_number(int num) {
    bool found = false;

    // Open the output file for wrting
    ofstream outfile("outputs.txt", ios:: app);
    // Write the data
    outfile << "\n\nSearch pokemon by dex number: " << num << endl;

    // Iterate through the list
    for(int i = 0; i < num_pokemon; i++) {
        // If matching dex number found
        if(pokemon_array[i].get_dex() == num) {
            found = true;
            // Print to the file
            outfile << "pokemon Found: " << pokemon_array[i].get_name() << endl;
        }
    }

    // If pokemon not found
    if(!found) {
        outfile << "Error! pokemon having dex number " << num << " not found." << endl;
    }

    // Close the file
    outfile.close();
}

// Search for pokemom having specified type number
void pokedex::search_by_type(string type) {
    bool found = false;

    // Open the output file for wrting
    ofstream outfile("outputs.txt", ios:: app);
    // Write the data
    outfile << "\n\nSearch pokemon by type: " << type << endl;

    // Iterate through the list
    for(int i = 0; i < num_pokemon; i++) {
        // If matching pokemon type found
        if(pokemon_array[i].get_type() == type) {
            found = true;
            // Print to the file
            outfile << "pokemon Found: " << pokemon_array[i].get_name() << endl;
        }
    }

    // If pokemon not found
    if(!found) {
        outfile << "Error! pokemon having type " << type << " not found." << endl;
    }

    // Close the file
    outfile.close();
}


