#include "shape.h"
#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle : public Shape {
   private:
      float width;
      float height;
   public:
      Rectangle();
      Rectangle(float,float,string,string);
      void set_width(float);
      void set_height(float);
      float area() const;

      float get_width();
      float get_height();
      friend bool operator> (const Rectangle &, const Rectangle &);
      friend bool operator< (const Rectangle &, const Rectangle &);
      
      
};

#endif