#include "pokemon.h"
#ifndef CHARMANDER_H
#define CHARMANDER_H

class Charmander : virtual public Pokemon{
        //private:
             //   int index;
        public:
                int index;
                Charmander();
                Charmander(int, string, string, int, int, int);
                int get_index();
                void set_index(int);
                void set_values();

};

#endif