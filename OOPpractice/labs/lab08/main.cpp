#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(std::vector <int> arr, int n)
{
    int i, j, min_index;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n; i++)
    {
        // Find the minimum element in unsorted array
        min_index = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_index])
        { 
            min_index = j;
        }
 
        // Swap the found minimum element with the first element
        swap(&arr[min_index], &arr[i]);
        
    }
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

}
 

int prime_number(int n)
{
    int size = n/2;
    int remainder_array[size-2];
    for(int i = 2; i < size; i++)
    {
        remainder_array[i-2] = n%i;
    }
    for(int i = 0; i < size; i++)
    {
        if(remainder_array[i] == 0)
        {
            cout << remainder_array[i];
            return false;
        }
    }

}

int main()
{
    int size;
    srand(time(NULL));
    cout << "Enter a number cutie: ";
    cin >> size;
    cout << endl;
    while(true)
    {
        if((size <= 0) || size > 25)
        {
            cout << "Enter proper number: ";
            cin >> size;
            cout << endl;
        }
        else
        {
            break;
        }
    }
    int *array = new int[size];

    for(int i = 0; i < size; i++)
    {
        int random = rand() % 100 + 1;
        array[i] = random;
    }
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << endl;
    }
    cout << endl;
    //copy vector
    std::vector<int> vect(array + 0, array + size);
    for(int i = 0; i < vect.size(); i++)
    {
        cout << "Vector print: " << vect[i] << endl; 
    }
    
    //ascending order sort
    cout << endl;
    cout << "Ascending order" << endl;
    selectionSort(vect, vect.size());

    

    //prime numbers
    std::vector<int> prime;
    for(int i = 0; i < vect.size(); i++)
    {
        if(prime_number(vect[i]))
        {
            prime.push_back(vect[i]);
        }
    }
    cout << endl;

    for(int i = 0; i < prime.size(); i++)
    {
        cout << "A prime number is: " << prime[i] << endl;
    }



    delete[] array;

    
}