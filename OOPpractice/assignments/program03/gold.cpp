#ifndef GOLD_CPP
#define GOLD_CPP

#include "bats.hpp"
#include "events.hpp"
#include "gold.hpp"
#include "map.hpp"

#include "pit.hpp"
#include "room.hpp"
#include "wumpus.hpp"

using namespace std;


Gold::Gold(){

   percept = "You see a glimmer nearby.";
   encounter = "Encountered the Gold ... Picked It Up";
}

string Gold::getPercept(){
   return percept;
}

string Gold::getEncounter(){
   return encounter;
}

Gold::~Gold(){

}

#endif