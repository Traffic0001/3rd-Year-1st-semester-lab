//Program to find the maximum and minimum distances between any two points
//taken from a randomly given set of n distinct points

#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;

//#define MAX_ITEMS 1000

//Function to calculate distance between any two points
double disfun(double xl, double yl, double xr, double yr) 
{
   double xd = xl - xr;
   double yd = yl - yr;
   return sqrt(xd * xd + yd * yd);
}

int main()
{
    cout<<"\nPlease make sure that all the points you enter are distinct\n";
    int i, j, n;
    double xleft, yleft, xright, yright;
    cout<<"\nEnter the number of points\n";
    cin>>n;
    
	if(n<2)
    {
    	cout<<"\nThere should be at least two points\n";
    	exit(0);
	}
   	int N=n*(n-1)/2;
   	double dist[N];
    double a[n][2];
    cout<<"\nEnter the points row-wise\n";
    for(i=0;i<n;i++)
   		for(j=0;j<2;j++)
   		cin>>a[i][j];
   	
   //main algorithm
   int m=0;	
   for(i=0;i<n-1;i++)
   {
   	
   	xleft=a[i][0];
   	yleft=a[i][1];
   	for(j=i+1;j<n;j++)
   	{	
   		xright=a[j][0];
   		yright=a[j][1];
   		cout<<"("<<xleft<<","<<yleft<<")"<<endl;
		cout<<"("<<xright<<","<<yright<<")"<<endl;
		dist[m]=disfun(xleft, yleft, xright, yright);
		cout<<"\nThe distances are: dist["<<m<<"]"<<setw(5)<<dist[m]<<endl;
		m++;
	}
   }
    //sorting the distances vector in ASCENDING ORDER
	for(i=0;i<m;i++)
	{		
		for(j=i+1;j<m;j++)
		{
			if(dist[i]>dist[j])
			{
				double temp  =dist[i];
				dist[i]=dist[j];
				dist[j]=temp;
			}
		}
	}
	cout<<"\nThe smallest distance is\n";
    cout<<dist[0]<<endl;
    cout<<"\nThe largest distance is\n";
    cout<<dist[m-1]<<endl;	
return 0;
}