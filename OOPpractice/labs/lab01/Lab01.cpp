#include <iostream>
#include <stdlib.h>

using namespace std;
	

bool is_valid_number(char* n){
	
	while(!atoi(n)){
		cout << "Invalid entry, retry: ";
		cin >> n;
		cout << endl;
	}
	return true;
	}
int* create_array(int n){

	char newEntry;
	int* array_dyna = new int[n];

	for(int i = 0; i < n; i++){

		cout << "Enter value: ";
		cin >> newEntry;
		cout << endl;

		is_valid_number(&newEntry);
		array_dyna[i] = atoi(&newEntry);
	
		}
	cout << endl;
	return array_dyna;
}

int find_maximum(int *number_array, int size){
	int max = number_array[0];
	for(int i = 1; i < size; i++){
		if(max < number_array[i]){
			max = number_array[i];
		}
		

	}
	return max;


}

int find_minimum(int *number_array, int size){

	int min = number_array[0];
	for(int i = 1; i < size; i++){
		if(min > number_array[i]){
			min = number_array[i];
		}
	}
	return min;
}	

int find_average(int *number_array, int size){

	int total = 0;
	for(int i = 0; i < size; i++){
		total = number_array[i] + total;

	}

	return total/size;


}

void menu(int *number_array, int size){

	int answer=0;
	int size1 = 5;
	

	while(answer != 4){
	
		cout << "Enter 1 for Min, 2 For Max, 3 for Average, 4 for quit: ";
		cin >> answer;
		cout << endl;

		if(answer == 1){

			int min = find_minimum(number_array, size1);
			cout << min;
			 
		}
		else if(answer == 2){
			int max = find_maximum(number_array, size1);
			cout << max;
		
		}

		else if(answer == 3){
	
			int average = find_average(number_array, size1);
			cout << average;
		}	

		else if(answer == 4){
			cout << "Bye!";
		}

		 else{
	
			cout << "Enter proper int: ";
			cin >> answer;

		}
	}
}	

void delete_array(int *num_array){

	delete num_array;
}

int main(int argc, char *argv[]){
	
	is_valid_number(argv[1]);
	int SIZE = atoi(argv[1]);
	int* number_array = create_array(SIZE);
	menu(number_array, SIZE);
	delete_array(number_array);
		
}
