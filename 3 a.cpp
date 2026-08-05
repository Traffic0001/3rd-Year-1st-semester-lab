/* Toufiq Islam - 2310728141 */
//checking n is prime or not
//also example of  using if under for loop
#include<iostream>
using namespace std;
int main()
{
	int n,i,si;
	bool prime=true;
	start:
	cout<<"Enter a positive integer number :"<<endl;
	cin>>n;
	
	if(n<=1)
	 prime=false;
	
	for(i=2;i*i<=n;i++)
	 
	 	if( n%i == 0)
	 	{
	 	 prime=false;
		  break;	
		}
	 
	 
	if(prime)
	    cout<<n<<" is a prime number. \n";
	else 
    	cout<<n<<" is not a prime number. \n"; 
	
	cout<<"If you want to run again type 1 else 0 for quit :\n";
	cin>>si;
	if(si==1)
	   goto start;	 
	
	return 0;
}
