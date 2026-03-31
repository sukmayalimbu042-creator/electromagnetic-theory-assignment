#include <iostream>
using namespace std;

int main() {
    int n = 10;
    double dx = 1.0;
    double lemda = 1.0;
    double eps0 = 1.0;

    double E[10];

    E[0] = 0;

    for(int i = 1; i < n; i++) {
        E[i] = E[i-1] + (lemda/eps0)*dx;
    }

    for(int i = 0; i < n; i++) {
        cout << "x = " << i*dx << "  E = " << E[i] << endl;
    }

    return 0;
}