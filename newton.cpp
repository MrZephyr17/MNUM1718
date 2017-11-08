#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(double x)
{
	return x*x - 4;
}

double diffF(double x)
{
	return 2 * x;
}

void newton()
{
	double x1=3, x2;
  const double prec=0.001;
  const int OUT_PREC = 5;
  int counter=0;

  cout << fixed << setprecision(OUT_PREC);

	do
	{
		if (counter > 0)
			x1 = x2;

		x2 = x1 - f(x1) / diffF(x1);
		counter++;

	} while (abs(x2-x1) > prec);

	cout << "Numero iteracoes: " << counter << endl;
	cout << "x = " << x2 << endl;
}


int main()
{
  newton();

  return 0;
}
