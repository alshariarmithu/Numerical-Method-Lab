#include <bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdlib.h>
using namespace std;

#define    f(x)    x*x*x - 2*x - 5

int main()
{    
    float x0,x1,f0,f1,f2,x2,err;
    int step = 1,N;
    cout<< setprecision(6)<< fixed;
    cout<<"Enter First Guess: ";
    cin>>x0;
    cout<<"Enter Second Guess: ";
    cin>>x1;
    cout<<"Enter Tolerance Limit: ";
    cin>>err;
    cout<<"Enter Maximum Iteration: ";
    cin>>N;
    do{
        f0 = f(x0);
        f1 = f(x1);
        if(f0==f1){
            cout<<"Error\n";
            return 0;
        }
        x2 = x1 - (x1-x0)*f1/(f1-f0);
        f2 = f(x2);
        cout<<"Iteration- "<<step<<" : x = "<<x2<<" f(x) = "<<f(x2)<<endl;
        x0=x1;
        x1=x2;
        f0=f1;
        f1=f2;
        step++;
        if(step>N)
        {
            cout<<"Not Converged\n";
            return 0;
        }
    }while(fabs(f2)>err);
    cout<<"Root is: "<<x2<<endl;
    return 0;
}