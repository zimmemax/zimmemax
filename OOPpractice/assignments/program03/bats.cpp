#ifndef BATS_CPP
#define BATS_CPP
#include "bats.hpp"
#include "events.hpp"
#include "gold.hpp"
#include "map.hpp"
#include "pit.hpp"
#include "room.hpp"
#include "wumpus.hpp"

using namespace std;



Bats::Bats(){
   percept = "You hear wings flapping.";
   encounter = "Encountered Bats, Taken to New Room";
}


string Bats::getPercept(){
   return percept;
}


string Bats::getEncounter(){
   return encounter;
}


Bats::~Bats(){

}

#endif