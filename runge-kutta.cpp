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

double f1(double x, double y)
{
  return x * x + y * y;
}

double f2(double t, double x)
{
  return sin(2.0 * x) + sin(2.0 * t);
}

double runge_kutta2(double f(double, double), double h, double x, double y, int numIt)
{
  for (int i = 0; i < numIt; i++)
  {
    y += h * f(x + h / 2, y + (h / 2) * f(x, y));
    x += h;

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
  }

  return y;
}

double runge_kutta4(double f(double, double), double h, double x, double y, int numIt)
{
  double delta1, delta2, delta3, delta4;

  for (int i = 0; i < numIt; i++)
  {
    delta1 = h * f(x, y);
    delta2 = h * f(x + h / 2, y + delta1 / 2);
    delta3 = h * f(x + h / 2, y + delta2 / 2);
    delta4 = h * f(x + h, y + delta3);

    y += delta1 / 6 + delta2 / 3 + delta3 / 3 + delta4 / 6;
    x += h;

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
  }

  return y;
}

double runge_kutta2_conv(double f(double, double), double h, double x0, double y0, int numIt)
{
  double s = runge_kutta2(f, h, x0, y0, numIt);
  double s1 = runge_kutta2(f, h / 2, x0, y0, 2 * numIt);
  double s2 = runge_kutta2(f, h / 4, x0, y0, 4 * numIt);

  return (s1 - s) / (s2 - s1);
}

double runge_kutta2_err(double f(double, double), double h, double x0, double y0, int numIt)
{
  double s1 = runge_kutta2(f, h / 2, x0, y0, 2 * numIt);
  double s2 = runge_kutta2(f, h / 4, x0, y0, 4 * numIt);

  return (s2 - s1) / 3;
}

double runge_kutta4_conv(double f(double, double), double h, double x0, double y0, int numIt)
{
  double s = runge_kutta4(f, h, x0, y0, numIt);
  double s1 = runge_kutta4(f, h / 2, x0, y0, 2 * numIt);
  double s2 = runge_kutta4(f, h / 4, x0, y0, 4 * numIt);

  return (s1 - s) / (s2 - s1);
}

double runge_kutta4_err(double f(double, double), double h, double x0, double y0, int numIt)
{
  double s1 = runge_kutta4(f, h / 2, x0, y0, 2 * numIt);
  double s2 = runge_kutta4(f, h / 4, x0, y0, 4 * numIt);

  return (s2 - s1) / 15;
}

int main()
{
  const int OUT_PREC = 5;

  cout << fixed << setprecision(OUT_PREC);

  cout << "Runge-Kutta2 method" << endl
       << endl
       << "Result: " << runge_kutta2(g, 0.5, 4.0, 0.0, 2) << endl;

  cout << "Convergence: " << runge_kutta2_conv(g, 0.5, 4.0, 0.0, 2) << endl;

  cout << "Error: " << runge_kutta2_err(g, 0.5, 4.0, 0.0, 2) << endl;

  cout << endl
       << "Runge-Kutta4 method" << endl
       << endl
       << "Result: " << runge_kutta4(f2, 0.125, 1.0, 1.0, 4) << endl;

  cout << "Convergence: " << runge_kutta4_conv(f2, 0.125, 1.0, 1.0, 4) << endl;

  cout << "Error: " << runge_kutta4_err(f2, 0.125, 1.0, 1.0, 4) << endl;
}
