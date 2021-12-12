#include <iostream>
#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "square.h"

bool operator> (const Rectangle &r1, const Rectangle &r2){
        return r1.area()>r2.area();
}
bool operator< (const Rectangle &r1, const Rectangle &r2){
        return r1.area()<r2.area(); 

}

int main()
{
    Circle c;
    Rectangle r1;
    Rectangle r2;
    r1.set_name("rectangle");
    r1.set_width(4.0);
    r1.set_height(3.0);
    r1.set_color("blue");

    r2.set_name("rectangle");
    r2.set_width(5.0);
    r2.set_height(4.0);
    r2.set_color("blueish");



    c.set_name("circle");
    c.set_radius(2.5);
    c.set_color("orange");

    if(r1>r2){
        cout << endl;
        cout << "r1 is greater than r2";
    }
    if(r2>r1){
        cout << endl;
        cout << "r2 is greater than r1";
    }
    
    cout << r1.get_name();
    cout << endl;
    cout << r1.get_color();
    cout << endl;

    cout << "area is: " << r1.area();
    cout << endl;

    cout << endl;
    cout << c.get_name() << endl;
    cout << c.get_color() << endl;
    cout << "Area for circle is: " << c.area();
    cout << endl;

    Square s;
    s.set_side(5);
    int side = s.get_side();
    s.set_name("square");
    s.set_color("dark_blue");
    cout << endl;
    cout << "Color is " << s.get_color() << endl;
    cout << "Name is " << s.get_name() << endl;
    cout << "Area is " << side*side << endl;
    


    //circle c1(2.5);




}
