#include <iostream>
using namespace std;

int main() {
    int n = 5;
    double dx = 1.0, dy = 1.0;
    double eps0 = 1.0;

    double sigma[5][5], Ex[5][5], Ey[5][5];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            sigma[i][j] = 1.0;
            Ex[i][j] = 0.0;
            Ey[i][j] = 0.0;
        }
    }

    for(int i = 1; i < n-1; i++) {
        for(int j = 1; j < n-1; j++) {
            double divE = (Ex[i+1][j] - Ex[i-1][j])/(2*dx)
                        + (Ey[i][j+1] - Ey[i][j-1])/(2*dy);

            double result = sigma[i][j] / eps0;

            cout << "Point = " << i << "," << j << " ";
            cout << "divE = " << divE << " , sigma/eps0 = " << result << endl;
        }
    }

    return 0;
}