#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<double> multiplyMatrixVec(const vector<vector<double> > &m, const vector<double> &v)
{
	vector<double> res(m.size());

	for(int i=0;i<res.size();i++)
		res.at(i)=(m.at(i).at(0)*v.at(0)+m.at(i).at(1)*v.at(1)+m.at(i).at(2)*v.at(2));

		return res;
}

vector<double> diffVec(const vector<double> &v1, const vector<double> &v2)
{
	vector<double> res(v1.size());

	for(int i=0;i<res.size();i++)
		res.at(i)=v1.at(i)-v2.at(i);

	return res;
}

void printMatrix(const vector<vector<double> > &m)
{
	cout << "Matriz" << endl;

	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m.at(i).size(); j++) {
			if (j>0)
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
		if (i>0)
			cout << setw(15);

		cout << sol.at(i);
	}

	cout << endl;
}

vector<double> gauss(const vector<vector<double> > &a, const vector<double> &b)
{

	cout << "Metodo de Gauss" << endl << endl;


	vector<vector<double> > a1(a.size(),vector<double>(a.size()+1));
	int n = a.size();
	vector<double> solutions(n);

	for(int i=0;i<a1.size();i++)
		for(int j=0;j<a1.at(i).size();j++){

			if(j>=a1.size())
					a1.at(i).at(j)=b.at(i);
			else
				a1.at(i).at(j)=a.at(i).at(j);
		}

		for (int dg = 0; dg < n; dg++) {
		for (int col = dg + 1; col <= n; col++)
			a1.at(dg).at(col) /= a1.at(dg).at(dg);

		a1.at(dg).at(dg) = 1;

		for (int lin = dg + 1; lin < n; lin++) {
			for (int col1 = dg + 1; col1 <= n; col1++)
				a1.at(lin).at(col1) -= a1.at(lin).at(dg)*a1.at(dg).at(col1);

			a1.at(lin).at(dg) = 0;
		}
	}

	printMatrix(a1);

	for (int dg = n-1; dg >= 0; dg--)
	{
		double s = 0;
		for (int col = dg+1; col < n; col++)
			s += a1.at(dg).at(col)*solutions.at(col);

		solutions.at(dg)= a1.at(dg).at(n) - s;
	}
		return solutions;
}

vector<double> externa(const vector<vector<double> > &a, const vector<double> &b)
{
	double da=0.1, db=0.2;

	cout << "Estabilidade externa" << endl << endl;


	vector<vector<double> > DA(a.size(),vector<double>(a.size()));
	vector<double> DB(b.size());
	vector<double> solutions = gauss(a,b);

	for(int i=0;i<DA.size();i++)
		for(int j=0;j<DA.at(i).size();j++)
			DA.at(i).at(j)=da;

	for(int i=0;i<DB.size();i++)
		DB.at(i)=db-multiplyMatrixVec(DA,solutions).at(i);

		vector<double> res = gauss(a,DB);

		printVector(res);

		return res;

}

vector<double> interna(const vector<vector<double> > &a, const vector<double> &b)
{
	cout << "Estabilidade interna" << endl << endl;


	vector<double> solutions = gauss(a,b);
	vector<double> residuos = diffVec(b,multiplyMatrixVec(a,solutions));
	vector<double> res;

	res=gauss(a,residuos);

	printVector(res);

	return res;
}









int main()
{
	vector<vector<double> > matrix(3, vector<double>(3));
	vector<double> b(matrix.size());
	vector<double> solutions(matrix.size());
	vector<double> residuos;
	vector<double> ext;
	const int OUT_PREC = 5;

	cout << fixed << setprecision(OUT_PREC);

	//Colocar valores, ultima coluna significa o vetor B
	matrix.at(0).at(0) = 1.005;
	matrix.at(0).at(1) = 1.005;
	matrix.at(0).at(2) = 1.005;
	matrix.at(1).at(0) = 0.999;
	matrix.at(1).at(1) = 1.004;
	matrix.at(1).at(2) = 1.005;
	matrix.at(2).at(0) = 1.001;
	matrix.at(2).at(1) = 1.003;
	matrix.at(2).at(2) = 1.005;
	b.at(0) = 111.555;
	b.at(1) = 111.539;
	b.at(2) = 111.531;

	//solutions = gauss(matrix,b);
	//residuos = interna(matrix,b);
	ext=externa(matrix,b);


	return 0;
}
