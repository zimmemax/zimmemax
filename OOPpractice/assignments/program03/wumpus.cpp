#ifndef WUMPUS_CPP
#define WUMPUS_CPP

#include "bats.hpp"
#include "events.hpp"
#include "gold.hpp"
#include "map.hpp"

#include "pit.hpp"
#include "room.hpp"
#include "wumpus.hpp"

using namespace std;

Wumpus::Wumpus(){
   percept = "You smell a terrible stench.";
   encounter = "Encountered the Wumpus ... You are Consumed";
}

string Wumpus::getPercept(){
   return percept;
}

string Wumpus::getEncounter(){
   return encounter;
}


Wumpus::~Wumpus(){

}

#endif