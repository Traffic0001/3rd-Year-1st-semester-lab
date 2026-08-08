/* Toufiq Islam - 2310728141 */
//Income Tax calculation
//First 250000 tax free
//5% tax for next 250000 
//10% tax for next 500000
//20% tax for next 4000000 
//40% tax for income above 5000000

#include<iostream> 
#include<iomanip>
using namespace std;

double tax(double income)
{	
	if(income<=250000)
		return 0;
	else if (income<=500000)
		return (income-250000)*0.05;
	else if (income<=1000000)
		return (income-500000)*0.1+(250000*0.05);
	else if (income<=5000000)
		return (income-1000000)*0.2+(500000*0.1)+(250000*0.05);
	else
		return (income-5000000)*0.4+(4000000*0.2)+(500000*0.1)+(250000*0.05);
}
int main( )
{
	
    cout<<fixed<<setprecision(2);
	double y_income;
	int si;
	
	a:
	cout<<"Enter the yearly total income :\n";
	cin>>y_income;
	
	cout<<"\nIncome TAX = "<<tax(y_income)<<" Taka only"<<endl;
	
	cout<<"\nDo you want to calculate tax for different person?\n";
	cout<<"\nIf yes, press 1 or press 0?\n";
	cin>>si;
	if(si==1)goto a;
    return 0;
}