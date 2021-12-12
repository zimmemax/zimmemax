#include "square.h"

Square::Square() : Rectangle()
{
    side = 0;
}
Square::Square(float side1) : Rectangle()
{
    side = side1;
}

float Square::get_side()
{
    return side;
}

void Square::set_side(float side1){
    side = side1;

}

/*float area() const{
    return (side*side);
}*/