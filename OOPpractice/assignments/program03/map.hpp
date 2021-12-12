#ifndef MAP_HPP
#define MAP_HPP

#include<iostream>
#include<cstdlib>
#include<vector>
#include"events.hpp"
#include"room.hpp"
#include"gold.hpp"
#include"bats.hpp"
#include"wumpus.hpp"
#include"pit.hpp"
#include<ctime>

using namespace std;

class Map{
	private: 
		vector<vector<Room*> > game_setting;
		int grid_size, direction, advX, advY, player_spot, rope_spot_x, rope_spot_y;
		int event_array[7], pit_1, pit_2, super_1, super_2, wumpus_1, rope_1, gold_1, arrow;
		bool wumpus_health;
		bool gold_health;
	public:
		Map();
		Map(int size);
		int win_condition();
		int set_direction();
		void random_event_selection();
		bool alter_direction(int r, int c);	
		int win();	
		void area_check();
		int event_check();			
		void start_random_events();	
		void display_grid();	
		int arrow_shot();	
		void wumpus_move();		


		~Map();



};

#endif
