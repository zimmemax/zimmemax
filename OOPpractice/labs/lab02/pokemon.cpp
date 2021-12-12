#include "pokemon.h"

pokedex::pokedex(){

	trainer = "";
	pokemon_amount = 0;
	pokemon_array;	
	pokemon_index = 0;
	initial_amount = 0;
	}


pokedex::pokedex(string trainer1, int pokemon_amount1, pokemon pokemon_array1[]){
	trainer = trainer1;
	//cout<<"the trainer for the pokedex is"<<trainer1<<endl; 
	pokemon_amount = pokemon_amount1;
	//cout<<"pokemon ammount is"<<pokemon_amount<<endl;
	initial_amount = pokemon_amount; 
	pokemon_index = pokemon_amount;
	//it initializes the new array
	pokemon_array = new pokemon[pokemon_amount];
	//cout<<"the size of the array when init is "<< (sizeof(pokemon_array)/sizeof(pokemon_array[0]))<<endl;
	for(int i = 0; i < pokemon_amount; i++){
		//cout<<"pokemon entered"<<pokemon_array1[i].get_name();
		pokemon_array[i] = pokemon_array1[i];


	}
	//cout<<endl;
	//cout<<pokemon_array[0].get_name()<<"   "<<pokemon_array[1].get_name()<<"     "<<endl;
	
}



void pokedex::set_trainer(string trainer1){

	trainer1 = trainer;

}

void pokedex::set_pokemon_amount(int pokemon_amount_1){ 

	pokemon_amount_1 = pokemon_amount;



}

void pokedex::set_pokemon_array(pokemon new_pokemon){
	
	int fuck_getters = get_pokemon_amount();
	//cout<<"got to the set array function"<<endl;	

	if(get_pokemon_index() >= initial_amount){
		//cout<<"did the for loop in the array funciton first"<<endl;
		//start making the array bigger
		int index = get_pokemon_index();
		//make temp array to hold the shit
		pokemon temp_array[pokemon_index];
		// dump the array's content in the temp
		for(int i = 0;i < index; i++){
			//cout<<"first for loop got to"<<i<<endl;
			temp_array[i] = pokemon_array[i];
		}
		//make a slightly larger array by 1 uwu
		//PLUS FUCKING ONE GODDAMNIT
	
		pokemon_array = new pokemon[index+1];
		
		
		
		//re-populate the array with its initial values
		for(int i = 0; i < index; i++){
			//cout<<"got to second loop value"<<i<<endl; 
			pokemon_array[i] = temp_array[i];
		}
		
		//add the new value to the very end of the array
		//cout<<"abt to do array"<<endl;
		//cout<<pokemon_array[index].get_name()<<endl;
		pokemon_array[index] = new_pokemon;
		//cout<<pokemon_array[index].get_name()<<endl;
		//cout<<"added to last element"<<endl;

		//updating the index
		//cout<<endl<<endl;
		//cout<<"the index is "<<index<<endl<<endl;
		set_pokemon_index(index+1);
		
	}
	else{
		//reguarly putting in a pokemon in the next index in the array
		//cout<<"got to adding one more to the array to the pokemon thing"<<endl;
		pokemon_array[get_pokemon_index()] = new_pokemon;
		set_pokemon_index(get_pokemon_index() +1);
	}

	return;

	} 
	

	/*pokemon temp_pokemon_array[pokemon_amount];
	for(int i = 0; i < pokemon_amount; i++){
		temp_pokemon_array[i].get_name();
		temp_pokemon_array[i].get_dex();
		temp_pokemon_array[i].get_type();
		temp_pokemon_array[i].get_moves();
		

	}

	*///pokemon temp_pokemon_array[pokemon_amount] = new_pokemon;
	//pokemon_amount++;

	

	
	
string pokedex::get_trainer(){

	return trainer;	

	

}

int pokedex::get_pokemon_amount(){


	return pokemon_amount;

}

pokemon* pokedex::get_pokemon_array(){

	return pokemon_array; 		

}

int pokedex::get_pokemon_index(){
	return pokemon_index;
}

void pokedex::set_pokemon_index(int to_set){
	pokemon_index = to_set;
}


