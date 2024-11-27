#include <bits/stdc++.h>
using namespace std;

#define f(x,y) (y*y-x*x)/(y*y+x*x)


int main()
{    
    double Xn,X0,Y0,n,Yn;
    cout<<"Enter 1st guess: ";
    cin>>X0;
    cout<<"Enter 2nd guess: ";
    cin>>Y0;
    cout<<"Enter calculation point Xn: ";
    cin>>Xn;
    cout<<"Number of Steps: ";
    cin>>n;

    double k1,k2,k3,k4,k;
    double h = (Xn-X0)/n;
    for(int i=1;i<=n;i++)
    {
        k1 = h*f(X0,Y0);
        k2 = h*f((X0+h/2),(Y0+k1/2));
        k3 = h*f((X0+h/2),(Y0+k2/2));
        k4 = h*f((X0+h),(Y0+k3));
        k = (k1+k2+k3+k4)/6;
        Yn = Y0+k;
        cout<<X0<<" "<<Y0<<" "<<Yn<<endl;
        X0 = X0+h;
        Y0 = Yn;
    }

    cout<<"Value of y at Xn = "<<Yn<<endl;

    return 0;
}