/* Toufiq Islam - 2310728141 */
//determinant
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int n,i,j,k;
	double t;
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
	
	//pivot
	for(i=0;i<n;i++) //current row
	   for(k=i+1;k<n;k++)   //below the current row
	        if(abs(mat[i][i])<abs(mat[k][i])) // ii means corner term and ki means same next row same column,note dekho.
	        {
	        	for(j=0;j<n;j++)  //across all coulumn
	            {
	            	double temp=mat[i][j];
	            	mat[i][j]=mat[k][j];
	            	mat[k][j]=temp;
				}
				determinant*=-1;
			}

    cout<<"\n The matrix after pivotising =  \n";
	for(i=0;i<n;i++)
	{
	  	for(j=0;j<n;j++)
	    cout<<mat[i][j]<<" ";
		cout<<endl;  	
	}				
	        
	  //gauss
	for(i=0;i<n-1;i++) //current row
	   for(k=i+1;k<n;k++)   //below the current row
	   {
	   	 double t=mat[k][i]/mat[i][i];
	        for(j=0;j<n;j++)  //across all coulumn
	            mat[k][j]=mat[k][j]-t*mat[i][j];
	   }
	       
	cout<<"\n The matrix after gauss = \n";
	for(i=0;i<n;i++)
	{
	  	for(j=0;j<n;j++)
	    cout<<mat[i][j]<<" ";
		cout<<endl;  	
	}	
	
	for(i=0;i<n;i++) 
		determinant*=mat[i][i];	  
 cout<<"\n The required determinant is : \n";
 cout<<determinant;
 return 0;
}
