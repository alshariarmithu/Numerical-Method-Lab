#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdlib.h>
using namespace std;

#define    f(x)    3*x - cos(x) -1
#define   g(x)   3 + sin(x)


int main()
{    
    float x0,x1,e,N,x,f0,g0,f1;
    int step = 1;
    cout<<"Enter first guess: ";
	cin>>x0;
	cout<<"Enter tolerable error: ";
	cin>>e;
	cout<<"Enter maximum iteration: ";
	cin>>N;
    do{
        f0 = f(x0);
        g0 = g(x0);
        if(g0==0.0)return 0;
        x1 = x0 - f0/g0;
        cout<<"Iterations- "<<step<<" : x = "<<x1<<" f(x) = "<<f(x1)<<endl;
        x0 = x1;
        if(step>N){
            cout<<"Not Convergent\n";
            return 0;
        }
        f1 = f(x1);
        step++;
    }while(fabs(f1)>e);
    cout<<"Root is: "<<x1<<endl;
    return 0;
}