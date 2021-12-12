#include <iostream>
#include <iomanip>
#include <string>
#ifndef SHAPE_H
#define SHAPE_H


using namespace std;
class Shape {
    private:
        string name;
        string color;
    public:
        Shape();
        Shape(string, string);
        string get_name();
        string get_color();
        virtual float area() const =0;

        void set_name(string);
        void set_color(string);
        

        
};
#endif