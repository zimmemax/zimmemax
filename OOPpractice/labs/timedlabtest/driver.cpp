#include "pet.h"
#include "dog.h"

int main()
{
    Pet pet_object;
    Dog* dog_array;

    string temp_name;
    //first part
    cout << "Enter name of pet: ";
    cin >> temp_name;
    pet_object.set_name(temp_name);
    cout << endl;
    int temp_weight;
    cout << "Enter weight of pet: ";
    cin >> temp_weight;
    pet_object.set_weight(temp_weight);
    cout << endl;

    cout << "Lifespan of pet: " << pet_object.get_lifespan() << endl;
    cout << endl << endl << endl;

    //second part
    int dog_num;
    cout << "How many dogs cuz: ";
    cin >> dog_num;
    cout << endl;
    dog_array = new Dog[dog_num];

    for(int i = 0; i < dog_num; i++)
    {
        string name1;
        int weight1;
        string breed1;
        cout << "Enter name: ";
        cin >> name1;
        cout << endl;

        cout << "Enter weight: ";
        cin >> weight1;
        cout << endl;

        cout << "Enter breed: ";
        cin >> breed1;
        cout << endl;

        dog_array[i].set_name(name1);
        dog_array[i].set_weight(weight1);
        dog_array[i].set_breed(breed1);
    }

    for(int i = 0; i < dog_num; i++)
    {
        cout << "Dog name " << dog_array[i].get_name() << " lifespan is: " << dog_array[i].get_lifespan();
        cout << endl;
    }

    delete[] dog_array;

}