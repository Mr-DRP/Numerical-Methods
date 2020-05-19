#include <iostream>
#include <cmath>
using namespace std;
double ddx(double x,double y,double z)
{
	double dz = (-5*z-3*y)/2;
	return dz;
}

double test2ndorder(double x0, double y0, double z0, double x, double h)
{
	int n = (int)((x - x0) / h);
	double k1, k2, k3, k4;
	double l1, l2, l3, l4;
	double y = y0;
	double z = z0;
	for (int i = 1; i <= n; i++)
	{

		k1 = h * z;
		l1 = h * ddx(x0, y, z);
		k2 = h * (z + 0.5*l1);
		l2 = h * ddx(x0 + 0.5*h, y + 0.5*k1, z + 0.5*l1);
		k3 = h * (z + 0.5*l2);
		l3 = h * ddx(x0 + 0.5*h, y + 0.5*k2, z + 0.5*l2);
		k4 = h * (z + l3);
		l4 = h * ddx(x0 + h, y + k3, z + l3);
        z = z + (1.0 / 6.0)*(l1 + 2 * l2 + 2 * l3 + l4);
		y = y + (1.0 / 6.0)*(k1 + 2 * k2 + 2 * k3 + k4);
		x0 = x0 + h;
	}
	return y;
}

int main()
{
	double x0, y0, z0, x, y, z,h;
	cout<<"Enter the initial values for x and y: ";
	cin>>x0>>y0;
	cout<<"Enter the value of x for which y is required: ";
	cin>>x;
	cout<<"Enter the step-width h: ";
	cin>>h;
	z0 = -4;
	y = test2ndorder(x0, y0, z0, x, h);
	cout << y;
	return 0;
}
