#ifndef CELESTIALBODY_H_
#define CELESTIALBODY_H_

#include "Position.h"
#include "Velocity.h" 
#include <fstream>
using std::ofstream;

//CelestialBody class,
class CelestialBody: public Position, public Velocity{
 public:
  double mass_;
  Position Pos_;
  Velocity Vel_;

  //constructor
  CelestialBody(double m, Position r, Velocity v);

  //output its position to a ofstream
  ofstream & GetPosition(ofstream &s);  

};  






#endif // CELESTIALBODY_H_
