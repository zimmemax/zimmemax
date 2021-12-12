#include "shape.h"

Shape::Shape()
{
    color = "";
    name = "";

}

Shape::Shape(string new_name, string new_color)
{
    name = new_name;
    color = new_color;
}
void Shape::set_name(string new_name)
{
    name = new_name;
}
void Shape::set_color(string new_color)
{
    color = new_color;
}

string Shape::get_name(){

    return name;
}
string Shape::get_color(){

    return color;
}




