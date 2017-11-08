#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//Funcoes

double f1(double x, double y)
{
	return y*y - 2 * x - 5;
}

double f2(double x, double y)
{
	return x*x - y - 20;
}


//Formulacoes de picardPeano
double pp1x(double x, double y)
{
	return (y*y - 5) / 2;
}

double pp1y(double x, double y)
{
	return x*x - 20;
}


double pp2x(double x, double y)
{
	return (y+20)/x;
}

double pp2y(double &x, double &y)
{
	return (2*x+5)/y;
}

double pp3y(double &x, double &y)
{
	return sqrt(2 * x + 5);
}

double pp3x(double &x, double &y)
{
	return sqrt(y + 20);
}


void sistPicardPeano()
{
	double xAnt, x=1.0, y=1.0;

	for (int i = 0; i < 50; i++)
	{
		xAnt = x;

		x = pp3x(x, y);
		y = pp3y(xAnt, y);

		cout << "x: " << x << '\t' << "y: " << y << endl;
	}

  cout << "f1 result: " << f1(x, y) << endl;

  cout << "f2 result: " << f2(x, y) << endl;
}


int main()
{
  sistPicardPeano();

  return 0;
}
