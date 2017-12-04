#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

 double f(double x,double y) {
	return  x*x+4*y;
}

double simpsons_cub(double A, double a, double B, double b){

    double hx = (A-a)/2.0;
    double hy = (B-b)/2.0;

    double x0 = a;
    double y0 = b;
    double x2 = A;
    double y2 = B;
    double x1 = a+hx;
    double y1 = b+hy;


    return (hx*hy/9)*(f(x0,y0)+f(x0,y2)+f(x2,y0)+f(x2,y2)+4*(f(x1,y0)+f(x0,y1)+f(x2,y1)+f(x1,y2))+16*f(x1,y1)); 
}


int main(){

    cout << fixed << setprecision(5);

    cout << simpsons_cub(14,11,10,7) << endl;
    
    return 0;  
}