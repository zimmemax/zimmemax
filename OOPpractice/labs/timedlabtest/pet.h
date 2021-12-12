#ifndef PET_H
#define PET_H


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;





class Pet
{

protected:
    string name;
    int weight;


public:

    Pet();
    Pet(string, int);
    int get_weight();
    string get_name();
    string get_lifespan();
    void set_weight(int);
    void set_name(string);


};

#endif