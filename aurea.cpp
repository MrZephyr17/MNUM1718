#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(double x)
{
	return (2 * x + 1) * (2 * x + 1) - 5 * cos(10 * x);
}

double f1(double x)
{
	return x + pow(x - 2, 2) / (sin(x) + 4);
}

void aurea(double f(double), double x1, double x2, int numIt)
{
	double x3, x4;
	double B = (sqrt(5) - 1) / 2;
	double A = B * B;

	x3 = -0.045080; //x1 + A * (x2 - x1);
	x4 = 0.545085;  //x1 + B * (x2 - x1);

	for (int i = 0; i < numIt; ++i)
	{
		if (f(x3) < f(x4))
		{
			x2 = x4;
			x4 = x3;
			x3 = x1 + A * (x2 - x1);
		}
		else if (f(x4) < f(x3))
		{
			x1 = x3;
			x3 = x4;
			x4 = x1 + B * (x2 - x1);
		}

		{
			cout << "x1: " << x1 << endl;
			cout << "x2: " << x2 << endl;
			cout << "x3: " << x3 << endl;
			cout << "x4: " << x4 << endl;
			cout << "f(x1): " << f(x1) << endl;
			cout << "f(x2): " << f(x2) << endl;
			cout << "f(x3): " << f(x3) << endl;
			cout << "f(x4): " << f(x4) << endl;
		}
	}
}

int main()
{
	const int OUT_PREC = 5;

	cout << fixed << setprecision(OUT_PREC);

	aurea(f1, -1.0, 1.5, 2);

	return 0;
}
