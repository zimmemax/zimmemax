#ifndef PIT_HPP
#define PIT_HPP

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "events.hpp"

using namespace std;
class Pit : public Event{
   private:
       string percept;
       string encounter;
   public:
       Pit();
       string getEncounter();
       string getPercept();
       ~Pit();
};

#endif