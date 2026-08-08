/* Toufiq Islam - 2310728141 */
//phone bill
//first 150 minutes are free
//next 250 (151-400 minutes) calls are charged at 1/min
//more than 400 calls are charged 2/min
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

double charge(double ncall)
{
	if(ncall<=150)
	  return 0;
	else if(ncall<=400)
	  return (ncall-150)*1;
	else
	  return (ncall-400)*2+250;   
}

int main()
{
	cout<<fixed<<setprecision(2);
	double calls;
	string name;
	
	cout<<"Enter the user name : "<<endl;
	cin>>name;
	
	cout<<"Enter the total call duration (in minutes):\n";
	cin>>calls;
	
	cout<<"\nMr./Mrs. "<<name<<endl;
	cout<< "\nYour total phone bill to paid = "<<charge(calls)<<" Taka only";
	
	return 0;
}
