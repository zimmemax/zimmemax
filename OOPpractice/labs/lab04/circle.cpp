#include "circle.h"
Circle::Circle() : Shape()
{
    radius = 0;
}

Circle::Circle(float radius1, string name, string color) : Shape(name, color)
{
    radius1 = radius;

}

float Circle::get_radius(){
    return radius;
}

void Circle::set_radius(float radius1)
{
    radius = radius1;
}

float Circle::area() const
{
    return 3.14*(radius*radius);
}