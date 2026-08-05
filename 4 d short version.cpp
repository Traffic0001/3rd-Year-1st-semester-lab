/* Toufiq Islam - 2310728141 */
//Greading system
//marks input range(0-100) and viva & lab marks input range(0-50)
#include <iostream>
#include<iomanip>
using namespace std;
float grade(float marks, int subs)
{
    float credit;
    if (subs == 6 ) 
		marks = (marks * 100) / 50; // subs that have 50 marks convert into 100;
		
    if (marks >= 80)
        credit = 4.00;
    else if (marks >= 75)
        credit = 3.75;
    else if (marks >= 70)
        credit = 3.50;
    else if (marks >= 65)
        credit = 3.25;
    else if (marks >= 60)
        credit = 3.00;
    else if (marks >= 55)
        credit = 2.75;
    else if (marks >= 50)
        credit = 2.50;
    else if (marks >= 45)
        credit = 2.25;
    else if (marks >= 40)
        credit = 2.00;
    else
        credit = 0.00;
    return credit;
}
int main()
{
	double marks;
	int subs;
	
	cout<<"Enter marks :"<<endl;
	cin>>marks;
	
	cout<<"Subject no (6 for 2 credit course): "<<endl;
	cin>>subs;
	
	cout<<"Your GPA is : "<<grade(marks,subs);
}