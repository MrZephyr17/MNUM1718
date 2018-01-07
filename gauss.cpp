#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void printMatrix(const vector<vector<double> > &m)
{
	cout << "Matriz" << endl;

	for (int i = 0; i < m.size(); i++)
	{
		for (int j = 0; j < m.at(i).size(); j++)
		{
			if (j > 0)
				cout << setw(15);

			cout << m.at(i).at(j);
		}
		cout << endl;
	}

	cout << endl;
}

void printVector(const vector<double> &sol)
{
	cout << "Vetor: ";

	for (int i = 0; i < sol.size(); i++)
	{
		if (i > 0)
			cout << setw(15);

		cout << sol.at(i);
	}

	cout << endl;
}

vector<double> gauss(const vector<vector<double> > &a, const vector<double> &b)
{
	cout << "Metodo de Gauss" << endl
		 << endl;

	vector<vector<double> > a1(a.size(), vector<double>(a.size() + 1));
	int n = a.size();
	vector<double> solutions(n);

	for (int i = 0; i < a1.size(); i++)
		for (int j = 0; j < a1.at(i).size(); j++)
		{

			if (j >= a1.size())
				a1.at(i).at(j) = b.at(i);
			else
				a1.at(i).at(j) = a.at(i).at(j);
		}

	for (int dg = 0; dg < n; dg++)
	{
		for (int col = dg + 1; col <= n; col++)
			a1.at(dg).at(col) /= a1.at(dg).at(dg);

		a1.at(dg).at(dg) = 1;

		for (int lin = dg + 1; lin < n; lin++)
		{
			for (int col1 = dg + 1; col1 <= n; col1++)
				a1.at(lin).at(col1) -= a1.at(lin).at(dg) * a1.at(dg).at(col1);

			a1.at(lin).at(dg) = 0;
		}
	}

	printMatrix(a1);

	for (int dg = n - 1; dg >= 0; dg--)
	{
		double s = 0;
		for (int col = dg + 1; col < n; col++)
			s += a1.at(dg).at(col) * solutions.at(col);

		solutions.at(dg) = a1.at(dg).at(n) - s;
	}
	return solutions;
}

int main()
{
	vector<vector<double> > matrix(3, vector<double>(3));
	vector<double> b(matrix.size());
	vector<double> solutions(matrix.size());

	const int OUT_PREC = 5;

	cout << fixed << setprecision(OUT_PREC);

	//Colocar valores, ultima coluna significa o vetor B
	{
		matrix.at(0).at(0) = 1.0;
		matrix.at(0).at(1) = 0.5;
		matrix.at(0).at(2) = (double)1 / 3;
		matrix.at(1).at(0) = 0.5;
		matrix.at(1).at(1) = (double)1 / 3;
		matrix.at(1).at(2) = 0.25;
		matrix.at(2).at(0) = (double)1 / 3;
		matrix.at(2).at(1) = 0.25;
		matrix.at(2).at(2) = 0.2;
		b.at(0) = -1.0;
		b.at(1) = 1.0;
		b.at(2) = 1.0;
	}

	solutions = gauss(matrix, b);
	printVector(solutions);

	return 0;
}
