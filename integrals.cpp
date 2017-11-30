#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double g(double x, double p)
{
	return pow(x,p);
}


double trapezees(int numSlices, double f(double, double), double p,double upperLim, double lowerLim) {
	double h = (upperLim - lowerLim) / numSlices;
	double sum = f(lowerLim,p);
	double x = lowerLim+h;

	for (int i = 1; i < numSlices; i++) {

		sum += 2 * f(x,p);

		x += h;

	}

	return (sum+f(upperLim,p))*h / 2;
}

double simpson(int numSlices, double f(double,double), double p, double upperLim, double lowerLim) {
	double h = (upperLim - lowerLim) / numSlices;
	double sum = f(lowerLim, p);
	double x = lowerLim+h;

	for (int i = 1; i < numSlices; i++) {

		if (i % 2 == 0)
			sum += 2 * f(x, p);
		else
			sum += 4 * f(x, p);

		x += h;

	}

	return (sum+f(upperLim,p))*h / 3;
}


int main()
{
	vector<double> sol = { 0.5,0.33,0.25,0.20 };

	cout << fixed << setprecision(4);

	cout << "Trapezees" << endl;

	for (int i = 1; i <= 4; i++) {
		cout << i << setw(10) << sol.at(i - 1) << setw(10) << sol.at(i - 1) - trapezees(2,g, i, 1, 0) << setw(10) << sol.at(i - 1) - trapezees(4,g, i, 1, 0) << setw(10) << sol.at(i - 1) - trapezees(8,g, i, 1, 0) << setw(10) << sol.at(i - 1) - trapezees(16,g, i, 1, 0) << endl;
	}

	cout <<  endl << "Simpsons" << endl;

	for (int i = 1; i <= 4; i++) {
		cout <<  i << setw(10) << sol.at(i - 1) << setw(10) << sol.at(i - 1) - simpson(2,g, i, 1, 0) << setw(10) << sol.at(i - 1) - simpson(4,g, i, 1, 0) << setw(10) << sol.at(i - 1) - simpson(8,g, i, 1, 0) << setw(10) << sol.at(i - 1) - simpson(16,g, i, 1, 0) << endl;
	}
	return 0;
}