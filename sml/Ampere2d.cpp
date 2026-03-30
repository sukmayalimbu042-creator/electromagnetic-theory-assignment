#include <iostream>
#include <cmath>

struct Vector2D { double bx, by; };

Vector2D calculateB2D(double I, double x, double y) {
    const double mu0 = 4 * M_PI * 1e-7;
    double r = std::sqrt(x*x + y*y);
    double magnitude = (mu0 * I) / (2 * M_PI * r);
    
    // The field is perpendicular to the radius vector (-y, x)
    return { -magnitude * (y / r), magnitude * (x / r) };
}

int main() {
    Vector2D field = calculateB2D(10.0, 0.03, 0.04);
    std::cout << "2D B-Field: (" << field.bx << ", " << field.by << ") T" << std::endl;
}