/* Toufiq Islam - 2310728141 */
//nr method
// while is suitable than for loop
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

 double ff(double x)
  {
  	return x*sin(x)-1;
  }

 double df(double x)
  {
  	return x*cos(x)+sin(x);
  }
 int main()
  {
 	cout<<fixed<<setprecision(5);

	double a,b,tol;
	
	cout<<"Enter the initial value :"<<endl;
 	cin>>a;

 	cout<<"Enter the tolerance :"<<endl;
 	cin>>tol;


 	do
 	 {

	 b=a;


 	 a=a-(ff(a)/df(a));

    }
    while(fabs(a-b) >=tol);
    //cout<<"Root  b "<<b<<endl;
    cout<<"Root  a "<<a<<endl;
 	return 0;
  }
