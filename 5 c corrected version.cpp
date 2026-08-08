//Toufiq Islam -2310728141
//determinant
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
	int n,i,j,k;
	cout<<"Please enter the dimension of the matrix : \n";
	cin>>n;
	double mat[n][n], determinant=1.0;
	
	cout<<"\n Please enter the matrix row wise : \n";
	for(i=0;i<n;i++)
	   for(j=0;j<n;j++)
	    cin>>mat[i][j];
	    
	cout<<"\n The matrix you have entered : \n";
	for(i=0;i<n;i++)
	{
	  	for(j=0;j<n;j++)
	    cout<<mat[i][j]<<" ";
		cout<<endl;  	
	}
	
	// GAUSS ELIMINATION WITH PIVOTING INSIDE
	for(i=0;i<n;i++) 
	{
		// 1. Pivot check for column i
		int maxRow = i;
		for(k=i+1;k<n;k++)
		{
			if(abs(mat[k][i]) > abs(mat[maxRow][i]))
				maxRow = k;
		}

		// 2. Swap rows if needed
		if(maxRow != i)
		{
			for(j=0;j<n;j++)
			{
				double temp = mat[i][j];
				mat[i][j] = mat[maxRow][j];
				mat[maxRow][j] = temp;
			}
			determinant *= -1.0;
		}

		// 3. If pivot is 0, whole column is zero -> det = 0
		if(abs(mat[i][i]) < 1e-9)
		{
			determinant = 0.0;
			break;
		}

		// 4. Eliminate rows below
		for(k=i+1;k<n;k++)
		{
			double t = mat[k][i] / mat[i][i];
			for(j=i;j<n;j++)
				mat[k][j] -= t * mat[i][j];  //mat[k][j] = mat[k][j]- t * mat[i][j];
		}
	}
	       
	cout<<"\n The matrix after gauss = \n";
	for(i=0;i<n;i++)
	{
	  	for(j=0;j<n;j++)
	    cout<<mat[i][j]<<" ";
		cout<<endl;  	
	}	
	
	if(determinant != 0.0)
	{
		for(i=0;i<n;i++) 
			determinant *= mat[i][i];	  
	}

	cout<<"\n The required determinant is : \n";
	cout<<determinant;

	return 0;
}