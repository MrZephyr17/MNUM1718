#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

double fx(double cw, double cx, double cy, double cz, double w, double y, double z, double s)
{
	return (s - cy*y - cz*z - cw*w) / cx;
}

double fy(double cw, double cx, double cy, double cz, double w, double x, double z, double s)
{
	return (s - cx*x - cz*z - cw*w) / cy;
}

double fz(double cw, double cx, double cy, double cz, double w, double x, double y, double s)
{
	return (s - cx*x - cy*y - cw*w) / cz;
}

double fw(double cw, double cx, double cy, double cz, double x, double y, double z, double s)
{
	return (s - cx*x - cy*y - cz*z) / cw;
}


vector<double> gaussJacobi(const vector<vector<double> > &a, const vector<double> &b)
{
	double x = 0.25, y = 0.25, z = 0.25, w = 0.25;
	double xAnt, yAnt, zAnt;
	double cw1, cx1, cy1, cz1, cw2, cx2, cy2, cz2, cx3, cy3, cz3, cw3, cx4, cy4, cz4, cw4, s1, s2, s3, s4;
	vector<double> sol(a.size());

	s1 = b[0];
	s2 = b[1];
	s3 = b[2];
	s4 = b[3];
	cx1 = a[0][0];
	cy1 = a[0][1];
	cz1 = a[0][2];
	cw1 = a[0][3];
	cx2 = a[1][0];
	cy2 = a[1][1];
	cz2 = a[1][2];
	cw2 = a[1][3];
	cx3 = a[2][0];
	cy3 = a[2][1];
	cz3 = a[2][2];
	cw3 = a[2][3];
	cx4 = a[3][0];
	cy4 = a[3][1];
	cz4 = a[3][2];
	cw4 = a[3][3];

	for(int i=0;i<2;i++){
		xAnt = x;
		x = fx(cw1, cx1, cy1, cz1, w, y, z, s1);
		yAnt = y;
		y = fy(cw2, cx2, cy2, cz2, w, xAnt, z, s2);
		zAnt = z;
		z = fz(cw3, cx3, cy3, cz3, w, xAnt, yAnt, s3);
		w = fw(cw4, cx4, cy4, cz4, xAnt, yAnt, zAnt, s4);

		cout << "x: " << x << "\t y:" << y << "\t z: " << z << "\t w:" << w << endl;
	}

	sol.at(0) = x;
	sol.at(1) = y;
	sol.at(2) = z;
	sol.at(3) = w;

	return sol;
}


vector<double> gaussSeidel(const vector<vector<double> > &a, const vector<double> &b)
{
	double x = 0.25, y = 0.25, z = 0.25, w = 0.25;
	double cw1, cx1, cy1, cz1, cw2, cx2, cy2, cz2, cx3, cy3, cz3, cw3, cx4, cy4, cz4, cw4, s1, s2, s3, s4;
	vector<double> sol(a.size());

	s1 = b[0];
	s2 = b[1];
	s3 = b[2];
	s4 = b[3];
	cx1 = a[0][0];
	cy1 = a[0][1];
	cz1 = a[0][2];
	cw1 = a[0][3];
	cx2 = a[1][0];
	cy2 = a[1][1];
	cz2 = a[1][2];
	cw2 = a[1][3];
	cx3 = a[2][0];
	cy3 = a[2][1];
	cz3 = a[2][2];
	cw3 = a[2][3];
	cx4 = a[3][0];
	cy4 = a[3][1];
	cz4 = a[3][2];
	cw4 = a[3][3];

	for (int i = 0; i < 10; i++) {
		x = fx(cw1, cx1, cy1, cz1, w, y, z, s1);
		y = fy(cw2, cx2, cy2, cz2, w, x, z, s2);
		z = fz(cw3, cx3, cy3, cz3, w, x, y, s3);
		w = fw(cw4, cx4, cy4, cz4, x, y, z, s4);

		cout << "x: " << x << "\t y:" << y << "\t z: " << z << "\t w:" << w << endl;
	}

	sol.at(0) = x;
	sol.at(1) = y;
	sol.at(2) = z;
	sol.at(3) = w;

	return sol;
}

int main()
{
	vector<vector<double> > matrix(4, vector<double>(4));
	vector<double> b(matrix.size());
	vector<double> solutions(matrix.size());
	const int OUT_PREC = 5;

	cout << fixed << setprecision(OUT_PREC);

	//Colocar valores, ultima coluna significa o vetor B
	//dependendo da situacao, pode ser necessaria pivotagem
	matrix.at(0).at(0) = 4.5;
  matrix.at(0).at(1) = -1.0;
	matrix.at(0).at(2) = -1.0;
	matrix.at(0).at(3) = 1.0;
	b.at(0) = 1.0;
	matrix.at(1).at(0) = -1.0;
	matrix.at(1).at(1) = 4.5;
	matrix.at(1).at(2) = 1.0;
	matrix.at(1).at(3) = -1.0;
	b.at(1)= -1.0;
	matrix.at(2).at(0) = -1.0;
	matrix.at(2).at(1) = 2.0;
	matrix.at(2).at(2) = 4.5;
  matrix.at(2).at(3) = -1.0;
	b.at(2) = -1.0;
	matrix.at(3).at(0) = 2.0;
	matrix.at(3).at(1) = -1.0;
	matrix.at(3).at(2) = -1.0;
	matrix.at(3).at(3) = 4.5;
	b.at(3) = 0.0;

	//solutions = gaussSeidel(matrix, b);
	solutions = gaussJacobi(matrix, b);

	return 0;
}
