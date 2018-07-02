#include "TCanvas.h"
#include "TGraph2D.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include "CelestialBody.h"
#include "Gravity.h"

using namespace std;

//Get the maxmiun and minimum of three numbers
double min(double x1 ,double x2)
{
  return x1 < x2 ? x1 : x2;
}
double min(double x1 ,double x2 ,double x3)
{
  return min(min(x1 , x2) , x3);
}

double max(double x1 ,double x2)
{
  return x1 > x2 ? x1 : x2;
}
double max(double x1 ,double x2 ,double x3)
{
  return max(max(x1 , x2) , x3);
}

//Get the scale of all datas to let ROOT draw a background
void scale(){
  ifstream fin1("data1.dat");
  ifstream fin2("data2.dat");
  ifstream fin3("data3.dat");
  ofstream fout("scale.dat");
  
  double x1,y1,z1,x2,y2,z2,x3,y3,z3;
  double xmin,xmax,ymin,ymax,zmin,zmax;
  int i = 1;
  while (fin1 >> x1)
    {
      fin1 >> y1 >> z1;
      fin2 >> x2 >> y2 >> z2;
      fin3 >> x3 >> y3 >> z3;
      if (i)
	{
	  xmin = min(x1 ,x2 ,x3);
	  xmax = max(x1 ,x2 ,x3);
	  ymin = min(y1 ,y2 ,y3);
	  ymax = max(y1 ,y2 ,y3);
	  zmin = min(z1 ,z2 ,z3);
	  zmax = max(z1 ,z2 ,z3);
	  i = 0;
	}
      else
	{
	  xmin = min(xmin , min(x1 ,x2 ,x3));
	  xmax = max(xmax , max(x1 ,x2 ,x3));
	  ymin = min(ymin , min(y1 ,y2 ,y3));
	  ymax = max(ymax , max(y1 ,y2 ,y3));
	  zmin = min(zmin , min(z1 ,z2 ,z3));
	  zmax = max(zmax , max(z1 ,z2 ,z3));

	}
    }
  if (fabs(xmin - xmax) <= 1e-11)
    {
      xmin = xmin - 1;
      xmax = xmax + 1;
    }
  if (fabs(ymin - ymax) <= 1e-11)
    {
      ymin = ymin - 1;
      ymax = ymax + 1;
    }
  if (fabs(zmin - zmax) <= 1e-11)
    {
      zmin = zmin - 1;
      zmax = zmax + 1;
    }
  fout << xmin << "\t" << ymin << "\t" << zmin << endl;
  fout << xmax << "\t" << ymax << "\t" << zmax << endl;
}

//Draw a picture with ROOT
void Pic(){
  TCanvas c("c","Locus of CelestialBody",600,600);

  TGraph2D scale("scale.dat","%lg %lg %lg","\t");
  scale.SetName("scale");
  scale.SetTitle("Body1:Red  Body2:Green  Body3:Blue; x(m); y(m); z(m)");
  scale.SetLineColor(1);//black

  TGraph2D star1("data1.dat","%lg %lg %lg","\t");
  star1.SetName("Celestialbody1");
  star1.SetLineColor(2);//red
  
  TGraph2D star2("data2.dat","%lg %lg %lg","\t");
  star2.SetName("Celestialbody2");
  star2.SetLineColor(3);//green

  TGraph2D star3("data3.dat","%lg %lg %lg","\t");
  star3.SetName("Celestialbody3");
  star3.SetLineColor(4);//blue

  scale.Draw("P");
  star1.Draw("LINE SAME");
  star2.Draw("LINE SAME");
  star3.Draw("LINE SAME");
  
  c.Print("Locus.gif");
}

//Simulate and draw using functions above
int main(){
  //  const double G = 6.67E-11;
  const double G = 1;
  double h, t, m1, m2, m3, V1_x, V1_y, V1_z, V2_x, V2_y, V2_z, V3_x, V3_y, V3_z, r1_x, r1_y, r1_z, r2_x, r2_y, r2_z, r3_x, r3_y, r3_z;
  
  cout << "How long do you want to simulate?(s) "<<endl;
  cin >> t;
  cout << "Please enter 1 number to get the timestep(s) "<<endl;
  cin >> h;
  cout << "Please enter 3 number to get the mass of the three celestialbodies(m1,m2,m3)(kg):"<<endl;
  cin >> m1 >> m2 >> m3;
  cout << "Please enter 3 number to get the initial velocity of m1(Vx,Vy,Vz)(m/s):"<<endl;
  cin >> V1_x >> V1_y >> V1_z;
  cout << "Please enter 3 number to get the initial velocity of m2(Vx,Vy,Vz)(m/s):"<<endl;
  cin >> V2_x >> V2_y >> V2_z;
  cout << "Please enter 3 number to get the initial velocity of m3(Vx,Vy,Vz)(m/s):"<<endl;
  cin >> V3_x >> V3_y >> V3_z;
  cout << "Please enter 3 number to get the initial position of m1(x,y,z)(m):"<<endl;
  cin >> r1_x >> r1_y >> r1_z;
  cout << "Please enter 3 number to get the initial position of m2(x,y,z)(m):"<<endl;
  cin >> r2_x >> r2_y >> r2_z;
  cout << "Please enter 3 number to get the initial position of m3(x,y,z)(m):"<<endl;
  cin >> r3_x >> r3_y >> r3_z;

  Velocity v1(V1_x, V1_y, V1_z), v2(V2_x, V2_y, V2_z), v3(V3_x, V3_y, V3_z);
  Position r1(r1_x, r1_y, r1_z), r2(r2_x, r2_y, r2_z), r3(r3_x, r3_y, r3_z);
  CelestialBody star1(m1,r1,v1), star2(m2,r2,v2), star3(m3,r3,v3);

  double m1m2 = G*m1*m2/(r1.Distance(r2))/(r1.Distance(r2))/(r1.Distance(r2));
  double m1m3 = G*m1*m3/(r1.Distance(r3))/(r1.Distance(r3))/(r1.Distance(r3));
  double m2m3 = G*m2*m3/(r2.Distance(r3))/(r2.Distance(r3))/(r2.Distance(r3));

  Vector3D r12(r1_x-r2_x,r1_y-r2_y,r1_z-r2_z), r21(r2_x-r1_x,r2_y-r1_y,r2_z-r1_z), r13(r1_x-r3_x,r1_y-r3_y,r1_z-r3_z), r31(r3_x-r1_x,r3_y-r1_y,r3_z-r1_z),r23(r2_x-r3_x,r2_y-r3_y,r2_z-r3_z),r32(r3_x-r2_x,r3_y-r2_y,r3_z-r2_z);

  Gravity F12(r12*(m1m2)), F21(r21*(m1m2)), F13(r13*(m1m3)), F31(r31*(m1m3)), F23(r23*(m2m3)), F32(r32*(m2m3));
  
  Gravity F1 = F21.Add(F31), F2 = F12.Add(F32), F3 = F13.Add(F23);

  int i = 0;
  int n = t/h;

  ofstream s1("data1.dat");
  ofstream s2("data2.dat");
  ofstream s3("data3.dat");

  for (i=0;i<n;i++){
    if (star1.Pos_.Distance(star2.Pos_)<0 or star1.Pos_.Distance(star3.Pos_)<0 or star2.Pos_.Distance(star3.Pos_)<0.01){
      cout << "CelestialBody bash another one, break! "<<endl;
      return 1;
    }
    star1.Pos_.Update_r(v1,F1,h,m1);
    star2.Pos_.Update_r(v2,F2,h,m2);
    star3.Pos_.Update_r(v3,F3,h,m3);

    F1.Update_F(G,star1,star2,star3);
    F2.Update_F(G,star2,star1,star3);
    F3.Update_F(G,star3,star1,star2);
  
    star1.GetPosition(s1);
    star2.GetPosition(s2);
    star3.GetPosition(s3);    
  }
  
  scale();
  Pic();
  return 0;
}
  
