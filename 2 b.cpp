//series sin(x)
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

// Function to calculate factorial
long long fact(int n)
{
    long long f = 1; 

    for(int i = 1; i <= n; i++)
        f = f * i;

    return f;
}

int main()
{
    double x,sum=0,tol,sum1=1;
    int i=0;
    cout<<fixed<<setprecision(10); 
    cout << "Enter x (radian): ";
    cin >> x;
    cout << "Enter tolerance : ";
    cin >> tol;
    
    while(fabs(sum1-sum)>=tol)
    {
    	sum1=sum;
		sum=sum+(pow(-1,i)*pow(x,2*i+1))/fact(2*i+1);
		i++;
		
	}
    
    cout<<sum<<endl;
    return 0;
}