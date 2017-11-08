#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;


void printMatrix(const vector<vector<double> > &m)
{
	cout << "Matriz diagonalizada" << endl;

	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m.size()+1; j++){
			if(j>0)
				cout << setw(15);

			cout << m.at(i).at(j);
		}
		cout << endl;
	}
}

void printSolution(const vector<double> &sol)
{
	cout << "Vetor solucao: ";

	for (int i = 0; i < sol.size(); i++)
	{
		if(i>0)
      cout << setw(15);

		cout << sol.at(i);
	}

	cout << endl;
}

void gauss()
{
  vector<vector<double> > matrix(3, vector<double>(4));
  int n = matrix.size();
  vector<double> solutions(n);
  const int OUT_PREC = 5;

  cout << fixed << setprecision(OUT_PREC);

  //Colocar valores, ultima coluna significa o vetor B
	matrix.at(0).at(0) = 2.0;
	matrix.at(0).at(1) = 2.0;
	matrix.at(0).at(2) = 2.0;
	matrix.at(1).at(0) = 1.0;
	matrix.at(1).at(1) = 2.0;
	matrix.at(1).at(2) = 4.0;
	matrix.at(2).at(0) = 2.0;
	matrix.at(2).at(1) = 1.0;
	matrix.at(2).at(2) = 2.0;
	matrix.at(0).at(3) = 2.0;
	matrix.at(1).at(3) = 7.0;
	matrix.at(2).at(3) = 0.0;


	for (int dg = 0; dg < n; dg++) {
		for (int col = dg + 1; col <= n; col++)
			matrix.at(dg).at(col) /= matrix.at(dg).at(dg);

		matrix.at(dg).at(dg) = 1;

		for (int lin = dg + 1; lin < n; lin++) {
			for (int col = dg + 1; col <= n; col++)
				matrix.at(lin).at(col) -= matrix.at(lin).at(dg)*matrix.at(dg).at(col);

			matrix.at(lin).at(dg) = 0;
		}
	}

	printMatrix(matrix);

	for (int dg = n-1; dg >= 0; dg--)
	{
		double s = 0;
		for (int col = dg+1; col < n; col++)
			s += matrix.at(dg).at(col)*solutions.at(col);

		solutions.at(dg)= matrix.at(dg).at(n) - s;
	}

	printSolution(solutions);
}




int main()
{
  gauss();

	return 0;
}
