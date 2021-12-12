#ifndef EVENTS_CPP
#define EVENTS_CPP

#include "bats.hpp"
#include "events.hpp"
#include "gold.hpp"
#include "map.hpp"

#include "pit.hpp"
#include "room.hpp"

using namespace std;

Event::Event(){
   percept = "";
   encounter = "";
}

string Event::getPercept(){
   return percept;
}


string Event::getEncounter(){
   return encounter;
}

Event::~Event(){

}

#endif