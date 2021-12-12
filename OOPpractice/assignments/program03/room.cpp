#ifndef ROOM_CPP
#define ROOM_CPP

#include "bats.hpp"
#include "events.hpp"
#include "gold.hpp"
#include "map.hpp"

#include "pit.hpp"
#include "room.hpp"
#include "wumpus.hpp"

using namespace std;

Room::Room(){
		array_spot = 0;
		event = 0;
}

void Room::set_array_spot(int array_spot){
	this -> array_spot = array_spot;
}

int Room::get_array_spot(){
	return array_spot;
}


void Room::set_wumpus_event(){
	if(event != 0){
		delete event;
	}
	event = new Wumpus;
}

void Room::set_gold_event(){
        if(event != 0){
                delete event;
        }
        event = new Gold;
}

void Room::set_pit_event(){
        if(event != 0){
                delete event;
        }
        event = new Pit;
}

void Room::set_bat_event(){
        if(event != 0){
                delete event;
        }
        event = new Bats;
}

void Room::print_event_response(){

	cout<< event->getPercept()<<endl;

}

void Room::print_event_text(){

	cout<< event->getEncounter()<<endl;
}


Room::~Room(){
	delete event;
}

#endif