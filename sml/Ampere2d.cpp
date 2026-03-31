#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


int main() {
    
    const double mu_0 = 4.0 * M_PI * 1e-7; 
    double h = 0.01;                   

    
    
    
    double By_right = 0.0030; 
    double By_left  = 0.0010;


    double Bx_up    = 0.0015;
    double Bx_down  = 0.0025;

    
    double dBy_dx = (By_right - By_left) / (2 * h);
    double dBx_dy = (Bx_up - Bx_down) / (2 * h);

    
    double curl_B_z = dBy_dx - dBx_dy;
    double Jz = curl_B_z / mu_0;

    
    cout << "Partial dB_y/dx: " << dBy_dx << " T/m" << endl;
    cout << "Partial dB_x/dy: " << dBx_dy << " T/m" << endl;
    cout << "Total Curl (B):  " << curl_B_z << " T/m" << endl;
    cout << "Current Density (Jz): " << Jz << " A/m^2" << endl;

    return 0;
}