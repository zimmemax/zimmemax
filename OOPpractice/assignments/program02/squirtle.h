#include "pokemon.h"
#ifndef SQUIRTLE_H
#define SQUIRTLE_H

class Squirtle : virtual public Pokemon{
        //private:
            //    int index;
        public:
                int index;
                Squirtle();
                Squirtle(int, string, string, int, int, int);
                int get_index();
                void set_index(int);
                void set_values();

};

#endif