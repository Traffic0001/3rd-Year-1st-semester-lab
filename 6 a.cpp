//system of solution using Gauss
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	int n,i,j,k;
	double t;
	cout<< fixed<< setprecision(3);
	
	cout<<"\n Enter the total equation No: \n";
	cin>>n;
	double a[n][n+1],x[n];
	
	cout<<"\nEnter the elements of the augmented-matrix row-wise:\n";
    for (i=0;i<n;i++)
        for (j=0;j<=n;j++)    
            cin>>a[i][j];  
            
    cout<<"\n The matrix you have entered : \n";
	for(i=0;i<n;i++)
	{
	  	for(j=0;j<=n;j++)
	    cout<<a[i][j]<<"    ";
	    
		cout<<endl;  	
	} 
  //now pivotising
   for(i=0;i<n;i++)
        for(k=i+1;k<n;k++)
            if(abs(a[i][i])<abs(a[k][i]))
               for(j=0;j<=n;j++)
               {
               	 double temp=a[i][j];
               	 a[i][j]=a[k][j];
               	 a[k][j]=temp;
			   }
			   
    cout<<"\n The matrix after pivotising : \n";
    
	for(i=0;i<n;i++)
	{
	  	for(j=0;j<=n;j++)
	    cout<<a[i][j]<<"   ";
	    
		cout<<endl;  	
	}   
	
	//now lets do traffic gauss
	
	for(i=0;i<n-1;i++)    //select first row
	   {
	   	  if(a[i][i]==0)
           {
              cout<<"No unique solution";
              return 0;
           }
		
		  for(k=i+1;k<n;k++)   //select next row
	       {
	         t=a[k][i]/a[i][i];  //make factor using next row's same column of (i,i)th term
	            for(j=0;j<=n;j++)  //making each column change
	                a[k][j]=a[k][j]-t*a[i][j];  // new row of k=(i+1)th rows 
		   }
	   }
	   

	               
   	
	cout<<"\n The matrix after Gauss : \n";
	for(i=0;i<n;i++)
	{
	  	for(j=0;j<=n;j++)
	    cout<<a[i][j]<<"   ";
	    
		cout<<endl;  	
	} 
   	  
	// now back substituition
	
	for(i=n-1;i>=0;i--)
	{
		if(a[i][i]==0)
		{
			cout<<"\nNo unique Solution : \n";
			exit(0); //better use return 0;
		}
		else
		{
			x[i]=a[i][n];
			   for(j=i+1;j<n;j++)
			    x[i]=x[i]-a[i][j]*x[j]; //ith rows all i-j column I mmean all column after (i,i)th corner.
			    
			x[i]=x[i]/a[i][i] ; //devide coefficient that alreay attached with variable like ax2=d -> x2=d/a;   
		}
	}
  cout<<"The values of the variables are as : \n";
    for(i=0;i<n;i++)
	   cout<<x[i]<<endl;
	return 0;   	
}