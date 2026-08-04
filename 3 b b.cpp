//using function to get factorial
//it can get upto 1754!
#include<iomanip>
#include <iostream>
using namespace std;

// Function to calculate factorial
long double factorial(int n)
{
    long double fact = 1;

    for(int i = 1; i <= n; i++)
        fact = fact * i;

    return fact;
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;
    cout<<fixed<<setprecision(0);
    cout << "Factorial = " << factorial(n);

    return 0;
}