/* Toufiq Islam - 2310728141 */
//implementation of Bisection method
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

double ff(double x)
{
	return x*sin(x)-1;
}
int main()
{
    cout<<fixed<<setprecision(6);
    double a,b,c, tol,fa,fb,fc;
    
    cout<<"Please enter the required accuracy : \n";
    cin>>tol;
    a: cout<<"\nEnter the initial guesses :\n";
    cin>>a>>b;
    
    
    if(ff(a)*ff(b)>0)
      {
    	  cout<<"\nThere is no root between a and b : \n";
    	  goto a;
      }
      
	else
     {
    		
    	while(fabs(a-b)>=tol)
    	 {
    			c=(a+b)/2.0;

    		    fc=ff(c);

    		if(fabs(fc)<1e-16)
    		{
    			cout<<"\nThe required root is :"<<c<<endl;
    			break;
			}
			else
			{
				if((ff(a)*ff(c))<0)
				b=c;
				else if((ff(c)*ff(b))<0)
				a=c;
			}
    	
		 }
			
			cout<<"The required root is : "<<c<<endl;
    		
	 }
		
	return 0;	
    	
}

	