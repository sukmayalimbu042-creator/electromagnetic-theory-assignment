#include<iostream>
#include<cmath>
using namespace std;
int main() {
double  const k = 8.99e9;
double Q1, Q2, x1, x2, y1, y2, z1,z2;
cout<<"Enter a charge Q1 Q2:";
cin>>Q1>>Q2;
cout<<"Enter a value of x1 x2:";
cin>>x1>>x2;
cout<<"Enter a value of y1 y2:";
cin>>y1>>y2;
cout<<"Enter a value of z1 z2:";
cin>>z1>>z2;

double dx = x2 - x1;
double dy = y2 - y1;
double dz = z2 - z1;
double r = sqrt(dx*dx + dy*dy + dz*dz);
 double Fx = k*Q1*Q2*dx/(r*r*r);
 double Fy = k*Q1*Q2*dy/(r*r*r);
 double Fz = k*Q1*Q2*dz/(r*r*r);

 cout<<"Fx ="<<Fx<<"N"<<endl;
 cout<<"Fy ="<<Fy<<"N"<<endl;
 cout<<"Fz ="<<Fz<<"N"<<endl;
}



