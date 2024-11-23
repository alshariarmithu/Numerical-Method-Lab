#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define TOL 1e-6

int main()
{    
    fastIO;
    cout<<"Enter the number of variables: ";
    int n;cin>>n;
    double coffecients[n][n];
    double constant[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)cin>>coffecients[i][j];
        cin>>constant[i];
    }
    vector<double>x_Old(n,0.0),x_New(n,0.0);
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
            x_New[i] = sum/coffecients[i][i];
            if(abs(x_New[i]-x_Old[i])>TOL)convergence=false;
        }
        x_Old = x_New;
        iter++;
        if(convergence)break;
    }
    if (convergence) {
        cout << "Converged in " << iter << " iterations." << endl;
        cout << "Solution:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "x" << i + 1 << " = " << x_New[i] << endl;
        }
    } else {
        cout << "Did not converge within " << max_iter << " iterations." << endl;
    }
    return 0;
}