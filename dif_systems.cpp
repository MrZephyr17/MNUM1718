#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double delta1g(double x, double y, double z, double h);
double delta2g(double x, double y, double z, double h);
double delta3g(double x, double y, double z, double h);


double f(double x, double y, double z){
    return 15.0* pow(exp(1),(-0.1/(y+273)))*z - 0.1*(y-20);   
}


double g(double x, double y, double z){
    return -(pow(exp(1),(-0.1/(y+273))))*z;
}


void euler_sist(double f(double,double,double), double g(double,double,double), double h, double x0, double y0, double z0, int numIt){

    double x= x0;
    double y = y0;
    double z = z0;

    cout << "Euler method" << endl; 

    for(int i=0;i<numIt;i++){
    
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;

    double y_temp = y;
    y+=h*f(x,y,z);
    z+=h*g(x,y_temp,z);
    x+=h;
    }

    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
}

double delta1f(double x, double y, double z, double h)
{
	return h* f(x, y,z);
}

double delta2f(double x, double y, double z, double h)
{
	return h* f(x + (h / 2), y + (delta1f(x, y, z, h) / 2), z + (delta1g(x, y, z, h) / 2));
}


double delta3f(double x, double y, double z, double h)
{
	return h* f(x + (h / 2), y + (delta2f(x, y, z, h) / 2), z + (delta2g(x, y, z, h) / 2));
}

double delta4f(double x, double y, double z, double h)
{
	return h* f(x + h, y + delta3f(x, y, z, h), z + delta3g(x, y, z, h));
}

double delta1g(double x, double y, double z, double h)
{
	return h* g(x, y,z);
}

double delta2g(double x, double y, double z, double h)
{
	return h* g(x + (h / 2), y + (delta1f(x, y, z, h) / 2), z + (delta1g(x, y, z, h) / 2));
}


double delta3g(double x, double y, double z, double h)
{
	return h* g(x + (h / 2), y + (delta2f(x, y, z, h) / 2), z + (delta2g(x, y, z, h) / 2));
}

double delta4g(double x, double y, double z, double h)
{
	return h* g(x + h, y + delta3f(x, y, z, h), z + delta3g(x, y, z, h));
}


void rk4_sist(double f(double,double,double), double g(double,double,double), double h, double x0, double y0, double z0, int numIt){

    double x = x0;
    double y = y0;
    double z = z0;

    cout << endl << "Runge-Kutta4 method" << endl;

    for(int i=0;i<numIt;i++){
    
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;

    double y_temp = y;
    y+=(delta1f(x, y, z, h) / 6) + (delta2f(x, y, z, h) / 3) + (delta3f(x, y, z, h) / 3) + (delta4f(x, y, z, h) / 6);
    z+=(delta1g(x, y_temp, z, h) / 6) + (delta2g(x, y_temp, z, h) / 3) + (delta3g(x, y_temp, z, h) / 3) + (delta4g(x, y_temp, z, h) / 6);
    x+=h;
    }

    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
}


int main(){

    euler_sist(f,g,0.25,0.5,20.0,2.0,2);

    rk4_sist(f,g,0.25,0.5,20.0,2.0,2);

    return 0;
}