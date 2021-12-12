#include "pokemon.h"
#include "charmander.h"
#include "bulbasaur.h"
#include "squirtle.h"
#ifndef TRAINER_H
#define TRAINER_H

class Trainer : public Squirtle, public Bulbasaur, public Charmander{
        private:
                string trainer;
                Pokemon pokemon_array[3];
                Pokemon cpu_pokemon_array[3];
        public:
                Trainer();
                Trainer(string, Pokemon[], Pokemon[]);
                string get_trainer();
                void set_trainer(string);
                void set_pokemon_array(Pokemon, int);
                Pokemon get_pokemon_array(int);
                Pokemon get_cpu_pokemon_array(int);
                void set_cpu_pokemon_array(Pokemon, int);

                void test();

                //in game functions
                Trainer heal(Trainer);//pass in single pokemon
                Trainer fight(Trainer);
                Trainer swap(Trainer);
                void fill_pokemon_array();
                Trainer random_cpu_move(Trainer);
                

};

#endif