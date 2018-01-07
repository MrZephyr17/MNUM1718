#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double delta1g(double g(double, double, double), double x, double y, double z, double h);
double delta2g(double f(double, double, double), double g(double, double, double), double x, double y, double z, double h);
double delta3g(double f(double, double, double), double g(double, double, double), double x, double y, double z, double h);

double f(double x, double y, double z)
{
    return 15.0 * pow(exp(1), (-0.1 / (y + 273))) * z - 0.1 * (y - 20);
}

double g(double x, double y, double z)
{
    return -(pow(exp(1), (-0.1 / (y + 273)))) * z;
}

double g1(double x, double y, double z)
{
    return 0.5 + x * x + x * z;
}

double f1(double x, double y, double z)
{
    return z;
}

double f2(double x, double y, double z)
{
    return 1 + x * x + x * z;
}

double euler_sist(double f(double, double, double), double g(double, double, double), double h, double x, double y, double z, int numIt)
{
    cout << "Euler method" << endl;

    for (int i = 0; i < numIt; i++)
    {
        double z_temp = z;
        z += h * g(x, y, z);
        y += h * f(x, y, z_temp);
        x += h;

        cout << "x: " << x << endl;
        cout << "y: " << y << endl;
        cout << "z: " << z << endl;
    }

    return z; //Return variable to test convergence and error
}

double euler_conv(double f(double, double, double), double g(double, double, double), double h, double x0, double y0, double z0, int numIt)
{
    double s = euler_sist(f, g, h, x0, y0, z0, numIt);
    double s1 = euler_sist(f, g, h / 2, x0, y0, z0, 2 * numIt);
    double s2 = euler_sist(f, g, h / 4, x0, y0, z0, 4 * numIt);

    return (s - s1) / (s2 - s1);
}

double euler_err(double f(double, double, double), double g(double, double, double), double h, double x0, double y0, double z0, int numIt)
{
    double s1 = euler_sist(f, g, h / 2, x0, y0, z0, 2 * numIt);
    double s2 = euler_sist(f, g, h / 4, x0, y0, z0, 4 * numIt);

    return (s2 - s1);
}

double delta1f(double f(double, double, double), double x, double y, double z, double h)
{
    return h * f(x, y, z);
}

double delta2f(double f(double, double, double), double g(double, double, double), double x, double y, double z, double h)
{
    return h * f(x + (h / 2), y + (delta1f(f, x, y, z, h) / 2), z + (delta1g(g, x, y, z, h) / 2));
}

double delta3f(double f(double, double, double), double g(double, double, double), double x, double y, double z, double h)
{
    return h * f(x + (h / 2), y + (delta2f(f, g, x, y, z, h) / 2), z + (delta2g(f, g, x, y, z, h) / 2));
}

double delta4f(double f(double, double, double), double g(double, double, double), double x, double y, double z, double h)
{
    return h * f(x + h, y + delta3f(f, g, x, y, z, h), z + delta3g(f, g, x, y, z, h));
}

double delta1g(double g(double, double, double), double x, double y, double z, double h)
{
    return h * g(x, y, z);
}

double delta2g(double f(double, double, double), double g(double, double, double), double x, double y, double z, double h)
{
    return h * g(x + (h / 2), y + (delta1f(f, x, y, z, h) / 2), z + (delta1g(g, x, y, z, h) / 2));
}

double delta3g(double f(double, double, double), double g(double, double, double), double x, double y, double z, double h)
{
    return h * g(x + (h / 2), y + (delta2f(f, g, x, y, z, h) / 2), z + (delta2g(f, g, x, y, z, h) / 2));
}

double delta4g(double f(double, double, double), double g(double, double, double), double x, double y, double z, double h)
{
    return h * g(x + h, y + delta3f(f, g, x, y, z, h), z + delta3g(f, g, x, y, z, h));
}

double rk4_sist(double f(double, double, double), double g(double, double, double), double h, double x, double y, double z, int numIt)
{
    cout << endl
         << "Runge-Kutta4 method" << endl;

    for (int i = 0; i < numIt; i++)
    {
        double z_temp = z;
        z += (delta1g(g, x, y, z, h) / 6) + (delta2g(f, g, x, y, z, h) / 3) + (delta3g(f, g, x, y, z, h) / 3) + (delta4g(f, g, x, y, z, h) / 6);
        y += (delta1f(f, x, y, z_temp, h) / 6) + (delta2f(f, g, x, y, z_temp, h) / 3) + (delta3f(f, g, x, y, z_temp, h) / 3) + (delta4f(f, g, x, y, z_temp, h) / 6);
        x += h;

        cout << "x: " << x << endl;
        cout << "y: " << y << endl;
        cout << "z: " << z << endl;
    }

    return z;
}

double rk4_conv(double f(double, double, double), double g(double, double, double), double h, double x0, double y0, double z0, int numIt)
{
    double s = rk4_sist(f, g, h, x0, y0, z0, numIt);
    double s1 = rk4_sist(f, g, h / 2, x0, y0, z0, 2 * numIt);
    double s2 = rk4_sist(f, g, h / 4, x0, y0, z0, 4 * numIt);

    return (s - s1) / (s2 - s1);
}

double rk4_err(double f(double, double, double), double g(double, double, double), double h, double x0, double y0, double z0, int numIt)
{
    double s1 = rk4_sist(f, g, h / 2, x0, y0, z0, 2 * numIt);
    double s2 = rk4_sist(f, g, h / 4, x0, y0, z0, 4 * numIt);

    return (s2 - s1);
}

int main()
{
    const int OUT_PREC = 5;
    cout << fixed << setprecision(OUT_PREC);

    //cout << "CONV: " << euler_conv(f,g,0.25,0.5,20.0,2.0,2);

    // cout << "ERR: " << euler_err(f,g,0.25,0.5,20.0,2.0,2);

    // rk4_sist(f,g,0.25,0.5,20.0,2.0,2);

    euler_sist(f1, f2, 0.5, 0.0, 1.0, 2.0, 2);

    rk4_sist(f1, f2, 0.5, 0.0, 1.0, 2.0, 2);

    return 0;
}