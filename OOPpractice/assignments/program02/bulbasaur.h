#include "pokemon.h"
#ifndef BULBASAUR_H
#define BULBASAUR_H

class Bulbasaur : virtual public Pokemon{
       // private:
              //  int index;
        public:
                int index;
                Bulbasaur();
                Bulbasaur(int, string, string, int, int, int);
                int get_index();
                void set_index(int);
                void set_values();

};

#endif