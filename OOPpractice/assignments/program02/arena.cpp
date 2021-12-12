#include "arena.h"
#ifndef ARENA_CPP
#define ARENA_CPP

Arena::Arena()
{
    health_points_counter = 0;
}

Arena::Arena(int health_points_counter1)
{
    health_points_counter = health_points_counter1;
}

void Arena::game()
{
    cout << "WELCOME TO THE BATTLE OF A LIFETIME!" << endl;
    Trainer user_dex; string name;
    cout << "Enter your name: "; cin >> name; user_dex.set_name(name); cout << endl;
    
    
    user_dex.fill_pokemon_array();
    do
    {

        //check to make sure pokemon[0] isn't out of health pokemons have a health of 0
        while(true)
        {
            Pokemon temp_pokemon;
            temp_pokemon = user_dex.get_pokemon_array(0);
            if(temp_pokemon.get_health_points() == 0)
            {
                cout << "Your current pokemon is out of health" << endl
                     << "Choose Pokemon with health points remaining." << endl;
                user_dex = user_dex.swap(user_dex);
            }

            else
            {
                break;
            }
        }
        
        
        //user move then cpu random move


        int input;
        cout << "Press 1 to Fight..." << endl << "Press 2 to swap a pokemon..." << endl << "Press 3 to Heal a Pokemon.." << endl;
        cout << "ENTER: ";
        cin >> input;

        if(input == 1)
        {
            user_dex = user_dex.fight(user_dex);
        }
        else if(input == 2)
        {
            user_dex = user_dex.swap(user_dex);
        }
        else if(input == 3)
        {
            user_dex = user_dex.heal(user_dex);
        }
        else
        {
            cout << "Enter a proper number you stinky poopoo faceywace: ";
            cin >> input;
            cout << endl;
        }

        user_dex = user_dex.random_cpu_move(user_dex);

    }while(health_counter(calc_cpu_health_points(user_dex), calc_user_health_points(user_dex)));

    if(calc_user_health_points(user_dex) <= 0)
    {
        cout << "HAHA U SUCK I AM SMARTER THAN YOU BECAUSE I CODED THE PROGRAM THAT BEAT YOU... I WIN!!!";
        cout << endl;
    }
    else
    {
        cout << user_dex.get_trainer() << "wins!";
        cout << endl;
    }
}

bool Arena::health_counter(int cpu_health, int user_health)
{

    if(cpu_health <= 0)
    {
        return false;
    }
    else if(user_health <= 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int Arena::calc_cpu_health_points(Trainer all_pokemons)
{
    Pokemon temp_cpu_array[3];
    temp_cpu_array[0] = all_pokemons.get_cpu_pokemon_array(0);
    temp_cpu_array[1] = all_pokemons.get_cpu_pokemon_array(1);
    temp_cpu_array[2] = all_pokemons.get_cpu_pokemon_array(2);

    int cpu_health = temp_cpu_array[0].get_health_points() + temp_cpu_array[1].get_health_points() + temp_cpu_array[2].get_health_points();
    return cpu_health;

}
int Arena::calc_user_health_points(Trainer all_pokemons)
{
    Pokemon temp_user_array[3];
    temp_user_array[0] = all_pokemons.get_pokemon_array(0);
    temp_user_array[1] = all_pokemons.get_pokemon_array(1);
    temp_user_array[2] = all_pokemons.get_pokemon_array(2);

    int user_health = temp_user_array[0].get_health_points() + temp_user_array[1].get_health_points() + temp_user_array[2].get_health_points();
    return user_health;

}

#endif