#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double f(double x);    //declare the function for the given equation
double f(double x)    //define the function here, ie give the equation
{
    double a=pow(x,3)-x-11.0;    //write the equation whose roots are to be determined
    return a;
}
int main()
{
        //set the precision of the output
double a,b,c,e;
cout<<"Enter the initial guess\na= ";
cin>>b;
cout<<"b= ";                //take an intial guess
cin>>c;
cout<<"Enter the degree of accuracy\n";
cin>>e;
if(fabs(f(b))<fabs(f(c)))                   //take the desired accuracy
{
    a=b;
    b=c;
    c=a;
}
do
{
    a=b;
    b=c;                //make b equal to the last calculated value of c
    c=b-(b-a)/(f(b)-f(a))*f(b);
    cout << "Root = " << c<<endl;    //calculate c
    if (f(c)==0)
    {
        cout<<"\nThe root of the equation is "<<c;    //print the root
        return 0;
    }
}while(abs(c-b)>=e);            //check if the error is greater than the desired accuracy
cout<<"\nThe root of the equation is "<<c;    //print the root
return 0;
}
