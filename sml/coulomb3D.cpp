#include <iostream>
#include <cmath>
using namespace std;
int main(){
     const double k = 8.99e9;
    double Q1, Q2, x1, x2, y1, y2,z1,z2;
    cout<<"Enter a charge Q1:";
    cin>>Q1;
    cout<<"Enter a charge Q2:";
    cin>>Q2;
    cout<<"Enter a value of x1:";
    cin>>x1;
    cout<<"Enter a value of x2:";
    cin>>x2;
    cout<<"Enter a value of y1:";
    cin>>y1;
    cout<<"Enter a value of y2:";
    cin>>y2;
    cout<<"Enter a value of z1:";
    cin>>z1;
    cout<<"Enter a value of z2:";
    cin>>z2;
    double dx = x2 - x1;
    double dy = y2 - y1;
    double dz = z2 - z1;
     double r = sqrt(dx*dx + dy*dy + dz*dz);

     double Fx = k*Q1*Q2*dx/(r*r*r);
     double Fy = k*Q1*Q2*dy/(r*r*r);
     double Fz = k*Q1*Q2*dz/(r*r*r);
     cout<<"Fx ="<<Fx<<"N"<<endl;
     cout<<"Fy ="<<Fy<<"N"<<endl;
     cout<< "Fz ="<<Fz<<"N"<<endl;
}



