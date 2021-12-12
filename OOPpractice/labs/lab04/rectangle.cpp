#include "rectangle.h"

Rectangle::Rectangle() : Shape()
{
    width = 0;
    height = 0;
}

Rectangle::Rectangle(float width1, float height1, string name, string color) : Shape(name, color)
{
    height1 = height;
    width1 = width;

}

float Rectangle::get_width(){
    return width;
}

float Rectangle::get_height(){
    return height;
}

void Rectangle::set_height(float height1)
{
    height = height1;
}

void Rectangle::set_width(float width1)
{
    width = width1;
}

float Rectangle::area() const
{
    return width*height;
}