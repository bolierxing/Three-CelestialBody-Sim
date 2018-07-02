#include "Vector3D.h"
#include <fstream>
#include <cmath>

using std::sqrt;
using std::acos;

Vector3D::Vector3D (double x, double y, double z){
  x_ = x ;
  y_ = y ;
  z_ = z ;
}

Vector3D::Vector3D ( Vector3D &v){
  x_ = v.x_;
  y_ = v.y_;
  z_ = v.z_;
}
 

double Vector3D::Length ()
{
  return sqrt(x_ * x_ + y_ * y_ + z_ * z_);
}

double Vector3D::Magnitude () 
{
  return Length();
}

double Vector3D::Distance ( Vector3D & v) 
{
  double dx = x_ - v.x_;
  double dy = y_ - v.y_;
  double dz = z_ - v.z_;
  return sqrt(dx * dx + dy * dy + dz * dz);
}

Vector3D & Vector3D::Scale (double d)
{
  x_ *= d;
  y_ *= d;
  z_ *= d;
  return *this;
}

double Vector3D::Angle (Vector3D &v) 
{
  if (Length() == 0 || v.Length() == 0)
    return 0;
  return acos(DotProduction(v) / (Length() * v.Length()));
}

Vector3D Vector3D::Add (Vector3D &v)
{
  double x = x_ + v.x_;
  double y = y_ + v.y_;
  double z = z_ + v.z_;
  Vector3D vv(x,y,z);
  return vv;
}

double Vector3D::DotProduction (Vector3D &v) 
{
  return x_ * v.x_ + y_ * v.y_ + z_ * v.z_;
}

Vector3D Vector3D::CrossProduction ( Vector3D &v)
{
  double x = y_ * v.z_ - z_ * v.y_;
  double y = z_ * v.x_ - x_ * v.z_;
  double z = x_ * v.y_ - y_ * v.x_;
  Vector3D vv(x,y,z);
  return vv;
}

Vector3D & Vector3D::operator+= ( Vector3D & rhs)
{
  x_ += rhs.x_;
  y_ += rhs.y_;
  z_ += rhs.z_;
  return *this;
}

Vector3D Vector3D::operator*(double s) 
{
  Vector3D vv(x_ * s, y_ * s, z_ * s);
  return vv;
}


