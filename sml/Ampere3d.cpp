#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    
    const double mu_0 = 4.0 * M_PI * 1e-7; 
    double h = 0.01;                   

    
    double Bz_y_plus = 0.0015,  Bz_y_minus = 0.0010; 
    double By_z_plus = 0.0005,  By_z_minus = 0.0008;

    
    double Bx_z_plus = 0.0012,  Bx_z_minus = 0.0010;
    double Bz_x_plus = 0.0020,  Bz_x_minus = 0.0018;

    
    double By_x_plus = 0.0030,  By_x_minus = 0.0010;
    double Bx_y_plus = 0.0015,  Bx_y_minus = 0.0025;

    
    double dBz_dy = (Bz_y_plus - Bz_y_minus) / (2 * h);
    double dBy_dz = (By_z_plus - By_z_minus) / (2 * h);
    
    double dBx_dz = (Bx_z_plus - Bx_z_minus) / (2 * h);
    double dBz_dx = (Bz_x_plus - Bz_x_minus) / (2 * h);
    
    double dBy_dx = (By_x_plus - By_x_minus) / (2 * h);
    double dBx_dy = (Bx_y_plus - Bx_y_minus) / (2 * h);

    
    double curl_x = dBz_dy - dBy_dz;
    double curl_y = dBx_dz - dBz_dx;
    double curl_z = dBy_dx - dBx_dy;

    
    double Jx = curl_x / mu_0;
    double Jy = curl_y / mu_0;
    double Jz = curl_z / mu_0;

    
    
    cout << "Jx: " << Jx << endl;
    cout << "Jy: " << Jy << endl;
    cout << "Jz: " << Jz << endl;
    cout << "Total Magnitude: " << sqrt(Jx*Jx + Jy*Jy + Jz*Jz) << " A/m^2" << endl;

    return 0;
}