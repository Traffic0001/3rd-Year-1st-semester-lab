/* Toufiq Islam - 2310728141 */
//function to get factorial
//it can get upto 1754!
#include<iomanip>
#include <iostream>
using namespace std;

int main()
{
    int n;
    long double fact = 1;
    cout << "Enter a number (positive integer): ";
    cin >> n;
    cout<<fixed<<setprecision(0);
    
    if(n<0)
        cout <<"\nFactorial does not exist = \n";
    else 
	{
	 for(int i = 1; i <= n; i++)
        fact = fact * i;
    cout << "Factorial = " << fact;	
	}
 

    return 0;
}