#include <bits/stdc++.h>
using namespace std;

double u_cal(double u, int n)
{
    double tmp = u;
    for(int i=1;i<n;i++)
    {
        tmp=tmp*(u-i);
    }
    return tmp;
}

int fact(int n)
{
    int factorial = 1;
    for(int i=2;i<=n;i++)factorial*=i;
    return factorial;
}

int main()
{    
    int n=5;
    double x[] = {1,2,3,4,5};
    double y[n][n];
    y[0][0] = 3.25;
    y[1][0] = 3.05;
    y[2][0] = 3.5;
    y[3][0] = 3.75;
    y[4][0] = 4.0;

    // Forward Difference Table //
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            y[j][i] = y[j+1][i-1] - y[j][i-1];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            cout<<y[i][j]<<" "; 
        }
        cout<<"\n";
    }
    double Xn = 2.5;
    double sum = y[0][1];
    double  u = (Xn - x[0])/(x[1]-x[0]);
    for(int i=2;i<n;i++)
    {
        sum+=(u_cal(u,i-1)*y[0][i])/fact(i-1);
    }
    sum/=(x[1]-x[0]);
    cout<<"Answer is: "<<sum<<endl;
    return 0;
}