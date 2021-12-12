#include "pokemon.h"

pokemon::pokemon(){

	dex_number = 0;
	name = "";
	type = "";
	/*for(int i = 0; i < 4; i++){

		moves[i]="";
*/	}
	




pokemon::pokemon(int edex_number, string ename, string etype){

	dex_number = edex_number;
	name = ename;
	type = etype;
/*	for(int i = 0; i < 4; i++){
		moves[i]=emoves[i];
*/	}



void pokemon::set_dex(int num){

	dex_number = num;

}


void pokemon::set_type(string etype){

	type = etype;

}

/*void pokemon::set_moves(string emoves[])
{

	for(int i = 0; i < 4; i++){

		moves[i]=emoves[i];

	}

}
*/
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

/*string pokemon::get_moves(){

	for(int i = 0; i < 4; i++){

		return moves[i];

	}

}
*/ 
/*void pokemon::print_pokemon(){


	cout << "Name: " << name << endl;
	cout << "Type: " << type << endl;

	cout << "Moves: ";
	for(int i = 0; i < 4; i++){
		cout <<  moves[i] << " ";

	}  
	


}*/ 
