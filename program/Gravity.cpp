#include "Gravity.h"
#include "Vector3D.h"
#include "CelestialBody.h"

Gravity &Gravity::operator=(Gravity &F){
  x_ = F.x_;
  y_ = F.y_;
  z_ = F.z_;
  unit_ = F.unit_;
  return *this;
}
  
  
  

Gravity::Gravity (const Vector3D &v){
  x_ = v.x_;
  y_ = v.y_;
  z_ = v.z_;
  unit_ = "N";
}


void Gravity::Update_F(double G, CelestialBody & m, CelestialBody & m1, CelestialBody & m2){
  x_ = (m1.Pos_.x_ - m.Pos_.x_)*(G*m1.mass_*m.mass_)/m1.Pos_.Distance(m.Pos_)/m1.Pos_.Distance(m.Pos_)/m1.Pos_.Distance(m.Pos_) +
       (m2.Pos_.x_ - m.Pos_.x_)*(G*m2.mass_*m.mass_)/m2.Pos_.Distance(m.Pos_)/m2.Pos_.Distance(m.Pos_)/m2.Pos_.Distance(m.Pos_);

  y_ = (m1.Pos_.y_ - m.Pos_.y_)*(G*m1.mass_*m.mass_)/m1.Pos_.Distance(m.Pos_)/m1.Pos_.Distance(m.Pos_)/m1.Pos_.Distance(m.Pos_) +
       (m2.Pos_.y_ - m.Pos_.y_)*(G*m2.mass_*m.mass_)/m2.Pos_.Distance(m.Pos_)/m2.Pos_.Distance(m.Pos_)/m2.Pos_.Distance(m.Pos_);
  
  z_ = (m1.Pos_.z_ - m.Pos_.z_)*(G*m1.mass_*m.mass_)/m1.Pos_.Distance(m.Pos_)/m1.Pos_.Distance(m.Pos_)/m1.Pos_.Distance(m.Pos_) +
       (m2.Pos_.z_ - m.Pos_.z_)*(G*m2.mass_*m.mass_)/m2.Pos_.Distance(m.Pos_)/m2.Pos_.Distance(m.Pos_)/m2.Pos_.Distance(m.Pos_);
  
}
