#ifndef EVENTS_HPP
#define EVENTS_HPP

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

class Event
{
   private:
       string percept;
       string encounter;
   public:
       Event();
       virtual string getEncounter();
       virtual string getPercept();
       ~Event();
};


#endif
