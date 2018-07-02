#include "Velocity.h"

Velocity &Velocity::operator=(Velocity &v){
  x_ = v.x_;
  y_ = v.y_;
  z_ = v.z_;
  unit_ = v.unit_;
  return *this;
}
  
Velocity::Velocity (double x, double y, double z){
  x_ = x;
  y_ = y;
  z_ = z;
}
