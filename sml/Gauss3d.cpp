#include <iostream>
#include <cmath> 

using namespace std;

const int N = 5;
double rho[N][N][N];
double Ex[N][N][N], Ey[N][N][N], Ez[N][N][N];

int main()
{
    double eps0 = 8.85e-12;
    double dx = 1.0;

    
    for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
    for(int k=0; k<N; k++)
        rho[i][j][k] = 1.0;

    // 2. Initialize Electric Field components 
    // To satisfy Div E = rho/eps0, we split the divergence 
    // equally among the three dimensions (1/3 each).
    for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
    for(int k=0; k<N; k++)
    {
        double factor = rho[i][j][k] / (3.0 * eps0);
        Ex[i][j][k] = factor * (i * dx); 
        Ey[i][j][k] = factor * (j * dx);
        Ez[i][j][k] = factor * (k * dx);
    }

    // 3. Calculate Numerical Divergence
    cout << fixed << setprecision(2);
    for(int i=1; i<N-1; i++)
    for(int j=1; j<N-1; j++)
    for(int k=1; k<N-1; k++)
    {
        double divE =
        (Ex[i+1][j][k] - Ex[i-1][j][k])/(2*dx) +
        (Ey[i][j+1][k] - Ey[i][j-1][k])/(2*dx) +
        (Ez[i][j][k+1] - Ez[i][j][k-1])/(2*dx);

        double expected = rho[i][j][k]/eps0;

        cout << "Node(" << i << "," << j << "," << k << ") -> "
             << "Div E: " << divE 
             << " | rho/eps0: " << expected << endl;
    }

    return 0;
}