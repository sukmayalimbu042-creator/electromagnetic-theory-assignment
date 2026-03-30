#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    int i, j, n, ny;
    double x, y, xmin, xmax, ymin, ymax;
    double dx, dy, r, Bz;
    double mu0, pi, Jx;

    n = 100;
    ny = 50;

    pi = 3.1415926;
    mu0 = 4.0 * pi * 1.0e-7;

    xmin = -1.0;
    xmax =  1.0;
    dx = (xmax - xmin) / (n - 1);

    ymin = 0.1;
    ymax = 1.0;
    dy = (ymax - ymin) / (ny - 1);

    Jx = 1.0;

    ofstream file("biot1d.txt");

    for (j = 0; j < ny; j++)
    {
        y = ymin + j * dy;
        Bz = 0.0;

        for (i = 0; i < n; i++)
        {
            x = xmin + i * dx;

            r = sqrt(x*x + y*y);

            if (r < 1.0e-12) continue;

            Bz += (mu0 / (4.0 * pi)) * (Jx * y) / (pow(r, 3)) * dx;
        }

        cout << y << " " << Bz << endl;
        file << y << " " << Bz << endl;
    }

    file.close();

    return 0;
}