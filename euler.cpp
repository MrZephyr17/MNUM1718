#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double g(double t, double T)
{
  return -0.25 * (T - 64);
}

double f(double t, double T)
{
  return -0.25 * (T - 45);
}

double f1(double u, double v)
{
  return u * (u / 2 + 1) * v * v * v + (u + (double)5 / 2) * v * v;
}

double euler(double f(double, double), double h, double x, double y, int numIt)
{
  for (int i = 0; i < numIt; i++)
  {
    y += h * f(x, y);
    x += h;

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
  }

  return y;
}

double euler_conv(double f(double, double), double h, double x0, double y0, int numIt)
{
  double s = euler(f, h, x0, y0, numIt);
  double s1 = euler(f, h / 2, x0, y0, numIt * 2);
  double s2 = euler(f, h / 4, x0, y0, numIt * 4);

  return (s1 - s) / (s2 - s1);
}

double euler_err(double f(double, double), double h, double x0, double y0, int numIt)
{
  double s1 = euler(f, h / 2, x0, y0, numIt * 2);
  double s2 = euler(f, h / 4, x0, y0, numIt * 4);

  return (s2 - s1);
}

int main()
{
  const int OUT_PREC = 5;

  cout << fixed << setprecision(OUT_PREC);

  cout << "Euler method" << endl
       << endl
       << "Result: " << euler(f1, 0.08, 1.0, 0.1, 10) << endl;

  cout << "Convergence: " << euler_conv(f, 0.4, 1.0, 23.0, 2) << endl;

  cout << "Error: " << euler_err(f, 0.4, 1.0, 23.0, 2) << endl;

  return 0;
}