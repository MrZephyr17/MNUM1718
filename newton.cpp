#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(double x)
{
	return x * x - 4;
}

double diffF(double x)
{
	return 2 * x;
}

double f1(double x)
{
	return (x - 3.7) + pow(cos((x + 1.2)), 3);
}

double diffF1(double x)
{
	return 1 - 3 * pow(cos(x + 1.2), 2) * sin(x + 1.2);
}

void newton(double f(double), double diff(double), double x, int numIt)
{
	for (int i = 0; i < numIt; ++i)
	{
		x -= f(x) / diffF(x);

		cout << "x = " << x << endl;
	}
}

int main()
{
	const int OUT_PREC = 5;
	cout << fixed << setprecision(OUT_PREC);

	newton(f1, diffF1, 3.8, 1);

	return 0;
}
