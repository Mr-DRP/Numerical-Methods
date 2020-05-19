#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
/*Define the RHS of the first order differential equation here(Ex: dy/dx=f(x,y))  */
double f(double x, double y){
	//return 2-exp(-4*x)-2*y;
	return x+y;
	//return x;
}
int main(){
	int i;
	 cout.precision(5);
	 cout.setf(ios::fixed);
	double x,y,x0,h,k1,k2,e,k3,k4;
	cout<<"Enter the initial condition for x and y: ";
	cin>>x0>>y;
	cout<<"Enter the value of x for which y is required: ";
	cin>>x;
	cout<<"Enter the step-width h: ";
	cin>>h;
	cout<<"x\t\ty\n";
	cout<<"_____________________\n";
	int n = (int)((x - x0) / h);
	//Begin Runge-Kutta Routine
	for (int i=0; i<=n; i++)
        {
		k1 = h*f(x0, y);
        k2 = h*f(x0 + 0.5*h, y + 0.5*k1);
        k3 = h*f(x0 + 0.5*h, y + 0.5*k2);
        k4 = h*f(x0 + h, y + k3);

        // Update next value of y
        y = y + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);

        // Update next value of x
        x0 = x0 + h;
        cout<<x0<<setw(15)<<y<<endl;
        }
	cout<<"________________________\n";
	cout<<"The value of y is \n\n"<<y;
	return 0;
}
