#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x, double y)
{
    return x * x + 4 * y;
}

double f1(double x, double y)
{
    if (x == 0 && y == 0)
        return 1.1;
    else if (x == 0 && y == 0.9)
        return 2.1;
    else if (x == 0 && y == 1.8)
        return 6.3;
    else if (x == 0.9 && y == 0)
        return 1.4;
    else if (x == 0.9 && y == 0.9)
        return 4.9;
    else if (x == 0.9 && y == 1.8)
        return 1.5;
    else if (x == 1.8 && y == 0)
        return 2.6;
    else if (x == 1.8 && y == 0.9)
        return 2.2;
    else
        return 1.2;
}

double simpsons_cub(double f(double, double), double A, double a, double B, double b)
{
    double hx = (A - a) / 2.0;
    double hy = (B - b) / 2.0;

    double x0 = a;
    double y0 = b;
    double x2 = A;
    double y2 = B;
    double x1 = a + hx;
    double y1 = b + hy;

    return (hx * hy / 9) * (f(x0, y0) + f(x0, y2) + f(x2, y0) + f(x2, y2) + 4 * (f(x1, y0) + f(x0, y1) + f(x2, y1) + f(x1, y2)) + 16 * f(x1, y1));
}

int main()
{
    const int OUT_PREC = 5;
    cout << fixed << setprecision(OUT_PREC);

    cout << simpsons_cub(f1, 1.8, 0, 1.8, 0) << endl;

    return 0;
}