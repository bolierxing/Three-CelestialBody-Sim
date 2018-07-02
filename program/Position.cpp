#include "Position.h"
#include "Gravity.h"
#include "Velocity.h"

Position &Position::operator=(Position r){
  x_ = r.x_;
  y_ = r.y_;
  z_ = r.z_;
  unit_ = r.unit_;
  return *this;
}

Position::Position(double x, double y, double z){
  x_ = x;
  y_ = y;
  z_ = z;
}

void Position::Update_r(Velocity &v,Gravity &F,double h,double m){
  v.x_ += F.x_*(h/2/m);
  v.y_ += F.y_*(h/2/m);
  v.z_ += F.z_*(h/2/m);
  
  this->x_ += v.x_*(h);
  this->y_ += v.y_*(h);
  this->z_ += v.z_*(h);
  
  v.x_ += F.x_*(h/2/m);
  v.y_ += F.y_*(h/2/m);
  v.z_ += F.z_*(h/2/m); 
}
  
  
