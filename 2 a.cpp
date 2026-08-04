//series ln(1+x)
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;


int main()
{
    double x,sum=0,tol,sum1=1;
    int i=1;
    cout<<fixed<<setprecision(10); 
    cout << "Enter x (radian): ";
    cin >> x;
    cout << "Enter tolerance : ";
    cin >> tol;
    
    if(x <= -1 || x > 1)
    {
       cout << "Series is not valid for this value of x.";
       return 0;
    }
    
    while(fabs(sum1-sum)>=tol)
    {
    	sum1=sum;
		sum=sum+(pow(-1,i-1)*pow(x,i))/i;
		i++;
		
	}
    
    cout<<"\nTotal sum within the tolerance = "<<sum<<endl;
    return 0;
}