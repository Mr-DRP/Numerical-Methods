#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double f(double x)    //define the function here, ie give the equation
{
    double a=pow(x,3.0)-x-11.0;    //write the equation whose roots are to be determined
    return a;
}
double fprime(double x)
{
    double b=3*pow(x,2.0)-1.0;        //write the first derivative of the equation
    return b;
}
int main()
{
    double x,x1,e,fx,fx1;
    double d=0.001,c=0;
    cout.precision(4);        //set the precision
    cout.setf(ios::fixed);
    cout<<"Enter the initial guess\n";    //take an intial guess
    cin>>x1;
    cout<<"Enter desired accuracy\n";    //take the desired accuracy
    cin>>e;
    cout <<"x{i}"<<setw(17)<<"x{i+1}"<<setw(22)<<"|x{i+1}-x{i}|"<<endl;

    do
    {   c+=1;
        x=x1;                /*make x equal to the last calculated value of                             x1*/
        fx=f(x);            //simplifying f(x)to fx
        fx1=fprime(x);
        if(fx1<d)
        {
            cout<<"The slope is too small";
            return 0;
        }
            if(c>50)
        {
            cout<<"The method cannot converge due to oscillation";
            return 0;
        }        //simplifying fprime(x) to fx1
        x1=x-(fx/fx1);            /*calculate x{1} from x, fx and fx1*/
        cout<<x<<setw(15)<<x1<<setw(20)<<abs(x1-x)<<endl;
    }while (fabs(x1-x)>=e);            /*if |x{i+1}-x{i}| remains greater than the desired accuracy, continue the loop*/
    cout<<"The root of the equation is "<<x1<<endl;
    return 0;
}
