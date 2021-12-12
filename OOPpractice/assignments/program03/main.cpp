
/******************************************************
** Program: wumpus.cpp
** Author: Max Zimmer
** Date: 11/22/2021
** Description: Write a C++ program that utilizes polymorphism and the
 Standard Template Library to create a game that allows the user 
to to interact with the program to retrieve gold and win the game.
 The user will spawn in a random room of a 4x4 grid (16 possibilities)
 and within the grid contains separate rooms with the monster, 2 bat rooms, 
 2 bottomless pit rooms and 1 gold room. The user must navigate through the
  rooms to get to the gold, then come back to the room they started in.
The user has 4 arrows they can fire in any direction and if any hit wumpus he dies.
If the user runs into the bat rooms they are transported back to spawn. If the user
 runs into a bottomless pit room, they die and are presented with the options of either 
 quitting or restarting the game with the same layout or a different layout. If the user
gets to the gold room they must navigate back to the starting room to win the game.
 If the user is within one tile of the bottomless pit room or a bat room,
  a specific message will print in the terminal.
 
** Input: various inputs by the user, either by moving or shooting arrows
** Output: info about the cave, wumpus, and the different rooms
******************************************************/

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "events.hpp"
#include "bats.hpp"
#include "gold.hpp"
#include "map.hpp"
#include "pit.hpp"
#include "room.hpp"
#include "wumpus.hpp"
#include "menu.h"
using namespace std;


int main(int argc, char** argv){

    char* size = argv[1];
    while(true)
    {
        if(atoi(size) < 4)
        {
            cout << "Enter size greater than or equal to 4: ";
            cin >> size;
            cout << endl;
        }
        else
        {
            break;
        }
    }

	Menu start_game;
	start_game.user_interaction(atoi(size));
	
	return 0;
}







