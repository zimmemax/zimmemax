#include "pokedex.h"

// Constructor that read pokemon data from the 
// given file and populate the pokemon_array list
/*********************************************************************  
** Function: constructor
** Description:  load all info from .txt file
** Parameters:   ifstream object
** Pre-Conditions:  valid ifstream file
** Post-Conditions:  none
*********************************************************************/ 
pokedex::pokedex(ifstream &file) {
    int num, num_pokemon, i = 0;
    string name;
    string type;
    string move1;
    string move2;
    string move3;
    string move4;
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
        //read moves

        file >> move1;
        file >> move2;
        file >> move3;
        file >> move4;

        cout << move4;
        
         
        // Create a pokemon
        pokemon p(num, name, type, move1, move2, move3, move4);

        // Add to the list
        pokemon_array[i] = p;

        i++;
    }

    // Close the file
    file.close();

    this->num_pokemon = i;
    
}

/*********************************************************************  
** Function: ~pokedex
** Description:  destruct array
** Parameters:  none
** Pre-Conditions:  none
** Post-Conditions:  none
*********************************************************************/ 

// Destrctor to free memory
pokedex::~pokedex() {
    delete[] pokemon_array;
}
/*********************************************************************  
** Function: menu
** Description:  menu for user
** Parameters:  none
** Pre-Conditions:  file loaded properly
** Post-Conditions:  none
*********************************************************************/ 

void pokedex::menu()
{
    int input = 5;
    cout << "Enter what u tryna do" << endl;
        cout << "1 for search by dex" << endl;
        cout << "2 for search by name" << endl;
        cout << "3 for search by type" << endl;
        cout << "4 add new pokemon" << endl;
        cout << "OR enter 0 to quit then crtl + c" << endl << endl;
        cout << "Enter: ";
        cin >> input;
        cout << endl;
    while(input !=0)
    {
        
    
        if(input == 1)
        {
            int temp_dex_num = 0;
            cout << "Enter dex number to search for: ";
            cin >> temp_dex_num;
            cout << endl;
            search_by_dex_number(temp_dex_num);
        }
        else if(input == 2)
        {
            string temp_name;
            cout << "Enter the name you want to search for: ";
            cout << endl;
            cin >> temp_name;
            search_by_name(temp_name);

        }
        else if(input == 3)
        {
            string temp_type;
            cout << "Enter type you wish to search by: ";
            cout << endl;
            cin >> temp_type;
            search_by_type(temp_type);
        }

        else if(input == 4)
        {
            int new_dex_num;
            string new_name;
            string new_type;
            string new_move1;
            string new_move2;
            string new_move3;
            string new_move4;

            cout << "Enter dex number for pokemon: ";
            cin >> new_dex_num;
            cout << endl;

            cout << "Enter name for pokemon: ";
            cin >> new_name;
            cout << endl;

            cout << "Enter type for pokemon: ";
            cin >> new_type;
            cout << endl;

            cout << "Enter move: ";
            cin >> new_move1;
            cout << endl;

            cout << "Enter move: ";
            cin >> new_move2;
            cout << endl;

            cout << "Enter move: ";
            cin >> new_move3;
            cout << endl;

            cout << "Enter move: ";
            cin >> new_move4;
            cout << endl;




            add_pokemon(new_dex_num, new_name, new_type, new_move1, new_move2, new_move3, new_move4);

            

        }
        else if(input == 0){
            break;
        }
        else{
            cout << "enter correct number: ";
            cin >> input;
            cout << endl;
        }

        cout << "1 for search by dex" << endl;
        cout << "2 for search by name" << endl;
        cout << "3 for search by type" << endl;
        cout << "4 add new pokemon" << endl;
        cout << "OR enter 0 to quit then crtl + c" << endl << endl;
        cout << "Enter: ";
        cin >> input;
        cout << endl;



    }
}
/*********************************************************************  
** Function: file_menu
** Description:  menu if the user chooses the option to output info to a file
** Parameters:  a .txt file name
** Pre-Conditions:  valid .txt file name
** Post-Conditions:  none
*********************************************************************/ 

void pokedex::file_menu(string file_name)
{
    int input = 5;
    string file_name1 = file_name;
    cout << "Enter what u tryna do" << endl;
        cout << "1 for search by dex" << endl;
        cout << "2 for search by name" << endl;
        cout << "3 for search by type" << endl;
        cout << "4 add new pokemon" << endl;
        cout << "OR 0 to quit then ctrl c" << endl << endl;
        cout << "Enter: ";
        cin >> input;
        cout << endl;
    while(input !=0)
    {
        
    
        if(input == 1)
        {
            int temp_dex_num = 0;
            cout << "Enter dex number to search for: ";
            cin >> temp_dex_num;
            cout << endl;
            search_by_dex_number_file(temp_dex_num, file_name1);
        }
        else if(input == 2)
        {
            string temp_name;
            cout << "Enter the name you want to search for: ";
            cout << endl;
            cin >> temp_name;
            search_by_name_file(temp_name, file_name1);

        }
        else if(input == 3)
        {
            string temp_type;
            cout << "Enter type you wish to search by: ";
            cout << endl;
            cin >> temp_type;
            search_by_type_file(temp_type, file_name1);
        }

        else if(input == 4)
        {
            int new_dex_num;
            string new_name;
            string new_type;
            string new_move1;
            string new_move2;
            string new_move3;
            string new_move4;

            cout << "Enter dex number for pokemon: ";
            cin >> new_dex_num;
            cout << endl;

            cout << "Enter name for pokemon: ";
            cin >> new_name;
            cout << endl;

            cout << "Enter type for pokemon: ";
            cin >> new_type;
            cout << endl;

            cout << "Enter Move: ";
            cin >> new_move1;
            cout << endl;

            cout << "Enter Move: ";
            cin >> new_move2;
            cout << endl;

            cout << "Enter Move: ";
            cin >> new_move3;
            cout << endl;

            cout << "Enter Move: ";
            cin >> new_move4;
            cout << endl;

            add_pokemon_file(new_dex_num, new_name, new_type, new_move1, new_move2, new_move3, new_move4, file_name1);

            

        }
        else{
            cout << "enter correct number!!!!!!!!!: ";
            cin >> input;
            cout << endl;
        }

        cout << "1 for search by dex" << endl;
        cout << "2 for search by name" << endl;
        cout << "3 for search by type" << endl;
        cout << "4 add new pokemon" << endl;
        cout << "OR 0 to quit then ctrl c" << endl << endl;
        cout << "Enter: ";
        cin >> input;
        cout << endl;
        



    }
   


}

/*********************************************************************  
** Function: add_pokemon
** Description:  load user's input into the class
** Parameters:  all pokemon info parameters
** Pre-Conditions:  valid data types for fucntion
** Post-Conditions:  none
*********************************************************************/ 
void pokedex::add_pokemon(int num, string name, string type, string moves1, string moves2, string moves3, string moves4)
{
    int new_amount = num_pokemon + 1;
    pokemon_array = new pokemon[new_amount];

    pokemon_array[new_amount - 1].set_dex(num);
    pokemon_array[new_amount - 1].set_name(name);
    pokemon_array[new_amount - 1].set_type(type);
    pokemon_array[new_amount - 1].set_moves(moves1, moves2, moves3, moves4);
 


    cout << endl;

    cout << "Pokemon Added!!!!!!!";

    cout << endl << endl << endl;
}


/*********************************************************************  
** Function: search_by_dex_number
** Description:  search by dex
** Parameters:  none
** Pre-Conditions:  none
** Post-Conditions:  none
*********************************************************************/ 
void pokedex::search_by_dex_number(int num) {
    bool found = false;

    // Iterate through the list
    for(int i = 0; i < num_pokemon; i++) {
        // If matching dex number found
        if(pokemon_array[i].get_dex() == num) {
            found = true;
            // Print to the file
            cout << "pokemon found: " << pokemon_array[i].get_name() << endl;
            cout << "Moves1: " << pokemon_array[i].get_moves1() <<endl;
            cout << "Moves2: " << pokemon_array[i].get_moves2() <<endl;
            cout << "Moves3: " << pokemon_array[i].get_moves3() <<endl;
            cout << "Moves4: " << pokemon_array[i].get_moves4() <<endl;
        }
    }

    // If pokemon not found
    if(!found) {
        cout << "Error! pokemon having dex number " << num << " not found." << endl;
    }

}

/*********************************************************************  
** Function: search_by_type
** Description:  search pokemon by type of array
** Parameters:  type inputted by user
** Pre-Conditions:  none
** Post-Conditions:  none
*********************************************************************/ 
void pokedex::search_by_type(string type) {
    bool found = false;

   for(int i = 0; i < num_pokemon; i++) {
        // If matching pokemon type found
        if(pokemon_array[i].get_type() == type) {
            found = true;
            // Print to the file
            cout << "pokemon Found: " << pokemon_array[i].get_name() << endl;
            cout << pokemon_array[i].get_moves1() << endl;
            cout << pokemon_array[i].get_moves2() << endl;
            cout << pokemon_array[i].get_moves3() << endl;
            cout << pokemon_array[i].get_moves4() << endl;
        }
    }

    // If pokemon not found
    if(!found) {
        cout << "Error! pokemon having type " << type << " not found." << endl;
    }

}
/*********************************************************************  
** Function: search_by_name
** Description:  search for pokemon by inputted name
** Parameters:  all pokemon info parameters
** Pre-Conditions:  valid data types for fucntion
** Post-Conditions:  none
*********************************************************************/ 

void pokedex::search_by_name(string name)
{
    bool found = false;
    for(int i = 0; i < num_pokemon; i++)
    {
        if(pokemon_array[i].get_name() == name)
        {
            found = true;
            cout << "pokemon found: " << name << endl;
            cout << "Pokemon details are: " << endl;
            cout << "Dex Number: " << pokemon_array[i].get_dex() << endl;
            cout << "Type is: " << pokemon_array[i].get_type() << endl;
            cout << "Moves: " << pokemon_array[i].get_moves1() << endl;
            cout << "Moves: " << pokemon_array[i].get_moves2() << endl;
            cout << "Moves: " << pokemon_array[i].get_moves3() << endl;
            cout << "Moves: " << pokemon_array[i].get_moves4() << endl;

        }

    }
    if(!found){
        cout << "Error no pokemon exists with name:" << name << endl;
    }

}
/*********************************************************************  
** Function: search by dex
** Description:  find pokemon based on users input
** Parameters:  a number for the porgram to look for and a file name
** Pre-Conditions:  valid data types for function
** Post-Conditions:  none
*********************************************************************/ 
void pokedex::search_by_dex_number_file(int num, string file_name)
{
     bool found = false;
     ofstream outFile(file_name.c_str(), ios::app);
    
    // Iterate through the list
    for(int i = 0; i < num_pokemon; i++) {
        // If matching dex number found
        if(pokemon_array[i].get_dex() == num) {
            found = true;
            // Print to the file
            outFile << "pokemon found: " << pokemon_array[i].get_name() << endl;
            outFile << "Moves are: " << pokemon_array[i].get_moves1() <<endl;
            outFile << "Moves are: " << pokemon_array[i].get_moves2() <<endl;
            outFile << "Moves are: " << pokemon_array[i].get_moves3() <<endl;
            outFile << "Moves are: " << pokemon_array[i].get_moves4() <<endl;
        }
    }

    // If pokemon not found
    if(!found) {
        outFile << "Error! pokemon having dex number " << num << " not found." << endl;
    }

}
/*********************************************************************  
** Function: search by name
** Description:  find pokemon based on users input
** Parameters:  a name for the porgram to look for and a file name
** Pre-Conditions:  valid data types for function
** Post-Conditions:  none
*********************************************************************/ 
void pokedex::search_by_name_file(string name, string file_name)
{
    bool found = false;
    ofstream outFile(file_name.c_str(), ios::app);
    for(int i = 0; i < num_pokemon; i++)
    {
        if(pokemon_array[i].get_name() == name)
        {
            found = true;
            outFile << "pokemon found: " << name << endl;
            outFile << "Pokemon details are: " << endl;
            outFile << "Dex Number: " << pokemon_array[i].get_dex() << endl;
            outFile << "Type is: " << pokemon_array[i].get_type() << endl;
            outFile << "Moves: " << pokemon_array[i].get_moves1() << endl;
            outFile << "Moves: " << pokemon_array[i].get_moves2() << endl;
            outFile << "Moves: " << pokemon_array[i].get_moves3() << endl;
            outFile << "Moves: " << pokemon_array[i].get_moves4() << endl;

        }

    }
    if(!found){
        outFile << "no pokemon exists with name:" << name << endl;
    }

}
/*********************************************************************  
** Function: search by type
** Description:  find pokemon based on users input
** Parameters:  a type for the porgram to look for and a file name
** Pre-Conditions:  valid data types for function
** Post-Conditions:  none
*********************************************************************/ 

void pokedex::search_by_type_file(string type, string file_name) {
    bool found = false;
    ofstream outFile(file_name.c_str(), ios::app);

   for(int i = 0; i < num_pokemon; i++) {
        // If matching pokemon type found
        if(pokemon_array[i].get_type() == type) {
            found = true;
            // Print to the file
            outFile << "pokemon Found: " << pokemon_array[i].get_name() << endl;
            outFile << pokemon_array[i].get_moves1() << endl;
            outFile << pokemon_array[i].get_moves2() << endl;
            outFile << pokemon_array[i].get_moves3() << endl;
            outFile << pokemon_array[i].get_moves4() << endl;
        }
    }

    // If pokemon not found
    if(!found) {
        outFile << "Error! pokemon having type " << type << " not found." << endl;
    }

}
/*********************************************************************  
** Function: add_pokemon_file
** Description:  add pokemon to outfile
** Parameters:  all types of pokemon data
** Pre-Conditions:  valid data types for function
** Post-Conditions:  none
*********************************************************************/ 
void pokedex::add_pokemon_file(int num, string name, string type, string moves1, string moves2, string moves3, string moves4, string file_name)
{
    ofstream outFile(file_name.c_str(), ios::app); 
    int new_amount = num_pokemon + 1;
    pokemon_array = new pokemon[new_amount];

    pokemon_array[new_amount - 1].set_dex(num);
    pokemon_array[new_amount - 1].set_name(name);
    pokemon_array[new_amount - 1].set_type(type);
    pokemon_array[new_amount - 1].set_moves(moves1, moves2, moves3, moves4);

    outFile << pokemon_array[new_amount - 1].get_dex() << endl;
    outFile << pokemon_array[new_amount - 1].get_name() << endl;
    outFile << pokemon_array[new_amount - 1].get_type() << endl;
    outFile << pokemon_array[new_amount - 1].get_moves1() << endl;
    outFile << pokemon_array[new_amount - 1].get_moves2() << endl;
    outFile << pokemon_array[new_amount - 1].get_moves3() << endl;
    outFile << pokemon_array[new_amount - 1].get_moves4() << endl;


    outFile << "Pokemon Added!!!!!!!";

    outFile << endl << endl << endl;
}
