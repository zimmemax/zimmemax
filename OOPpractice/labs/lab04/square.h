#include "shape.h"
#include "rectangle.h"
#ifndef SQUARE_H
#define SQUARE_H


class Square : public Rectangle {
   private:
      float side;
   public:
      Square();
      Square(float);
      void set_side(float);
      //float area() const;

      float get_side();
      
      
};

#endif