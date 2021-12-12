#include "pokemon.h"
#include "charmander.h"
#include "bulbasaur.h"
#include "squirtle.h"
#include "trainer.h"
#ifndef ARENA_H
#define ARENA_H

class Arena
{
    private:
        int health_points_counter;
    public:
        Arena();
        Arena(int);
        void game();
        bool health_counter(int, int);
        int calc_cpu_health_points(Trainer);
        int calc_user_health_points(Trainer);


};





#endif