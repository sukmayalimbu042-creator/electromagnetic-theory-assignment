#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{  
    int i, j, k, ix, iy, iz, nx, ny, nz;
    double x, y, z, xp, yp, zp;
    double dx, dy, dz, r2, r;
    double Bx, By, Bz;
    double xmin, xmax, ymin, ymax, zmin, zmax;
    double mu0, pi, Jx;

    nx = 20;
    ny = 20;
    nz = 20;

    pi = 3.1415926;
    mu0 = 4.0 * pi * 1.0e-7;

    xmin = -1.0; xmax = 1.0;
    ymin = -1.0; ymax = 1.0;
    zmin = -1.0; zmax = 1.0;

    dx = (xmax - xmin) / (nx - 1);
    dy = (ymax - ymin) / (ny - 1);
    dz = (zmax - zmin) / (nz - 1);

    Jx = 1.0; 

    ofstream file("biot3d.txt");

    for (iz = 0; iz < nz; iz++)
    {
        z = zmin + iz * dz;

        for (iy = 0; iy < ny; iy++)
        {
            y = ymin + iy * dy;

            for (ix = 0; ix < nx; ix++)
            {
                x = xmin + ix * dx;

                Bx = 0.0;
                By = 0.0;
                Bz = 0.0;

                for (k = 0; k < nz; k++)
                {
                    for (j = 0; j < ny; j++)
                    {
                        for (i = 0; i < nx; i++)
                        {
                            xp = xmin + i * dx;
                            yp = ymin + j * dy;
                            zp = zmin + k * dz;

                            double rx = x - xp;
                            double ry = y - yp;
                            double rz = z - zp;

                            r2 = rx*rx + ry*ry + rz*rz;

                            if (r2 < 1.0e-6) continue;

                            r = sqrt(r2);

                            double factor = (mu0 / (4.0 * pi)) / (r2 * r);

                            // J = (Jx, 0, 0)
                            // J × r = (0, -Jx*rz, Jx*ry)

                            Bx += 0.0;
                            By += (-Jx * rz) * factor * dx * dy * dz;
                            Bz += ( Jx * ry) * factor * dx * dy * dz;
                        }
                    }
                }

                cout << x << " " << y << " " << z << " "
                     << Bx << " " << By << " " << Bz << endl;

                file << x << " " << y << " " << z << " "
                     << Bx << " " << By << " " << Bz << endl;
            }
        }

        file << endl;
    }

    file.close();

    return 0;
}