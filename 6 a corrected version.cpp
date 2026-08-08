/*Toufiq Islam - 2310728141 */
//solving system of equation using gauss
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
	int n,i,j,k;
	cout<<"Please enter the dimension of the matrix : \n";
	cin>>n;
	double mat[n][n+1],x[n];
	
	cout<<"\n Please enter the augmented matrix row wise : \n";
	for(i=0;i<n;i++)
	   for(j=0;j<=n;j++)
	    cin>>mat[i][j];
	    
	cout<<"\n The matrix you have entered : \n";
	for(i=0;i<n;i++)
	{
	  	for(j=0;j<=n;j++)
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
			for(j=0;j<=n;j++)
			{
				double temp = mat[i][j];
				mat[i][j] = mat[maxRow][j];
				mat[maxRow][j] = temp;
			}
			//determinant *= -1.0; no need here
		}

		// 3. If pivot is 0, whole column is zero -> det = 0
		if(abs(mat[i][i]) < 1e-9)
		{
			cout<<"\nNo unique solution\n";
			return 0;
		}

		// 4. Eliminate rows below
		for(k=i+1;k<n;k++)
		{
			double t = mat[k][i] / mat[i][i];
			    for(j=i;j<=n;j++)
				   mat[k][j] -= t * mat[i][j];
		}
	}
	       
	cout<<"\n The matrix after gauss = \n";
	for(i=0;i<n;i++)
	{
	  	for(j=0;j<=n;j++)
	    cout<<mat[i][j]<<" ";
		cout<<endl;  	
	}	
	
	
	//back substitution
	for(i=n-1;i>=0;i--)
	{
		if(fabs(mat[i][i])<1e-9)
		{
			cout<<"\nNo unique Solution : \n";
			return 0; //better use return 0;
		}
		else
		{
			x[i]=mat[i][n];
			   for(j=i+1;j<n;j++)
			    x[i]=x[i]-mat[i][j]*x[j]; //ith rows all i-j column I mean all column after (i,i)th corner.
			    
			x[i]=x[i]/mat[i][i] ; //devide coefficient that alreay attached with variable like ax2=d -> x2=d/a;   
		}
	}
	
	
	cout<<"The values of the variables are as : \n";
    for(i=0;i<n;i++)
	   cout<<x[i]<<endl;

	return 0;
}