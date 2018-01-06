#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(double x, double y)
{
	return 3 * x * x - x * y + 11 * y + y * y - 8 * x;
}

double fderx(double x, double y)
{
	return 6 * x - y - 8;
}

double fdery(double x, double y)
{
	return -x + 11 + 2 * y;
}

void gradient(double f(double, double), double x, double y, double h, int numIt)
{
	double xn, yn;

	cout << "f(x0, y0): " << f(x, y) << endl;

	for (int i = 0; i < numIt; ++i)
	{
		xn = x - h * fderx(x, y);
		yn = y - h * fdery(x, y);

		if (!(f(xn, yn) < f(x, y)))
			h /= 2;
		else
		{
			x = xn;
			y = yn;
			h *= 2;
		}

		cout << "fderx(xn,yn): " << fderx(xn, yn) << endl;
		cout << "fdery(xn, yn): " << fdery(xn, yn) << endl;
		cout << "xn: " << xn << endl;
		cout << "yn: " << yn << endl;
		cout << "f(xn, yn): " << f(xn, yn) << endl;
	}
}

int main()
{
	const int OUT_PREC = 5;
	cout << fixed << setprecision(OUT_PREC);

	gradient(f, 2.0, 2.0, 0.5, 1);

	return 0;
}