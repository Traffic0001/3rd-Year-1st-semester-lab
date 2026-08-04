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
    
    for(int i = 1; i <= n; i++)
        fact = fact * i;
        
    cout << "Factorial = " << fact;

    return 0;
}