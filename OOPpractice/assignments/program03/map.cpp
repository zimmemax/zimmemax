#ifndef MAP_CPP
#define MAP_CPP

#include "bats.hpp"
#include "events.hpp"
#include "gold.hpp"
#include "map.hpp"
#include"gold.hpp"
#include"map.hpp"
#include "pit.hpp"
#include "room.hpp"
#include "wumpus.hpp"

using namespace std;


/*********************************************************************  
 ** Function: Map constructor
 ** Description: set base info for the game
 ** Parameters: none
 ** Pre-Conditions: none	
 ** Post-Conditions: none
 *********************************************************************/  

Map::Map(){
	advX = 0;
	advY = 0;
	arrow = 3;
	wumpus_health = 0;
	gold_health = 0;
	
}
/*********************************************************************  
 ** Function:  srota another constructor for the map
 ** Description: established vector for the map that contains rooms
 ** Parameters: size inputted by the user
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/ 


Map::Map(int size){
//set vector of type room to gain the total amount of rooms that are in the game
	grid_size = size;
	for(int i = 0; i <grid_size; i++){
		vector<Room*> row;//set the rows
		for(int j = 0; j < size; j++){
			row.push_back(new Room);
		}
		game_setting.push_back(row);
		}

}
/*********************************************************************  
 ** Function:  arrow_shot
 ** Description: asks the user in which directions they would like to shoot and then shoots the arroaw
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/ 
int Map::arrow_shot()
{
	int test = 1; int spot;
	int i = 0;
	while(i<grid_size)
	{
		for(int j = 0; j < grid_size; j++)
		{
			if(i == advX && j == advY)
			{
				spot = test;
			}
			test++;
		}
		i++;
	}
	int shoot;

	cout<<"SHOOOOOOOTTTTTT WHEERRRRREEEEE?: "<<endl;
	cout<<"1 to shoot up: "<<endl;
	cout<<"2 to shoot down: "<<endl;
	cout<<"3 to shoot left: "<<endl;
	cout<<"4 to shoot right: "<<endl;
	cin>>shoot;
	
	if(shoot == 1){
		arrow--;
		int i = 1;
		while(i <= 3){
			if(alter_direction(advX-i, advY))
			{
				cout << spot - (grid_size*i)<<endl;
				if(wumpus_health == 1)
				{
					break;
				}

				if(spot - (grid_size) == wumpus_1)
				{
					cout<<"You killed the wumpus!!"<<endl;
					wumpus_health = 1;
					return 0;
				}
			}
			i++;
		}
	}
	else if(arrow > 0 && wumpus_health == 1)
	{
        return 0;
                        
	}
    else if (arrow <=0 && wumpus_health == 1)
	{
        cout<< "Your arrows are gone and wumpus is dead."<<endl;
    }
	else if(shoot == 2){
        arrow--;
        for(int i = 1; i<=3; i++){
                if(alter_direction(advX+i, advY))
				{
                    cout << spot + (grid_size*i)<<endl;
                    if (wumpus_health ==1)
						{
							break;
						}			
				
				if(spot + (grid_size*i) == wumpus_1){
                                        cout<<"You killed the wumpus!!"<<endl;
					wumpus_health = 1;
                                        return 0;
                                }
                        }
                }
        	if(arrow > 0 && wumpus_health == 1){
				return 0;
			}
		else if (arrow <=0 && wumpus_health == 1)
		{
			cout<< "you done an wumpy dead!"<<endl;
		}
	}



        else if(shoot == 3){
                arrow--;
                for(int i = 1; i<=3; i++){
                        if(alter_direction(advX, advY-i)){
                                cout<< spot -i <<endl;
                                if(wumpus_health == 1){
					break;
				}
				if(spot - i  == wumpus_1){
                                        cout<<"You killed the wumpus!!"<<endl;
                                        wumpus_health = 1;
                                        return 0;
                                }
                        }
                }
        

	if(arrow > 0 && wumpus_health == 1){
                        return 0;
                        }
                else if (arrow <=0 && wumpus_health == 1){
                        cout<< "Your arrows are gone and wumpus is dead. Stop wasting time and get out of there!"<<endl;
                }



	}




        else if(shoot == 4){
                arrow--;
                for(int i = 1; i<=3; i++){
                        if(alter_direction(advX, advY+i)){
                                cout<< spot + i<<endl;
                                if(wumpus_health == 1){
				break;
				}

				if(spot + i == wumpus_1){
                                        cout<<"You killed the wumpus!!"<<endl;
                                        wumpus_health = 1;
                                        return 0;
                                }
                        
                }
       		}
		 
	if(arrow > 0 && wumpus_health == 1){
                        return 0;
                        }
        else if (arrow <=0 && wumpus_health == 1){
                        cout<< "Your arrows are gone and wumpus is dead. Stop wasting time and get out of there!"<<endl;
                }	  
		
	}
	
	if(wumpus_health==0){
	
	}
	else if(wumpus_health==1){
		return 0;
	}
	if(arrow <= 0 && wumpus_health == 0){
		cout<< "Ran out of arrows so you ran out of life :)"<<endl;
		arrow=3;
		return 1;
	}
	else{
	
		return 0;
	}
}

/*********************************************************************  
 ** Function:  set_direction
 ** Description: asks user what direction they want to walk
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/ 
int Map::set_direction()
{
	//while(true)
	//ask user what they wanna do
	int direction_option;
	cout<<"WHICH DIRECTION SHALL YOU PARTAKE: "<<endl;
	cout<<"1 UP"<<endl;
	cout<<"2 DOWN"<<endl;
	cout<<"3 LEFT"<<endl;
	cout<<"4 RIGHT"<<endl;
	cout << "Enter choice: " << endl;
	cin >> direction_option;
	while(true)
	{
	if(direction_option == 1)
	{
		if(alter_direction(advX-1, advY))
		{
			advX--;

		}
		else
		{
			cout<<"cannot move in that direction as it is not on board"<<endl;
		}
		
	}
	else if(direction_option == 2)
	{
        if(alter_direction(advX+1, advY))
			{
                advX++;
				break;
				
            }
            else
			{
                cout<<"cannot move in that direction as it is not on map"<<endl;
        	}
			
    }
	else if(direction_option == 3)
	{
        if(alter_direction(advX, advY+1))
			{
                advY--;
				break;
				
            }
            else
			{
                    cout<<"cannot move that direction as it is not on the board"<<endl;
        	}
			
        }

    else if(direction_option == 4)
	{
        if(alter_direction(advX, advY-1))
			{
                advY++;
				break;
			}
            else
			{
                cout<<"cannot move that direction as it is not on the board"<<endl;
        	}

    }
	}
	//function to check if user has won and diplay other stuff (check function)
	int number = win_condition();
	return number;
}

/*********************************************************************  
 ** Function:  win_condition
 ** Description: checks the win condition to determine if the game shall continue while also outputting the location of the player
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/ 
	

int Map::win_condition()
{
int check = 1;
	for(int i = 0; i < grid_size; i++){
		for(int j = 0; j < grid_size; j++){
			if(i == advX && j == advY){
				player_spot = check;
			}
			check++;
		}
	}

	cout<<	"Location: "<< player_spot <<endl;
	if(event_check() == 0)
	{
		return 1;
	}
	area_check();

	if(win() == 1)
	{
		cout << "you have won" <<endl;
		return 1;
	}
}
/*********************************************************************  
 ** Function: random_event_selection() 
 ** Description: selects a random event when creating map for its location
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/ 
void Map::random_event_selection(){
	int n_event = 1;
	int event[7];
	int if_sim = 0;
	int t;
	event[0] = rand () % (grid_size*grid_size) + 1;
	
	while(n_event < 7){
		t = rand() % (grid_size*grid_size) + 1;
		for(int i = 0; i<n_event;i++){
			if(t == event[i]){
				if_sim = 1;
				break;
			}
		}
		if(if_sim == 1){
			if_sim = 0;
		}
		else if(if_sim == 0){
			event[n_event] = t;
			n_event++;
		}
	}
	
	cout<<endl;

	rope_1 = event[0];
	super_1 = event[1];
	super_2 = event[2];
	pit_1 = event[3];
	pit_2 = event[4];
	wumpus_1 = event[5];
	gold_1 = event[6];

	for(int i =0; i < 7;i++){
		event_array[i] = event[i];
	}
	
//	for(int i =0 ; i < 7; i++){
//		cout << "Event array: " << event_array[i] << endl;
//}
}
	
/*********************************************************************  
 ** Function:  alter_direction()
 ** Description: checks to see if the direction that the arrow/
 ** Parameters: an x and y coordinate for where the user shoots
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/ 

bool Map::alter_direction(int r, int c){
	if(r<0||r>grid_size-1|| c<0|| c>grid_size-1){
		return false;
}
	else{
		return true;
}
}

/*********************************************************************  
 ** Function: win()
 ** Description: checks to see if user has won the game
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 ********************************************************************/



int Map::win(){
	if(wumpus_health == 1 && gold_health == 1 && player_spot == event_array[0]){
		wumpus_health = 0;
		gold_health = 0;
		arrow = 3;
		return 1;
	
	}
	else{
		 return 0;
	}
}
/*********************************************************************  
 ** Function: win()
 ** Description: checks to see if user has won the game
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 ********************************************************************/
void Map::area_check()
{
	int spot; int test = 1; int i = 0;
	
	while(i<grid_size)
	{
		for(int j= 0; j< grid_size; j++)
		{
			if(i == advX && j == advY)
			{
				spot = test;
			}
			test++;
		}
		i++;	
	}
	if(alter_direction(advX-1, advY))
	{
		for(int i = 1; i < 6; i++)
		{
			if(spot-grid_size == event_array[5] && wumpus_health ==1)
			{
                cout<<"monsiour wumpussio had diedio"<<endl;
				break;
            }
	


			else if(spot - grid_size == event_array[i])
			{
				game_setting[advX-1][advY]->print_event_response();
			}
		
		}
	}
	
        if(alter_direction(advX+1, advY)){
                for(int i = 1; i < 6; i++){
                  if(spot+grid_size == event_array[5] && wumpus_health ==1){
                        cout<<"he ded"<<endl;
				break;
                        }
			

			 if(spot + grid_size == event_array[i]){
                                game_setting[advX+1][advY]->print_event_response();
                        }
                       
		
		}
        }


        if(alter_direction(advX, advY-1)){
                for(int i = 1; i < 6; i++){
               	if(spot-1 == event_array[5] && wumpus_health ==1){
                        cout<<"he ded"<<endl;
                                break;
                        }

		
			if(spot - 1 == event_array[i]){
                                game_setting[advX][advY-1]->print_event_response();
                        }
                }
        }


        if(alter_direction(advX, advY+1)){
                for(int i = 1; i < 6; i++){
                        if(spot+1 == event_array[5] && wumpus_health ==1){
                        cout<<"he ded"<<endl;
                                break;
                        }


			if(spot + 1 == event_array[i]){
                                game_setting[advX][advY+1]->print_event_response();
                        }
                }
        }





}


void Map::display_grid(){
	for(int i = 0; i<grid_size; i++){
		for(int j = 0; j < grid_size; j++){
			cout<< " | ";
			if( i == advX && j == advY){
				cout<< "*";
			}
			else{
			cout<< " ";
			}
		}
		cout<< " | "<< endl;
	}

}






void Map::start_random_events(){
	int direction_option = rope_1;
	for (int i = 0; i<grid_size;i++){
		for(int j = 0; j<grid_size;j++){
		if(direction_option ==1){
			rope_spot_x = i;
			advX = i;
			advY= j;
			rope_spot_y=j;
			
			
			}
		direction_option--;
		}
	}

	direction_option = pit_1;

	for(int i = 0; i < grid_size; i++){
		for(int j = 0; j< grid_size; j++){
			if(direction_option ==1){
				game_setting[i][j]->set_pit_event();
				}
			direction_option--;
		}		

	}



        direction_option = pit_2;

        for(int i = 0; i < grid_size; i++){
                for(int j = 0; j< grid_size; j++){
                        if(direction_option ==1){
                                game_setting[i][j]->set_pit_event();
                                }
                        direction_option--;
                }

        }

        direction_option = super_1;

        for(int i = 0; i < grid_size; i++){
                for(int j = 0; j< grid_size; j++){
                        if(direction_option ==1){
                                game_setting[i][j]->set_bat_event();
                                }
                        direction_option--;
                }

        }

        direction_option = super_2;

        for(int i = 0; i < grid_size; i++){
                for(int j = 0; j< grid_size; j++){
                        if(direction_option ==1){
                                game_setting[i][j]->set_bat_event();
                                }
                        direction_option--;
                }

        }

        direction_option = wumpus_1;

        for(int i = 0; i < grid_size; i++){
                for(int j = 0; j< grid_size; j++){
                        if(direction_option ==1){
                                game_setting[i][j]->set_wumpus_event();
                                }
                        direction_option--;
                }

        }

        direction_option = gold_1;

        for(int i = 0; i < grid_size; i++){
                for(int j = 0; j< grid_size; j++){
                        if(direction_option ==1){
                                game_setting[i][j]->set_gold_event();
                                }
                        direction_option--;
                }

        }

}

int Map::event_check(){
	if(player_spot == event_array[1] || player_spot == event_array[2]){
		cout<<"Bats have took you up to another room"<<endl;
		player_spot = rand() % (grid_size * grid_size) + 1;
		
		int new_spot = player_spot;
		for(int i = 0; i< grid_size; i++){
			for(int j=0;j < grid_size; j++){
			if (new_spot == 1){
				advX = i;
				advY = j;
				}
			new_spot--;
			}
		}
		event_check();
			
	}
	else if(player_spot == event_array[3] || player_spot == event_array[4]){
		cout<<"you died after falling in the pit"<<endl;
		return 0;
	}
	else if(player_spot == event_array[6]){
		if(gold_health == 1){
			return 1;
		}
		else{
		cout<<"you enterd the gold room"<<endl;
		gold_health = 1;
	}
	}
	else if(player_spot == event_array[5]){
		if(wumpus_health == 1){
			return 1;
			}
		else{
		cout<<"you have died by wumpus"<<endl;
		arrow = 3;
		wumpus_health=0;
		gold_health=0;
		return 0;
	}
	}
	return 1;	

}





Map::~Map()
{

}

#endif