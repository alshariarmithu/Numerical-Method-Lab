#include<iostream>
#include<iomanip>
#include<math.h>

#define f(x) cos(x) - x * exp(x)

using namespace std;

int main()
{
    float x0,x1,x,f0,f1,f,err;
    int step = 1;
    up:
    cout<<"Enter First Guess: ";
    cin>>x0;
    cout<<"Enter Second Guess: ";
    cin>>x1;
    cout<<"Enter tolerable error: ";
    cin>>err;

    f0 = f(x0);
    f1 = f(x1);

    if(f0*f1>0.0){
        cout<<"Incorrect Initail Guesses";
        goto up;
    }

    cout<<"Flase Position Method"<<endl;
    
    do
    {
        x = x0 - (x0-x1)*f0/(f0-f1);
        f = f(x);

        cout<<"Iteration-"<<step<<": \t x = "<<setw(10)<<x<<" and f(x) = "<<setw(10)<<f(x)<<endl;
        if( f0 * f < 0)
		{
			x1 = x;
			f1 = f;
		}
		else
		{
			x0 = x;
			f0 = f;
		}
		  step = step + 1;
    } while (fabs(f)>err);
    cout<< endl<<"Root is: "<< x<< endl;
    return 0;
}