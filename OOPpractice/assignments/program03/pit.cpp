#ifndef PIT_CPP
#define PIT_CPP
#include "bats.hpp"
#include "events.hpp"
#include "gold.hpp"
#include "map.hpp"
#include "pit.hpp"
#include "room.hpp"
#include "wumpus.hpp"

using namespace std;

Pit::Pit(){
   percept = "You feel a breeze.";
   encounter = "Encountered a Pit ... Fell in and Died";
}

string Pit::getPercept(){
   return percept;
}

string Pit::getEncounter(){
   return encounter;
}

Pit::~Pit(){

}

#endif