#ifndef WUMPUS_HPP
#define WUMPUS_HPP

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "events.hpp"

using namespace std;

class Wumpus : public Event {
   private:
       string percept;
       string encounter;
   public:
       Wumpus();
       string getEncounter();
       string getPercept();
       ~Wumpus();
};

#endif