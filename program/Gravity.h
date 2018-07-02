#ifndef GRAVITY_H_
#define GRAVITY_H_
#include <string>
#include "Vector3D.h"
class CelestialBody;

//Gravity class
class Gravity: public Vector3D {
 public:
  std::string unit_ = "N";

  //default constructor
  Gravity() = default;

  //copy constructor
  Gravity(const Vector3D &v);

  //operate =
  Gravity &operator=(Gravity &F);

  //update Gravity according to three CelestalBodies' position
  void Update_F(double G, CelestialBody & m, CelestialBody & m1, CelestialBody & m2);
};

#endif //GRAVITY_H_
