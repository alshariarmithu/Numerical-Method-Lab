#include <bits/stdc++.h>
using namespace std;

const int SIZE = 10;

int main()
{
    int n;
    cout<<"Enter the number of variable: ";
    cin>>n;
    double a[SIZE][SIZE],x[SIZE],ratio;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n+1;j++)cin>>a[i][j];
    }
    //Gauss - Jordan - Method //
    for(int i=1;i<=n;i++)
    {
        if(a[i][i]==0.0){
            cout<<"Mathematical Error\n";
            exit(0);
        }
        for(int j=1;j<=n;j++)
        {
            if(i!=j)
            {
                ratio = a[j][i]/a[i][i];
                for(int k=1;k<=n+1;k++)
                {
                    a[j][k]=a[j][k]-ratio*a[i][k];
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        x[i] = a[i][n+1]/a[i][i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n+1;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    for(int i=1;i<=n;i++)
    {
        cout<<"x"<<i<<": "<<x[i]<<endl;
    }
    return 0;
}