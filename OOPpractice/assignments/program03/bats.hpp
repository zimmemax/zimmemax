#ifndef BATS_HPP
#define BATS_HPP

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "events.hpp"

using namespace std;

class Bats : public Event{
   private:
       string percept;
       string encounter;
   public:
       Bats();
       string getEncounter();
       string getPercept();
       ~Bats();
};

#endif