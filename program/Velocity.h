#ifndef VELOCITY_H_
#define VELOCITY_H_
#include <string>
#include "Vector3D.h"

//Velocity class
class Velocity: public Vector3D{
 public:
  std::string unit_ = "m/s";

  //default construcor
  Velocity() = default;

  //constructor
  Velocity(double x, double y, double z);

  //operate = 
  Velocity &operator=(Velocity &v);
  
};

  


#endif // VELOCITY_H_
