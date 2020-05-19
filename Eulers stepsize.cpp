/* CPP Program to find approximation
of a ordinary differential equation
using euler method.*/
#include <iostream>
#include <iomanip>
using namespace std;
float func(float x, float y)
{
	return (x+y);
}

int main()
{
    float x0,y0,h,xn,yd,ydh;
    cout<<"Enter initial values of x and y"<<endl;
    cin>>x0>>y0;
    cout<<"Enter final value of x and stepsize to be taken"<<endl;
    cin>>xn>>h;
	int n=(xn-x0)/h;
	float x[n],y[n];
	x[0]=x0,y[0]=y0;
	cout<<"x"<<setw(9)<<"y"<<setw(19)<<"f(x,y)"<<setw(19)<<"hf(x,y)"<<endl;
    cout<<"-----------------------------------------------------------------\n";
    for (int i=0;i<=n;i++)
        {   yd=func(x[i],y[i]);
            ydh=h*func(x[i],y[i]);
            cout<<x[i]<<setw(12)<<y[i]<<setw(15)<<yd<<setw(18)<<ydh<<endl;
            x[i+1]=x[i]+ h;
            y[i+1]=y[i]+ydh;
        }
	return 0;
}
