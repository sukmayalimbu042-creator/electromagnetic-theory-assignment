#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Vector3D { double x, y, z; };

Vector3D calculateB3D(double I, Vector3D pos) {
    const double mu0 = 4 * M_PI * 1e-7;
    
    double r = std::sqrt(pos.x * pos.x + pos.y * pos.y);
    
    if (r == 0) return {0, 0, 0}; 

    double magnitude = (mu0 * I) / (2 * M_PI * r);

    
    return { -magnitude * (pos.y / r), magnitude * (pos.x / r), 0.0 };
}

int main() {
    Vector3D point = {0.1, 0.1, 0.5};
    Vector3D B = calculateB3D(15.0, point);
    cout << "3D B-Field at (0.1, 0.1, 0.5): [" 
              << B.x << ", " << B.y << ", " << B.z << "] T" << endl;
}