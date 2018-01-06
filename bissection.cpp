#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//Function
double f(double x)
{
  return x * x - 4;
}

double f1(double x)
{
  return x * x * x - 10 * sin(x) + 2.8;
}

void bissection(double f(double), double a, double b, int numIt)
{
  double m;
  int counter = 0;

  for (int i = 0; i < numIt; ++i)
  {
    m = (a + b) / 2.0;

    if (f(a) * f(m) >= 0)
      a = m;
    else
      b = m;

    cout << "|a - b| = " << abs(a - b) << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "m = " << m << endl;

    counter++;
  }
}

int main()
{
  const int OUT_PREC = 5;

  cout << fixed << setprecision(OUT_PREC);

  bissection(f1, 1.5, 4.2, 3);

  return 0;
}
