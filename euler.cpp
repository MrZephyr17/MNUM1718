#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double g(double t, double T){
  return -0.25*(T-64);
}

double f(double t, double T){
  return -0.25*(T-45);
}

double euler(double f(double,double), double h, double x0, double y0){

  double x = x0;
  double y = y0;

  for(int i=0;i<2;i++){
    y+=h*f(x,y);
    x+=h;
  }

  return y;
}

double euler_conv(double f(double,double), double h, double x0, double y0){

  double s = euler(f,h,x0,y0);
  double s1 = euler(f,h/2,x0,y0);
  double s2 = euler(f,h/4,x0,y0);

  return (s1-s)/(s2-s1);

}

double euler_err(double f(double,double), double h, double x0, double y0){

  double s1 = euler(f,h/2,x0,y0);
  double s2 = euler(f,h/4,x0,y0);

  return (s2-s1);

}
 
int main(){

  const int OUT_PREC = 5;

  cout << fixed << setprecision(OUT_PREC);

  cout << "Euler method" << endl << endl << "Result: " <<  euler(f,0.4,1.0,23.0) << endl;

  cout << "Convergence: " << euler_conv(f,0.4,1.0,23.0) << endl;

  cout << "Error: " << euler_err(f,0.4,1.0,23.0) << endl;

  return 0;
}