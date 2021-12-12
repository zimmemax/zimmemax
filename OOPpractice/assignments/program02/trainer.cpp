#include "trainer.h"
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


#endif