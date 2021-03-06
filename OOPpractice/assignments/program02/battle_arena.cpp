pokemon.h                                                                                           0000660 0044234 0070547 00000001271 14136343113 012535  0                                                                                                    ustar   zimmemax                        upg18588                                                                                                                                                                                                               #include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#ifndef POKEMON_H
#define POKEMON_H

using namespace std;

class Pokemon {

	public:	
		string name;
		string type;
        int health_points;
        int attack;
        int defense;

	
		//default
		Pokemon();
		//parameter
		Pokemon(string, string, int, int, int);

		//setter 
		void set_name(string);
		void set_type(string);
		void set_health_points(int);
        void set_attack(int);
        void set_defense(int);

		//getter
		string get_name();
		string get_type();
        int get_health_points();
        int get_attack();
        int get_defense();

		


};	
#endif                                                                                                                                                                                                                                                                                                                                       trainer.h                                                                                           0000660 0044234 0070547 00000002100 14136610423 012522  0                                                                                                    ustar   zimmemax                        upg18588                                                                                                                                                                                                               #include "pokemon.h"
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

#endif                                                                                                                                                                                                                                                                                                                                                                                                                                                                arena.h                                                                                             0000660 0044234 0070547 00000000701 14136562171 012157  0                                                                                                    ustar   zimmemax                        upg18588                                                                                                                                                                                                               #include "pokemon.h"
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





#endif                                                               bulbasaur.h                                                                                         0000660 0044234 0070547 00000000644 14136345226 013057  0                                                                                                    ustar   zimmemax                        upg18588                                                                                                                                                                                                               #include "pokemon.h"
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

#endif                                                                                            squirtle.h                                                                                          0000660 0044234 0070547 00000000637 14136345256 012754  0                                                                                                    ustar   zimmemax                        upg18588                                                                                                                                                                                                               #include "pokemon.h"
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

#endif                                                                                                 charmander.h                                                                                        0000660 0044234 0070547 00000000651 14136345242 013177  0                                                                                                    ustar   zimmemax                        upg18588                                                                                                                                                                                                               #include "pokemon.h"
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

#endif                                                                                       main.cpp                                                                                            0000660 0044234 0070547 00000001075 14140401733 012344  0                                                                                                    ustar   zimmemax                        upg18588                                                                                                                                                                                                               #include <iostream>
#include "pokemon.h"
#include "charmander.h"
#include "bulbasaur.h"
#include "squirtle.h"
#include "trainer.h"
#include "arena.h"
/******************************************************
** Program: battle_arena.cpp
** Author: Max Zimmer
** Date: 10/31/2021
** Description: USER BATTLES  CPU WITH SELECTED POEKMON UNTIL ONE RUNS OUT OF HEALTH  
** Input: USER INPUTS
** Output: THE WINNER
******************************************************/

int main()
{
//Happy with my amount of lines in main? :)

    Arena a;
    a.game();
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                   pokemon.cpp                                                                                         0000660 0044234 0070547 00000002074 14136370221 013072  0                                                                                                    ustar   zimmemax                        upg18588                                                                                                                                                                                                               #include "pokemon.h"
#ifndef POKEMON_CPP
#define POKEMON_CPP

Pokemon::Pokemon(){

	name = "";
	type = "";
    health_points = 0;
    attack = 0;
    defense = 0;
	
}




Pokemon::Pokemon(string ename, string etype, int ehealth_points, int eattack, int edefense){

	name = ename;
	type = etype;
    health_points = ehealth_points; 
    attack = eattack;
    defense = edefense;
	
	


}



void Pokemon::set_type(string etype){

	type = etype;

}



void Pokemon::set_name(string ename){

	name = ename;

}

void Pokemon::set_health_points(int ehealth_points)
{
    health_points = ehealth_points;
}

void Pokemon::set_attack(int eattack)
{
    attack = eattack;
}
void Pokemon::set_defense(int edefense)
{
    defense = edefense;
}


string Pokemon::get_name(){

	return name;
}

string Pokemon::get_type(){

	return type;

}
int Pokemon::get_health_points()
{
    return health_points;
}

int Pokemon::get_attack()
{
    return attack;
}
int Pokemon::get_defense()
{
    return defense;
}

#endif
                                                                                                                                                                                                                                                                                                                                                                                                                                                                    charmander.cpp                                                                                      0000660 0044234 0070547 00000001206 14136370512 013525  0                                                                                                    ustar   zimmemax                        upg18588                                                                                                                                                                                                               #include "charmander.h"
#ifndef CHARMANDER_CPP
#define CHARMANDER_CPP

Charmander::Charmander():Pokemon()
{
    index = 0;
}

Charmander::Charmander(int index1, string name, string type, int health_points, int attack, int defense):Pokemon(name, type, health_points, attack, defense)
{
    index = index1;
}

void Charmander::set_index(int index1)
{
    index = index1;
}

int Charmander::get_index()
{
    return index;
}

void Charmander::set_values()
    {   
        set_name("Charmander");
        set_type("Fire");
        set_health_points(39);
        set_attack(52);
        set_defense(43);
    }

#endif                                                                                                                                                                                                                                                                                                                                                                                          bulbasaur.cpp                                                                                       0000660 0044234 0070547 00000001171 14136603157 013406  0                                                                                                    ustar   zimmemax                        upg18588                                                                                                                                                                                                               #include "bulbasaur.h"
#ifndef BULBASAUR_CPP
#define BULBASAUR_CPP

Bulbasaur::Bulbasaur():Pokemon()
{
    index = 2;
}

Bulbasaur::Bulbasaur(int index1, string name, string type, int health_points, int attack, int defense):Pokemon(name, type, health_points, attack, defense)
{
    index = index1;
}

void Bulbasaur::set_index(int index1)
{
    index = index1;
}

int Bulbasaur::get_index()
{
    return index;
}

void Bulbasaur::set_values()
    {
        set_name("Bulbasaur");
        set_type("Grass");
        set_health_points(45);
        set_attack(49);
        set_defense(49);
    }

#endif                                                                                                                                                                                                                                                                                                                                                                                                       squirtle.cpp                                                                                        0000660 0044234 0070547 00000001156 14136370607 013302  0                                                                                                    ustar   zimmemax                        upg18588                                                                                                                                                                                                               #include "squirtle.h"
#ifndef SQUIRTLE_CPP
#define SQUIRTLE_CPP

Squirtle::Squirtle():Pokemon()
{
    index = 1;
}

Squirtle::Squirtle(int index1, string name, string type, int health_points, int attack, int defense):Pokemon(name, type, health_points, attack, defense)
{
    index = index1;
}

void Squirtle::set_index(int index1)
{
    index = index1;
}

int Squirtle::get_index()
{
    return index;
}

void Squirtle::set_values()
    {
        set_name("Squirtle");
        set_type("Water");
        set_health_points(44);
        set_attack(48);
        set_defense(65);
    }

#endif                                                                                                                                                                                                                                                                                                                                                                                                                  trainer.cpp                                                                                         0000660 0044234 0070547 00000042577 14137121720 013101  0                                                                                                    ustar   zimmemax                        upg18588                                                                                                                                                                                                               #include "trainer.h"
#ifndef TRAINER_CPP
#define TRAINER_CPP

Trainer::Trainer():Squirtle(), Bulbasaur(), Charmander()
{
    trainer = "";
    pokemon_array;
    cpu_pokemon_array;
}

Trainer::Trainer(string trainer1, Pokemon pokemon_array1[], Pokemon cpu_pokemon_array1[]):Squirtle(Squirtle::index, name, type, health_points, attack, defense),Bulbasaur(Bulbasaur::index, name, type, health_points, attack, defense),Charmander(Charmander::index, name, type, health_points, attack, defense)
{
    trainer = trainer1;
    for(int i = 0; i < 3; i++)
    {
        pokemon_array[i] = pokemon_array1[i];
    }
    for(int i = 0; i < 3; i++)
    {
        cpu_pokemon_array[i] = cpu_pokemon_array1[i];
    }
}

void Trainer::set_trainer(string trainer1)
{
    trainer = trainer1;
}

string Trainer::get_trainer()
{
    return trainer;
}

void Trainer::set_pokemon_array(Pokemon temp_pokemon, int index1)
{
    pokemon_array[index1] = temp_pokemon;
}
void Trainer::set_cpu_pokemon_array(Pokemon temp_pokemon, int index1)
{
    cpu_pokemon_array[index1] = temp_pokemon;
}

Pokemon Trainer::get_pokemon_array(int index1)
{
    return pokemon_array[index1];
}
Pokemon Trainer::get_cpu_pokemon_array(int index1)
{
    return cpu_pokemon_array[index1];
}

Trainer Trainer::heal(Trainer user_dex)
{   
    Pokemon temp_pokemon_array[3];
    temp_pokemon_array[0] = user_dex.get_pokemon_array(0);
    temp_pokemon_array[1] = user_dex.get_pokemon_array(1);
    temp_pokemon_array[2] = user_dex.get_pokemon_array(2);
    int new_index;
    do
        {
            cout << "Enter the corresponding number for the pokemon you want to heal.." << endl;
            cout << "Enter 0 to heal " << temp_pokemon_array[0].get_name() << " with " << temp_pokemon_array[0].get_health_points() << " health points remaining." << endl;
            cout << "Enter 1 to heal " << temp_pokemon_array[1].get_name() << " with " << temp_pokemon_array[1].get_health_points() << " health points remaining." << endl;
            cout << "Enter 2 to heal " << temp_pokemon_array[2].get_name() << " with " << temp_pokemon_array[2].get_health_points() << " health points remaining." << endl;
            cout << "ENTER: ";
            cin >> new_index;
            cout << endl;
            if(new_index == 0)
            {
                Pokemon temp_pokemon = temp_pokemon_array[0];
                int health = temp_pokemon.get_health_points();
                health = health + 15;
                temp_pokemon_array[0].set_health_points(health);
                cout << "New health is: " << temp_pokemon_array[0].get_health_points() << endl;
                user_dex.set_pokemon_array(temp_pokemon_array[0],0);
                break;
            }
            else if(new_index == 1)
            {
                Pokemon temp_pokemon = temp_pokemon_array[1];
                int health = temp_pokemon.get_health_points();
                health = health + 15;
                temp_pokemon_array[1].set_health_points(health);
                cout << "New health is: " << temp_pokemon_array[1].get_health_points() << endl;
                user_dex.set_pokemon_array(temp_pokemon_array[1],1);
                break;
            }
            else if(new_index == 2)
            {
                Pokemon temp_pokemon = temp_pokemon_array[1];
                int health = temp_pokemon.get_health_points();
                health = health + 15;
                temp_pokemon_array[1].set_health_points(health);
                cout << "New health is: " << temp_pokemon_array[2].get_health_points() << endl;
                user_dex.set_pokemon_array(temp_pokemon_array[2],2);
                break;
            }
            else
            {
                cout << "Enter correct number you silly poopoo head: ";
                cin >> new_index;
                cout << endl;
            }
        }while(true);

    return user_dex;
   
}


Trainer Trainer::fight(Trainer user_dex)
{
    int random_int = (rand() % 30 + 85);
    random_int = random_int * 15;
    random_int = random_int/100;
    Pokemon attacker = user_dex.get_pokemon_array(0);
    Pokemon defender = user_dex.get_cpu_pokemon_array(0);
    int damage = (attacker.get_attack()/defender.get_defense());
    damage = damage * random_int;
    //for grass

    if(attacker.get_type() == "Grass")
    {
        if(defender.get_type() == "Fire")
        {
            damage = damage * .5;
            int new_health = defender.get_health_points();
            new_health = new_health - damage;
            defender.set_health_points(new_health);
            cout << "Damage for the attack is: " << damage << endl;
            cout << "Opponent has " << defender.get_health_points() << " remaining." << endl;

        }
        else
        {
            damage = damage * 2;
            int new_health = defender.get_health_points();
            new_health = new_health - damage;
            defender.set_health_points(new_health);
            cout << "Damage for the attack is: " << damage << endl;
            cout << "Opponent has " << defender.get_health_points() << " remaining." << endl;
            
        }
    }
    //for water
    else if(attacker.get_type() == "Water")
    {
        if(defender.get_type() == "Fire")
        {
            damage = damage * 2;
            int new_health = defender.get_health_points();
            new_health = new_health - damage;
            defender.set_health_points(new_health);
            cout << "Damage for the attack is: " << damage << endl;
            cout << "Opponent has " << defender.get_health_points() << " remaining." << endl;
        }
        else
        {
            damage = damage * .5;
            int new_health = defender.get_health_points();
            new_health = new_health - damage;
            defender.set_health_points(new_health);
            cout << "Damage for the attack is: " << damage << endl;
            cout << "Opponent has " << defender.get_health_points() << " remaining." << endl;
        }
    }
    //for fire
    else
    {
        if(defender.get_type() == "Grass")
        {
            damage = damage * 2;
            int new_health = defender.get_health_points();
            new_health = new_health - damage;
            defender.set_health_points(new_health);
            cout << "Damage for the attack is: " << damage << endl;
            cout << "Opponent has " << defender.get_health_points() << " remaining." << endl;
        }

        else
        {
            damage = damage * .5;
            int new_health = defender.get_health_points();
            new_health = new_health - damage;
            defender.set_health_points(new_health);
            cout << "Damage for the attack is: " << damage << endl;
            cout << "Opponent has " << defender.get_health_points() << " remaining." << endl;
        }
    }
    user_dex.set_cpu_pokemon_array(defender, 0);

    return user_dex;



}

Trainer Trainer::swap(Trainer user_dex)
//create a menu that has states "enter 1 1 << pokemon_array[0].get_name enter 2 to swap pokemon_array[1]
//enter 3 to swap pokemon_array[2].
//Then depending on their answer, the index is given by the answer of - 1
//so basically Pokemon old_pokemon = pokemon_array[0];
//Pokemon new_pokemon = pokemon_array[input - 1];
//pokemon_array[0] = new_pokemon;
//pokemon_array[index] = old_pokemon;
{
    Pokemon temp_pokemon_array[3];
    temp_pokemon_array[0] = user_dex.get_pokemon_array(0);
    temp_pokemon_array[1] = user_dex.get_pokemon_array(1);
    temp_pokemon_array[2] = user_dex.get_pokemon_array(2);
    int new_index;
        do
        {
            cout << "Enter the corresponding number for the pokemon you want to swap.." << endl;
            cout << "Enter 1 to sub in " << temp_pokemon_array[1].get_name() << " with " << temp_pokemon_array[1].get_health_points() << " health points remaining." << endl;
            cout << "Enter 2 to sub in " << temp_pokemon_array[2].get_name() << " with " << temp_pokemon_array[2].get_health_points() << " health points remaining." << endl;
            cout << "ENTER: ";
            cin >> new_index;
            if(new_index == 1 || new_index == 2)
            {
                break;
            }
        }while(true);


    Pokemon new_figher = temp_pokemon_array[new_index];
    Pokemon old_figher = temp_pokemon_array[0];
    user_dex.set_pokemon_array(new_figher,0);
    user_dex.set_pokemon_array(old_figher,new_index);

    return user_dex;
}
void Trainer::test()
{
    Squirtle s;
    Charmander c;
    Bulbasaur b;
    s.set_values();
    c.set_values();
    b.set_values();

    set_pokemon_array(s,0);
    set_pokemon_array(b,1);
    set_pokemon_array(c,2);

}
void Trainer::fill_pokemon_array()
{
    //fill user array
    Squirtle s;
    Charmander c;
    Bulbasaur b;
    s.set_values();
    c.set_values();
    b.set_values();
    while(true)
    {
        for(int i = 0; i < 3; i++)
        {
            int num;
            cout << "CHOOSE YOUR POKEMON FOR BATTLE!" << endl;
            cout << "1 For Charmander..." << endl;
            cout << "2 For Bulbasaur..." << endl;
            cout << "3 For Squirtle..." << endl;
            cout << "ENTER NUM: ";
            cin >> num;
            cout << endl;
            if(num == 1)
            {
                pokemon_array[i] = c;
            }
            else if(num == 2)
            {
                pokemon_array[i] = b;
            }
            else if(num == 3)
            {
                pokemon_array[i] = s;
            }

            else
            {
                cout << "Incorrect input... Dumbass" << endl;
                i = i - 1;
            }
        }

        break;
    
    }

    //fill cpu array

    for(int i = 0; i < 3; i++)
    {
        int random_int = rand() % 3 + 1;
        if(random_int == 1)
        {
            cpu_pokemon_array[i] = b;
        }
        else if(random_int == 2)
        {
            cpu_pokemon_array[i] = c;
        }
        else
        {
            cpu_pokemon_array[i] = s;
        }
    }



}
Trainer Trainer::random_cpu_move(Trainer user_dex)
{
    //random var to determine move
    Pokemon temp_pokemon_array[3];
    temp_pokemon_array[0] = user_dex.get_cpu_pokemon_array(0);
    temp_pokemon_array[1] = user_dex.get_cpu_pokemon_array(1);
    temp_pokemon_array[2] = user_dex.get_cpu_pokemon_array(2);

    int random_int = rand() % 3 + 1;
    //1 swap 2 heal 3 fight

    if(temp_pokemon_array[0].get_health_points() <= 0)
    {
        cout << "CPU current pokemon is dead... CPU is swapping them out..." << endl << endl << endl;
        if(temp_pokemon_array[1].get_health_points() <= 0)
        {
            cout << "CPU SWAPS IN " << temp_pokemon_array[1].get_name() << "!" << endl;
            Pokemon old_pokemon = user_dex.get_cpu_pokemon_array(0);
            user_dex.set_cpu_pokemon_array(temp_pokemon_array[1], 0);
            user_dex.set_cpu_pokemon_array(old_pokemon, 1);

        }
        else
        {
            cout << "CPU SWAPS IN " << temp_pokemon_array[2].get_name() << "!" << endl;
            Pokemon old_pokemon = user_dex.get_cpu_pokemon_array(0);
            user_dex.set_cpu_pokemon_array(temp_pokemon_array[2], 0);
            user_dex.set_cpu_pokemon_array(old_pokemon, 2);
        }
    }

    if(random_int == 1)
    {     
        cout << endl << "CPU decides to swap a pokemon!" << endl;
        if(temp_pokemon_array[1].get_health_points() <= 0 && temp_pokemon_array[2].get_health_points() <= 0)
        {
            cout << "CPU DECIDES TO SWAP INVALID POKEMON AS NO OTHERS ARE ALIVE. CPU LOSES TURN!" << endl;
        }
        else if(temp_pokemon_array[1].get_health_points() <= 0)
        {
            Pokemon new_pokemon = temp_pokemon_array[2];
            Pokemon old_pokemon = temp_pokemon_array[0];
            user_dex.set_cpu_pokemon_array(new_pokemon, 0);
            user_dex.set_cpu_pokemon_array(old_pokemon, 2);
            cout << "CPU SUBS IN " << new_pokemon.get_name() << endl;
        }
        else if(temp_pokemon_array[2].get_health_points() <= 0)
        {
            Pokemon new_pokemon = temp_pokemon_array[1];
            Pokemon old_pokemon = temp_pokemon_array[0];
            user_dex.set_cpu_pokemon_array(new_pokemon, 0);
            user_dex.set_cpu_pokemon_array(old_pokemon, 1);
            cout << "CPU SUBS IN " << new_pokemon.get_name() << endl;
        }
        else
        {
        
            cout << endl << "CPU decides to swap a pokemon!" << endl;
            int index = rand() % 2 + 1;
            cout << "CPU subs in " << temp_pokemon_array[index].get_name() << " for " << temp_pokemon_array[0].get_name() << endl;
            Pokemon new_pokemon = temp_pokemon_array[index];
            Pokemon old_pokemon = temp_pokemon_array[0];
            user_dex.set_cpu_pokemon_array(new_pokemon,0);
            user_dex.set_cpu_pokemon_array(old_pokemon,index);
        }

    }
    else if(random_int == 2)
    {
        int index = rand() % 2 + 0;
        cout << "CPU Decided to Heal " << temp_pokemon_array[index].get_name() << "!" << endl;
        Pokemon temp_pokemon = temp_pokemon_array[index];
        int health = temp_pokemon.get_health_points();
        health = health + 15;
        temp_pokemon_array[index].set_health_points(health);
        cout << "New health is: " << temp_pokemon_array[index].get_health_points() << endl;
        user_dex.set_pokemon_array(temp_pokemon_array[index],index);
        cout << endl << endl << endl;

    }
    else
    {
        int random_int = (rand() % 30 + 85);
        random_int = random_int * 15;
        random_int = random_int/100;
        Pokemon attacker = user_dex.get_cpu_pokemon_array(0);
        Pokemon defender = user_dex.get_pokemon_array(0);
        int damage = (attacker.get_attack()/defender.get_defense());
        damage = damage * random_int;
        //for grass

        if(attacker.get_type() == "Grass")
        {
            if(defender.get_type() == "Fire")
            {
                damage = damage * .5;
                int new_health = defender.get_health_points();
                new_health = new_health - damage;
                defender.set_health_points(new_health);
                cout << "Damage for the attack is: " << damage << endl;
                cout << "Your current Pokemon has " << defender.get_health_points() << " remaining." << endl;

            }
            else
            {
                damage = damage * 2;
                int new_health = defender.get_health_points();
                new_health = new_health - damage;
                defender.set_health_points(new_health);
                cout << "Damage for the attack is: " << damage << endl;
                cout << "Your current Pokemon has " << defender.get_health_points() << " remaining." << endl;
            
            }
        }
        //for water
        else if(attacker.get_type() == "Water")
        {
            if(defender.get_type() == "Fire")
            {
                damage = damage * 2;
                int new_health = defender.get_health_points();
                new_health = new_health - damage;
                defender.set_health_points(new_health);
                cout << "Damage for the attack is: " << damage << endl;
                cout << "Your current Pokemon has " << defender.get_health_points() << " remaining." << endl;
            }
            else
            {
                damage = damage * .5;
                int new_health = defender.get_health_points();
                new_health = new_health - damage;
                defender.set_health_points(new_health);
                cout << "Damage for the attack is: " << damage << endl;
                cout << "Your current Pokemon has " << defender.get_health_points() << " remaining." << endl;
            }
        }
        //for fire
        else
        {
            if(defender.get_type() == "Grass")
            {
                damage = damage * 2;
                int new_health = defender.get_health_points();
                new_health = new_health - damage;
                defender.set_health_points(new_health);
                cout << "Damage for the attack is: " << damage << endl;
                cout << "Your current Pokemon has " << defender.get_health_points() << " remaining." << endl;
            }

            else
            {
            damage = damage * .5;
                int new_health = defender.get_health_points();
                new_health = new_health - damage;
                defender.set_health_points(new_health);
                cout << "Damage for the attack is: " << damage << endl;
                cout << "Your current pokemon has " << defender.get_health_points() << " remaining." << endl;
            }
            user_dex.set_pokemon_array(defender, 0);
        }
    
    

        
    }

    return user_dex;



}




/*void Trainer::test()
{
    Squirtle s;
    Charmander c;
    Bulbasaur b;
    s.set_values();
    c.set_values();
    b.set_values();
    cout << "Health Points in Test: " << s.get_health_points() << endl;
    cout << "Health Points in Test: " << c.get_health_points() << endl;
    cout << "Health Points in Test: " << b.get_health_points() << endl;
}*/


#endif                                                                                                                                 arena.cpp                                                                                           0000660 0044234 0070547 00000006552 14140036170 012512  0                                                                                                    ustar   zimmemax                        upg18588                                                                                                                                                                                                               #include "arena.h"
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

#endif                                                                                                                                                      Makefile                                                                                            0000660 0044234 0070547 00000000154 14140402401 012342  0                                                                                                    ustar   zimmemax                        upg18588                                                                                                                                                                                                               battle:
	g++ main.cpp pokemon.cpp bulbasaur.cpp squirtle.cpp charmander.cpp trainer.cpp arena.cpp -o battle                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    