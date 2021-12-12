#ifndef ROOM_HPP
#define ROOM_HPP
#include<iostream>
#include<vector>
#include"wumpus.hpp"
#include"bats.hpp"
#include"gold.hpp"
#include"pit.hpp"


using namespace std;

class Room{
	
	private:
		int array_spot;
		Event *event;	
	public:
		Room();
	
		void set_array_spot(int array_spot);
		void set_wumpus_event();
		void set_bat_event();
		void set_pit_event();
		void set_gold_event();

		int get_array_spot();
		void print_event_text();
		void print_event_response();
	
		~Room();
};

#endif