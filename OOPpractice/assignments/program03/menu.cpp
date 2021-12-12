#ifndef MENU_CPP
#define MENU_CPP

#include "menu.h"
/*********************************************************************  
 ** Function:  constructor
 ** Description: set evertthing to zero
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions:  none
 *********************************************************************/  

Menu::Menu()
{
    user = "";
}
/*********************************************************************  
 ** Function:  user interaction
 ** Description: primarily interacts with user
 ** Parameters: inputtted map size from the user
 ** Pre-Conditions: none
 ** Post-Conditions:  none
 *********************************************************************/  

void Menu::user_interaction(int map_size)
{


   // cout << "HI" << endl;
    
	Map start_game(map_size);

   // cout << "HI" << endl;

    bool finish_game = false;
	int user_input;
	int play_again=1; 
	int map_selections_similar;
	
	start_game.random_event_selection();
    //cout << "hello";
	start_game.start_random_events();
    //cout <<"pee";
	start_game.display_grid();
    //cout <<"poo";
	start_game.event_check();
    //cout << "HI" << endl;
	
	do{
		while(!finish_game)
        {
		cout<<"1 TO MOVE A DIRECTION" << endl;
		cout <<"2 TO SHOOT AN ARROW" << endl;
		cout <<"0 TO EXIT" << endl;
		cout << "INPUT::::::: ";
		cin >>user_input;

		if(user_input ==1){
			if(start_game.set_direction() == 1){
				
				break;
			}
		}
		else if(user_input == 2){
			if(start_game.arrow_shot() == 1){
				break;
			}	
		}
		else if(user_input == 0){
			finish_game = true;
			play_again = 0;
			break;
		}
		start_game.display_grid();
	}
	if(user_input == 0){
		play_again = 0;
	}
	else{	
	cout << "1 to play Play Again" << endl;
    cout << "0 to stop" << endl;
    cout << "Enter ::::::: ";
	cin >>play_again;

	if(play_again == 1){
		cout<<"Same Board? (1) or reset?(0): ";
		cin>> map_selections_similar;
		if(map_selections_similar == 1){
			start_game.start_random_events();
			start_game.display_grid();
			
		}
		else if(map_selections_similar == 0){
			start_game.random_event_selection();
			start_game.start_random_events();
			start_game.display_grid();
		}
	}
}
	}while (play_again == 1);
}

/*********************************************************************  
 ** Function:  destrucor for menu
 ** Description: destructs data
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions:  none
 *********************************************************************/  

Menu::~Menu()
{

}





#endif