#include<iostream>
#include<iomanip>
#include<math.h>

#define f(x) x*x-4*x-10

using namespace std;

int main()
{
	 float x0, x1, x, f0, f1, f, e;
	 int step = 1;

     cout<< setprecision(6)<< fixed;

	 up:
	 cout<<"Enter first guess: ";
     cin>>x0;
     cout<<"Enter second guess: ";
     cin>>x1;
     cout<<"Enter tolerable error: ";
     cin>>e;

	 f0 = f(x0);
	 f1 = f(x1);

	 if( f0 * f1 > 0.0)
	 {
		  cout<<"Incorrect Initial Guesses."<< endl;
		  goto up;
	 }
   /* Implementing Bisection Method */
     cout<< endl<<"****************"<< endl;
	 cout<<"Bisection Method"<< endl;
	 cout<<"****************"<< endl;
	 do 
	 {
		  /* Bisecting Interval */
		  x = (x0 + x1)/2;
		  f = f(x);

		  cout<<"Iteration-"<< step<<":\t x = "<< setw(10)<< x<<" and f(x) = "<< setw(10)<< f(x)<< endl;

		  if( f0 * f < 0)
		  {
			   x1 = x;
		  }
		  else
		  {
			   x0 = x;
		  }
		  step = step + 1;
	 }while(fabs(f)>e);

	 cout<< endl<<" Root is: "<<  x<< endl;

	 return 0;
}