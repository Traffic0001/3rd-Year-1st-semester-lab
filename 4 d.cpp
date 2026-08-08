/* Toufiq Islam - 2310728141 */
//Greading system
//marks input range(0-100) and viva & lab marks input range(0-50)
#include <iostream>
#include<iomanip>
#include<string>
using namespace std;
float grade(float marks, int subs)
{
    float credit;
    if (subs == 6 || subs ==7) 
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
    // Return obtained Credit x actual Credit
    if (subs == 6 || subs == 7)
        return credit * 2.00;  //2 credit course
    else
        return credit * 3.00;  //for 3 credit course
}
int main()
{
	cout<<fixed<<setprecision(3);
	float markEach[8],totCredit=0.0,cgpa; //markEach[8] arrow collect all 8 sunject mark individual
	int j =0, fail_count = 0;    //fail subject count
	string name;
	cout<<"Enter the name :"<<endl;
	cin>>name;
	
	cout<<"Mr./Mrs "<<name<<"Your result: "<<endl; 
	while(true)
	{
		
		cout << "Enter Marks of A. Math.- " << 3101 + j << " : ";
		cin>>markEach[j];   //taking input on each subject marks
		
		if (j <6 && markEach[j] < 40)   //checking fail for first 6 course
				fail_count++;
		
		totCredit +=grade(markEach[j], j);
		j++;
		
		if(j==8) break;  //there total 8 course so when course 9 means loop exit 	
	}
	
		if(markEach[6] < 20 || markEach[7] < 20) 
			cout << "\nCGPA = 0.00 Grade = F (Fail) : Failed in Lab or Viva : Semester drop" << endl;
			
	    else if(fail_count > 2)
	    {
	      cout << "\nCGPA = 0.00 Grade = F (Fail) : Semester drop" << endl;
		  cout <<"\nFailed in "<<fail_count<<"subject.\n";	
		}
		 
		else
		{
		        cgpa =  totCredit/ 22;
		        cout << "\nCumulative Grade Point Average(CGPA) = " << cgpa << endl;
		}
  return 0;		
}