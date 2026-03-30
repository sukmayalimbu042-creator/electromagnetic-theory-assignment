#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    int i, j, ix, iy, nx, ny;
    double x, y, xp, yp, dx, dy, r2, r, Bz;
    double xmin, xmax, ymin, ymax;
    double mu0, pi, Jx;

    nx = 80;
    ny = 80;

    pi = 3.1415926;
    mu0 = 4.0 * pi * 1.0e-7;

    xmin = -1.0; xmax = 1.0;
    ymin = -1.0; ymax = 1.0;

    dx = (xmax - xmin) / (nx - 1);
    dy = (ymax - ymin) / (ny - 1);

    Jx = 1.0;

    ofstream file("biot2d.txt");

    for (iy = 0; iy < ny; iy++)
    {
        y = ymin + iy * dy;

        for (ix = 0; ix < nx; ix++)
        {
            x = xmin + ix * dx;
            Bz = 0.0;

            for (i = 0; i < nx; i++)
            {
                for (j = 0; j < ny; j++)
                {
                    xp = xmin + i * dx;
                    yp = ymin + j * dy;

                    
                    r2 = (x - xp)*(x - xp) + (y - yp)*(y - yp);

                    if (r2 < 1.0e-6) continue;

                    r = sqrt(r2);

                    Bz += (mu0 / (4.0 * pi)) *
                          ((Jx * (y - yp)) / (r2 * r)) * dx * dy;
                }
            }

            cout << x << " " << y << " " << Bz << endl;
            file << x << " " << y << " " << Bz << endl;
        }

        file << endl; 
    }

    file.close();

    return 0;
}