#ifndef GOLD_HPP
#define GOLD_HPP

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "events.hpp"

using namespace std;

class Gold : public Event {
   private:
       string encounter;
       string percept;
   public:
       Gold();
       string getEncounter();
       string getPercept();
       ~Gold();
};

#endif  