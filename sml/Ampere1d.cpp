#include <iostream>
#include <cmath>
#include <vector>

using namespace std;



int main() {
    
    const double mu_0 = 1.256637e-6; 
    double dx = 0.01;                

    

    vector<double> By = {0.0020, 0.0025, 0.0030}; 

    
    double dB_dx = (By[2] - By[0]) / (2 * dx);


    double Jz = dB_dx / mu_0;

    
    cout << "Magnetic Field Gradient (dB/dx): " << dB_dx << " T/m" << endl;
    cout << "Calculated Current Density (Jz): " << Jz << " A/m^2" << endl;

    return 0;
}