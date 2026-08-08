#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;
int main()
{
	int i,j,n;
	cout<<fixed<<setprecision(5);
	
	cout<<"Enter dimension :\n";
	cin>>n;
	double a[n][n],b[n],c[n],k,eps,y;
	
	cout<<"\n Please enter the matrix row wise : \n";
	for(i=0;i<n;i++)
	   for(j=0;j<n;j++)
	     cin>>a[i][j];
    cout<<"\n Please enter the initial guesses : \n";
	for(i=0;i<n;i++)
	    cin>>b[i];
     cout<<"\n Please enter the accuracy : \n";	
	 cin>>eps;
	 
	k=0;
	do
	{
		y=k;
		for(i=0;i<n;i++)
		{
		   c[i]=0.0;
	       for(j=0;j<=n;j++)
	           c[i]=c[i]+a[i][j]*b[j];	
		}

	     k=c[0];
	   for(i=0;i<n;i++)
	   {
		   if(fabs(k)<fabs(c[i])) 
	       k=c[i];	
	   }
	
	   for(i=0;i<n;i++)
	       b[i]=c[i]/k;           
	}while(fabs(k-y)>=eps);
	
	cout<<"\n\nThe largest Eigenvalue is: "<<k<<endl;
    cout<<"\nAnd the corresponding Eigenvector is: \n";
    for (i=0;i<n;i++)
        cout<<b[i]<<endl;
    cout<<"\n"; 
	
	
	  
    return 0;	  	   
}