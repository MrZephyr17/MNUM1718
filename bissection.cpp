#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//Function
double f(double x)
{
  return x*x - 4;
}

void bissection()
{
  double a = 0, b = 5;
  double m;
  const double precision = 0.001;
  const int OUT_PREC = 5;
  int counter = 0;

  cout << fixed << setprecision(OUT_PREC);

  //Stopping criterium -> absolute precision
  while (!(abs(a - b)<precision))
  {
    m = (a + b) / 2.0;

    if (f(a)*f(m) >= 0)
      a = m;
    else
      b = m;

    cout << "|a - b| = " << abs(a - b) << endl;

    counter++;
  }

  cout << "a = " << a << endl;
  cout << "b = " << b << endl;

  cout << "Number of iterations: " << counter << endl;

  cout << "Aproximation of the root in the given interval (precision= " << precision << "): " << m << endl;

}

int main()
{
  bissection();

  return 0;
}
