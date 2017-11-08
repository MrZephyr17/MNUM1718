#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//Funcoes e derivadas

double f1(double x, double y)
{
	return y*y - 2 * x - 5;
}

double f2(double x, double y)
{
	return x*x - y - 20;
}

double f1derx(double x, double y)
{
	return -2;
}

double f1dery(double x, double y)
{
	return 2 * y;
}

double f2derx(double x, double y)
{
	return 2*x;
}

double f2dery(double x, double y)
{
	return -1;
}

double h(double x, double y)
{
	return -(f1(x, y)*f2dery(x, y) - f2(x, y)*f1dery(x, y))/(f1derx(x,y)*f2dery(x,y)-f1dery(x,y)*f2derx(x,y));
}

double j(double x, double y)
{
	return -(f2(x, y)*f1derx(x, y) - f1(x, y)*f2derx(x, y)) / (f1derx(x, y)*f2dery(x, y) - f1dery(x, y)*f2derx(x, y));
}


void newton()
{
  double x=1.0, y=1.0; //guesses iniciais
  const double OUT_PREC = 5;
	double xAnt;

  cout << fixed << setprecision(OUT_PREC);

	for (int i = 0; i < 50; i++)
	{
		xAnt = x;

		x += h(x, y);
		y += j(xAnt, y);

		cout << "x: " << x << '\t' << "y: " << y << endl;

	}

  cout << "f1 result: " << f1(x, y) << endl;

  cout << "f2 result: " << f2(x, y) << endl;
}

int main()
{
  newton();

  return 0;
}
