#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//Function
double f(double x)
{
  return x*x - 4;
}

void falsePosition()
{
	double a = 0, b = 10;
	double r,prevR;
  int const OUT_PREC = 5;
	double const precision = 0.001;
	int counter = 0;

  cout << fixed << setprecision(OUT_PREC);

	do
	{
		prevR = (a*f(b) - b*f(a)) / (f(b) - f(a));

		if (f(a)*f(prevR) < 0)
			b = prevR;
		else
			a = prevR;

		cout << "|a - b| = " << abs(a - b) << endl;

		r = (a*f(b) - b*f(a)) / (f(b) - f(a));
		counter++;
	} while (abs(prevR - r) > precision);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	cout << "Number of iterations: " << counter << endl;

	cout << "Aproximation of the root in the given interval (precision= " << precision << "): " << r << endl;

}


int main()
{
  falsePosition();

  return 0;
}
