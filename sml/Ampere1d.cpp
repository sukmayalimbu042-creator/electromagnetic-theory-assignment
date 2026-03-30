#include <iostream>
#include <cmath>
using namespace std;

double calculateB1D(double I, double r) {
    const double mu0 = 4 * M_PI * 1e-7; 
    return (mu0 * I) / (2 * M_PI * r);
}

int main() {
    double current = 10.0; 
    double radius = 0.05;  
    cout << "1D B-Field: " << calculateB1D(current, radius) << " Tesla" << endl;
    return 0;
}