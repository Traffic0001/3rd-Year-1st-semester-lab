/* Toufiq Islam - 2310728141 */
//checking n is prime or not using function
#include<iostream>
using namespace std;

bool check(int n)
{
  bool prime=true;
  if(n<=1)
	 prime=false;
	
	for(int i=2;i*i<=n;i++)
	 
	 	if( n%i == 0)
	 	{
	 	  prime=false;
		  break;	
		}
   return prime;	 
}

int main()
{
	int n,i,si;
	start:
	cout<<"Enter a positive integer number :"<<endl;
	cin>>n;
	 
	if(check(n))
	    cout<<n<<" is a prime number. \n";
	else 
    	cout<<n<<" is not a prime number. \n";  
	
	
	cout<<"If you want to calculate again type 1 else 0 for quit :\n";
	cin>>si;
	if(si==1)
	   goto start;	
	
	return 0;
}