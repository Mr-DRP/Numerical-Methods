#include<iostream>

using namespace std;

//function used is x^3-2x^2+3
double func(double x)
{
    return x*x - 3*x + 2;
}

double c;

int bisection(double a,double b,double e)
{
    if((func(a) * func(b)) >= 0)
    {
        cout<<"Incorrect a and b";
        return 0;
    }

    c = a;

    while ((b-a) >= e)
    {
        c = (a+b)/2;
        if (func(c) == 0.0){
            cout << "Root = " << c<<endl;
            break;
        }
        else if (func(c)*func(a) < 0){
                cout << "Root = " << c<<endl;
                b = c;
        }
        else{
                cout << "Root = " << c<<endl;
                a = c;
        }
    }
}

int main()
{
    double a,b,e;

    cout<<"The function used is x^2-3*x+2\n";
    cout<<"Enter the initial guess\na= ";
cin>>a;
cout<<"b= ";                //take an intial guess
cin>>b;
cout<<"Enter the degree of accuracy\n";
cin>>e;
    bisection(a,b,e);
    cout<<"\n";
    cout<<"Accurate Root calculated is = "<<c<<endl;

    return 0;
}
