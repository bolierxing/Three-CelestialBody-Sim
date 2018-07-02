#include "CelestialBody.h"
using std::endl;


CelestialBody::CelestialBody(double m, Position r, Velocity v){
  mass_ = m;
  Pos_  = r;
  Vel_  = v;
}

ofstream &CelestialBody::GetPosition(ofstream &s){
  s << Pos_.x_ <<"\t"<< Pos_.y_ <<"\t"<< Pos_.z_ << endl;
  return s;
}
  
