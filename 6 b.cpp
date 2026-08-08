//cramers
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double determinant(double a[][100],int n)
{
	int i,j,k;
	double det=1.0;
	
   for(i=0;i<n;i++)
	{
	  int maxRow=i;
	  for(k=i+1;k<n;k++)
	  {
	  	if(fabs(a[k][i])>fabs(a[maxRow][i]))
	  	    maxRow=k;
	  }	
	  
	  if(maxRow !=i)
	  {
	  	for(j=0;j<n;j++)
	  	  {
	  	    double temp= a[i][j];
			  a[i][j]=a[maxRow][j];
			  a[maxRow][j]=temp;	
		  }
		  det *=-1.0;
	  }
	  if(fabs(a[i][i])<1e-10)
	  {
	  	det=0.0;
	  	break;
	  }
	  for(k=i+1;k<n;k++)
	   {
	   	 double t=a[k][i]/a[i][i];
	   	    for(j=0;j<n;j++)
	   	      a[k][j] -=t*a[i][j];
	   }
	}
	if(det !=0)
	{
	    for(i=0;i<n;i++) 
	       det *= a[i][i];
	}
	
  return det;
}

int main()
{
	int i,j,k,n;
	cout<<fixed<<setprecision(3);
	
	cout<<"\nEnter the order of the matrix:\n";        //Get the order of the square matrix
    cin>>n;
    double A[100][100],T[100][100],B[100][100],b[100],x[100];
    
    cout<<"\nEnter the elements of matrix row-wise:\n";
    for (i=0;i<n;i++)                    //Get the elements of the matrix
        for (j=0;j<n;j++)
        {
           cin>>A[i][j];
		   T[i][j]=A[i][j];	
		}
            
    cout<<"\nEnter the RHS vector:\n";
    for (j=0;j<n;j++)                    
        cin>>b[j];
        
	double detA= determinant(A,n);
	if(fabs(detA)<1e-9)
	{
		cout<<"No unique solution";
		return 0;
	}
	
	for(i=0;i<n;i++)
	{
		//restore original code
		for(j=0;j<n;j++)
		   for(k=0;k<n;k++)
		     B[j][k]=T[j][k];
		     
		//replace ith column with b[j]
	    for(j=0;j<n;j++)
			B[j][i]=b[j];
			
		//find x[i]	
		x[i]=determinant(B,n)/detA;
		
	}
	
	cout << "\nSolution:\n";

    for(i=0;i<n;i++)
      cout << "x" << i+1 << " = " << x[i] << endl;	   
}