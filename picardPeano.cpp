#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//Funcao
double f(double x)
{
	return x - 2 * log(x) - 5;
}

//Formulacao de picardPeano
double g(double x)
{
	return 2 * log(x) + 5;
}

double g1(double x)
{
	return pow(4 * x * x * x - x + 1, 0.25);
}

void picardPeano(double g(double), double guess, int numIt)
{
	for (int i = 0; i < numIt; ++i)
	{
		guess = g(guess);

		cout << "x = " << guess << endl;
	}
}

int main()
{
	const int OUT_PREC = 5;
	cout << fixed << setprecision(OUT_PREC);

	picardPeano(g1, 4.0, 2);

	return 0;
}
