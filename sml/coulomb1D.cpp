#include <iostream>
#include <cmath>
using namespace std;
int main(){
    const double k = 8.85e9;
    double Q1, Q2, x1, x2;
    
    cout<<"Enter a charge Q1:";
    cin>>Q1;
    cout<<"Enter a charge Q2:";
    cin>>Q2;
    cout<<"Enter a value of x1:";
    cin>>x1;
    cout<<"Enter a value of x2:";
    cin>>x2;
     double r = fabs(x2 - x1);
     
     double F = k*Q1*Q2/(r*r*r);

cout<<"Force =";
    cout<<F<<"N"<<endl;










}