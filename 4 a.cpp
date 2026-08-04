/* Toufiq Islam - 2310728141 */
//calculating current bil using user define function
#include<iostream>
#include<string>
using namespace std;
double bill(int unit)
{
	 int a=0,b=0,c=0,un=unit;
	 if(un > 500)
    {
       a = (un - 500);
       un = (un - a);
    }

    if(un > 250)
   {
      b = (un - 250);
      un = un - b;
   }

    if(un > 50)
   {
      c = (un - 50);
      un = un - c;
   }
   return (a * 5) + (b * 3.5) + (c * 2.5)+100.0 ;
}

int main()
{
   int x;
  start:	
	string name;
	int unit,prev,pre;
	double sum=0.0,vat=0.05,totbill;
	
	cout<<"Enter the user name : ";
	getline(cin,name);
	
	cout<<"Enter the previous meter reading"<<endl;
	cin>>prev;
	cout<<"Enter the present meter reading"<<endl;
	cin>>pre;
	
	unit=pre-prev;
	
	if(unit < 0)
    {
       cout << "Error in reading input";
       cin.ignore();
       goto start;
    }

     sum=bill(unit); //call the funcction
      cout<<"Total unit = "<<unit<<endl;    
      cout<<"Bill = "<<sum<<" Tk only"<<endl;
      
      totbill=sum+sum*vat+50;
      cout<<endl<<endl;
      
    cout << "----------------------------------------------------\n";  
    cout << "|--------------------------------------------------|\n";
    cout << "|                 ELECTRIC BILL                    |\n";
    cout << "|--------------------------------------------------|\n";
    cout << "|User name        = " <<name<<"\n";
    cout << "|Previous Reading = " << prev<< "\n";
    cout << "|Present Reading  = " << pre<< "\n";

    cout << "|--------------------------------------------------|\n";

    cout << "|Unit uses        = " << unit << "\n";
    cout << "|Unit bill        = " << sum << "\n";
    cout << "|Meter charge     = 50\n";
    cout << "|Vat     (5%)     = " << sum*vat << "\n";

    cout << "|--------------------------------------------------|\n";

    cout << "|Total bill       = " << totbill << "\n";

    cout << "|--------------------------------------------------|\n";
    
	cout <<endl;
	
	cout<<"If you want to calculate again type 1 else 0 for quit :\n";
	cin>>x;
	if(x==1)
	{
	   cin.ignore();
	   goto start;	
	}
	   
	return 0;
}