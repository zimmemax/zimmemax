#include <iostream>
#include "pokedex.h"
#include "pokemon.h"
/******************************************************
** Program: pokedex.cpp
** Author: Max Zimmer
** Date: 10/18/2021
** Description: user connects program to a .txt which constains information on a pokemon. Then, 
** the user chooses to either have the program output to the terminal or a new inputted .txt file.
** The user then is asked what information they would like to see by name, type, or dex number.
** Input: .txt file
** Output: pokemon information
******************************************************/




int main(int argc, char* argv[]){
	ifstream inFile;
	string file_name = argv[1];
	inFile.open(file_name.c_str());
	while(1){//test if valid file
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

	pokedex dex(inFile);//load file to pokedex
	int answer;
	cout << endl;
	cout << "Enter 1 to have info displayed in terminal or 2 to have code displayed on file: ";
	cin >> answer;
	cout << endl;

	while(answer != 1 || answer != 2)
	{
		if(answer == 1){
			dex.menu();
			cout << endl;
		}

		else if(answer == 2){
			string temp_name;
			cout << "Enter name of file (must be .txt): ";
			cin >> temp_name;
			dex.file_menu(temp_name);
			
			cout << endl;
		}
		else
			cout << "Enter correct number: ";
			cin >> answer;
			cout << endl;
	}
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

	
		



