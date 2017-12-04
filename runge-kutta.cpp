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

double f1(double x, double y)
{
	return x*x + y*y;
}


double runge_kutta2(double f(double,double), double h, double x0, double y0){

    double x = x0;
    double y = y0;

    for(int i=0;i<2;i++){
        y+=h*f(x+h/2,y+(h/2)*f(x,y));
        x+=h;
    }

    return y;
}


double runge_kutta4(double f(double,double), double h, double x0, double y0){

    double x = x0;
    double y = y0;
    double delta1, delta2, delta3, delta4;

    for(int i=0;i<2;i++){

        delta1 = h*f(x,y);
        delta2 = h*f(x+h/2,y+delta1/2);
        delta3 = h*f(x+h/2,y+delta2/2);
        delta4 = h*f(x+h/2,y+delta3);

        y+=delta1/6 + delta2/3 +delta3/3 + delta4/6; 
        x+=h;
    }

    return y;
}

double runge_kutta2_conv(double f(double,double), double h, double x0, double y0){

    double s = runge_kutta2(f,h,x0,y0);
    double s1 = runge_kutta2(f,h/2,x0,y0);
    double s2 = runge_kutta2(f,h/4,x0,y0);

   return (s1-s)/(s2-s1);

}

double runge_kutta2_err(double f(double,double), double h, double x0, double y0){

  double s1 = runge_kutta2(f,h/2,x0,y0);
  double s2 = runge_kutta2(f,h/4,x0,y0);

  return (s2-s1)/3;

}

double runge_kutta4_conv(double f(double,double), double h, double x0, double y0){

    double s = runge_kutta4(f,h,x0,y0);
    double s1 = runge_kutta4(f,h/2,x0,y0);
    double s2 = runge_kutta4(f,h/4,x0,y0);

   return (s1-s)/(s2-s1);

}

double runge_kutta4_err(double f(double,double), double h, double x0, double y0){

  double s1 = runge_kutta4(f,h/2,x0,y0);
  double s2 = runge_kutta4(f,h/4,x0,y0);

  return (s2-s1)/3;

}

int main(){

  const int OUT_PREC = 5;

  cout << fixed << setprecision(OUT_PREC);

  cout << "Runge-Kutta2 method" << endl << endl << "Result: " <<  runge_kutta2(g,0.5,4.0,0.0) << endl;

  cout << "Convergence: " << runge_kutta2_conv(g,0.5,4.0,0.0) << endl;

  cout << "Error: " << runge_kutta2_err(g,0.5,4.0,0.0) << endl;

  cout << endl << "Runge-Kutta4 method" << endl << endl << "Result: " <<  runge_kutta4(g,0.5,4.0,0.0) << endl;

  cout << "Convergence: " << runge_kutta4_conv(g,0.5,4.0,0.0) << endl;

  cout << "Error: " << runge_kutta4_err(g,0.5,4.0,0.0) << endl;

}