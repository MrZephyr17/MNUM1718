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
	return pow(x, 7) + 0.5 * x - 0.5;
}

void falsePosition(double f(double x), double a, double b, int numIt)
{
	double r = 0.656044;

	for (int i = 0; i < numIt; ++i)
	{
		if (f(a) * f(r) < 0)
			b = r;
		else
			a = r;

		r = (a * f(b) - b * f(a)) / (f(b) - f(a));

		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		cout << "r = " << r << endl;
	}
}

int main()
{
	int const OUT_PREC = 5;
	cout << fixed << setprecision(OUT_PREC);

	falsePosition(f1, 0.0, 0.8, 3);

	return 0;
}
