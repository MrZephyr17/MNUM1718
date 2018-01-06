#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double g(double x, double p)
{
	return pow(x, p);
}

double f(double x)
{
	return sqrt(1 + 1.5 * pow(exp(1), 1.5 * x) * 1.5 * pow(exp(1), 1.5 * x));
}

double f1(double x)
{
	if (x == 0.0)
		return 1.02;
	else if (x == 0.2)
		return 1.21;
	else if (x == 0.4)
		return 1.45;
	else if (x == 0.6)
		return 0.89;
	else if (x == 0.8)
		return 0.62;
	else if (x == 1.0)
		return 1.46;
	else if (x == 1.2)
		return 0.74;
	else if (x == 1.4)
		return 0.36;
	else
		return 0.87;
}

double trapezees(double h, double f(double), double upperLim, double lowerLim)
{
	double numSlices = (upperLim - lowerLim) / h;
	double sum = f(lowerLim);
	double x = lowerLim + h;

	for (int i = 1; i < numSlices; i++)
	{
		sum += 2 * f(x);
		x += h;
	}

	return (sum + f(upperLim)) * h / 2;
}

double simpson(double h, double f(double), double upperLim, double lowerLim)
{
	double numSlices = (upperLim - lowerLim) / h;
	double sum = f(lowerLim);
	double x = lowerLim + h;

	for (int i = 1; i < numSlices; i++)
	{
		if (i % 2 == 0)
			sum += 2 * f(x);
		else
			sum += 4 * f(x);

		x += h;
	}

	return (sum + f(upperLim)) * h / 3;
}

double trapezeesConv(double h, double f(double), double upperLim, double lowerLim)
{
	double s = trapezees(h, f, upperLim, lowerLim);
	double s1 = trapezees(h / 2, f, upperLim, lowerLim);
	double s2 = trapezees(h / 4, f, upperLim, lowerLim);

	return (s1 - s) / (s2 - s1);
}

double trapezeesErr(double h, double f(double), double upperLim, double lowerLim)
{
	double s1 = trapezees(h / 2, f, upperLim, lowerLim);
	double s2 = trapezees(h / 4, f, upperLim, lowerLim);

	return (s2 - s1) / 3;
}

double simpsonErr(double h, double f(double), double upperLim, double lowerLim)
{
	double s1 = simpson(h / 2, f, upperLim, lowerLim);
	double s2 = simpson(h / 4, f, upperLim, lowerLim);

	return (s2 - s1) / 15;
}

double simpsonConv(double h, double f(double), double upperLim, double lowerLim)
{
	double s = simpson(h, f, upperLim, lowerLim);
	double s1 = simpson(h / 2, f, upperLim, lowerLim);
	double s2 = simpson(h / 4, f, upperLim, lowerLim);

	return (s1 - s) / (s2 - s1);
}

int main()
{
	const int OUT_PREC = 5;
	cout << fixed << setprecision(OUT_PREC);

	cout << "Trapezees" << endl;

	cout << trapezees(0.25, f, 1.0, 0.0) << endl;

	cout << "Convergence" << endl;

	cout << trapezeesConv(0.25, f, 1.0, 0.0) << endl;

	cout << "Error" << endl;

	cout << trapezeesErr(0.25, f, 1.0, 0.0) << endl;

	cout << endl
		 << "Simpsons" << endl;

	cout << simpson(0.25, f, 1.0, 0.0) << endl;

	cout << "Convergence" << endl;

	cout << simpsonConv(0.25, f, 1.0, 0.0) << endl;

	cout << "Error" << endl;

	cout << simpsonErr(0.25, f, 1.0, 0.0) << endl;

	return 0;
}
