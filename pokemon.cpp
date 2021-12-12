#include "pokemon.h"

pokemon::pokemon(){

	dex_number = 0;
	name = "";
	type = "";
	move1 = "";
	move2 = "";
	move3 = "";
	move4 = "";
}




pokemon::pokemon(int edex_number, string ename, string etype, string new_move1, string new_move2, string new_move3, string new_move4){

	dex_number = edex_number;
	name = ename;
	type = etype;
	move1 = new_move1;
	move2 = new_move2;
	move3 = new_move3;
	move4 = new_move4;
	


}
void pokemon::set_dex(int num){

	dex_number = num;

}


void pokemon::set_type(string etype){

	type = etype;

}

void pokemon::set_moves(string emove1, string emove2, string emove3, string emove4)
{
	move1 = emove1;
	move2 = emove2;
	move3 = emove3;
	move4 = emove4;
	

	

}

void pokemon::set_name(string ename){

	ename = name;

}

int pokemon::get_dex(){

	return dex_number;

} 

string pokemon::get_name(){

	return name;
}

string pokemon::get_type(){

	return type;

}

string pokemon::get_moves1(){
	return move1;
}
string pokemon::get_moves2(){
	return move2;
}
string pokemon::get_moves3(){
	return move3;
}
string pokemon::get_moves4(){
	return move4;
}


	/*void pokemon::print_pokemon(){


	cout << "Name: " << name << endl;
	cout << "Type: " << type << endl;

	cout << "Moves: ";
	for(int i = 0; i < 4; i++){
		cout <<  moves[i] << " ";

	}  
	


}*/ 
