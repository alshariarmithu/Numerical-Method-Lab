#include <bits/stdc++.h>
using namespace std;
#define TOL 1e-6

int main()
{    
    cout<<"Enter the number of variables: ";
    int n;cin>>n;
    double coffecients[n][n];
    double constant[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)cin>>coffecients[i][j];
        cin>>constant[i];
    }
    vector<double>x_Old(n,0.0);
    int max_iter = 100;
    int iter = 0;
    bool convergence = false;
    while(iter<max_iter)
    {
        convergence = true;
        for(int i=0;i<n;i++)
        {
            double sum = constant[i];
            for(int j=0;j<n;j++)
            {
                if(i!=j){
                    sum-=(coffecients[i][j]*x_Old[j]);
                }
            }
            double x_New = sum/coffecients[i][i];
            if(abs(x_New-x_Old[i])>TOL)convergence=false;
            x_Old[i] = x_New;
        }
        iter++;
        if(convergence)break;
    }
    if (convergence) {
        cout << "Converged in " << iter << " iterations." << endl;
        cout << "Solution:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "x" << i + 1 << " = " << x_Old[i] << endl;
        }
    } else {
        cout << "Did not converge within " << max_iter << " iterations." << endl;
    }
    return 0;
}