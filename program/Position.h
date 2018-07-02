#ifndef POSITION_H_
#define POSITION_H_
#include <string>
#include "Vector3D.h"
class  Velocity;
class  Gravity;

//Position class
class Position: public Vector3D {
 public:
  std::string unit_ = "m";

  //default constructor
  Position() = default;

  //constructor
  Position (double x, double y, double z);

  //opetator =
  Position & operator=(Position r);
  
  //update Position(update Velocity implicitly)
  void Update_r(Velocity &v,Gravity &F,double h,double m);
};

#endif // POSITION_H_
