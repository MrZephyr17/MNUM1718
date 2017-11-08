#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//Funcao
/*double f(double x)
{
	return x - 2 * log(x) - 5;
}

double d_f(double x)
{
	return 1 - 2 / x;
}*/


//Formulacao de picardPeano
double g(double x)
{
	return 2 * log(x) + 5;
}

double d_g(double x)
{
	return 2 / x;
}

void picardPeano()
{
  double guess = 9; //guess inicial
	double next_guess = g(guess);
  double const precision = pow(10, -4);
	int i = 1;

	while ((abs(next_guess - guess)) > precision)
	{
		guess = next_guess;
		next_guess = g(guess);

		i++;
	}
	cout << "Numero de iteracoes: " << i << endl;
	cout << "x = " << next_guess << endl;

}



int main()
{
  picardPeano();

  return 0;
}
