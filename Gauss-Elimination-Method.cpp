#include <bits/stdc++.h>
using namespace std;
const int SIZE = 10;

int main()
{ 
    int n;   
    cout<<"Enter the number of variables: ";
    cin>>n;
    double a[SIZE][SIZE],X[SIZE],ratio;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n+1;j++)cin>>a[i][j];
    }
    //Gauss Elimination //

    for(int i=1;i<=n-1;i++)
    {
        if(a[i][i]==0.0){
            cout<<"Mathematical Error\n";
            exit(0);
        }
        for(int j=i+1;j<=n;j++)
        {
            ratio = a[j][i]/a[i][i];
            for(int k=1;k<=n+1;k++)
            {
                a[j][k] = a[j][k]-ratio*a[i][k];
            }
        }
    }
    // Back Substitution Method //
    X[n] = a[n][n+1]/a[n][n]; 
    for(int i=n-1;i>=1;i--)
    {
        X[i] = a[i][n+1];
        for(int j=i+1;j<=n;j++)
        {
            X[i] = X[i] - a[i][j]*X[j];
        }
        X[i] = X[i]/a[i][i];
    }

    for(int i=1;i<=n;i++)
    {
        cout<<"x"<<i<<" : "<<X[i]<<" ";
    }
    cout<<endl;
    return 0;
}