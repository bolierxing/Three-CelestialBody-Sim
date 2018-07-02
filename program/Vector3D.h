#ifndef VECTOR3D_H_
#define VECTOR3D_H_


class Vector3D {

 public:
  // functions exposed
  // the constructor
  Vector3D () = default;

  Vector3D (double x, double y, double z);

  Vector3D (Vector3D &v);

  double GetX ()  { return x_; }

  double GetY ()  { return y_; }

  double GetZ ()  { return z_; }

  double Length () ;

  double Magnitude() ;

  double Distance (Vector3D & v) ;

  Vector3D & Scale (double d);

  double Angle ( Vector3D &v) ;

  Vector3D Add ( Vector3D &v) ;

  double DotProduction ( Vector3D &v) ;

  Vector3D CrossProduction ( Vector3D &v);

  Vector3D & operator+= (Vector3D & rhs);

  Vector3D operator*(double s) ;

  // protected: Why must be protected?
  // the data members
  double x_ ;
  double y_ ;
  double z_ ;
  
};




#endif // VECTOR3D_H_
