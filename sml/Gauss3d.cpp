#include <iostream>
using namespace std;

const int N = 5;
double rho[N][N][N];
double Ex[N][N][N], Ey[N][N][N], Ez[N][N][N];

int main()
{
    double eps0 = 8.85e-12;
    double dx = 1.0;

    for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
    for(int k=0;k<N;k++)
        rho[i][j][k] = 1.0;

    for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
    for(int k=0;k<N;k++)
    {
        Ex[i][j][k] = 0;
        Ey[i][j][k] = 0;
        Ez[i][j][k] = 0;
    }

    for(int i=1;i<N-1;i++)
    for(int j=1;j<N-1;j++)
    for(int k=1;k<N-1;k++)
    {
        double divE =
        (Ex[i+1][j][k] - Ex[i-1][j][k])/(2*dx) +
        (Ey[i][j+1][k] - Ey[i][j-1][k])/(2*dx) +
        (Ez[i][j][k+1] - Ez[i][j][k-1])/(2*dx);

        cout << "Div E = " << divE
             << " , rho/eps0 = " << rho[i][j][k]/eps0 << endl;
    }

    return 0;
}