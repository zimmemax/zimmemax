#include "shape.h"
#ifndef CIRCLE_H
#define CIRCLE_H


class Circle : public Shape {
   private:
      float radius;
   public:
      Circle();
      Circle(float,string,string);
      void set_radius(float);
      float area() const;

      float get_radius();
      
      
};

#endif