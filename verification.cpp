//testing 
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
  int i,j,k,n;
  
  cout<<"Enter the dimension \n";
  cin>>n;
  
  double mat[n][2*n],ori[n][n],in[n][n],u[n][n];
  cout<<"Enter row wise :\n";
  
  for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{
    	  cin>>mat[i][j];
    	  ori[i][j]=mat[i][j];	
		}

		for(j=n;j<2*n;j++)
		   mat[i][j]=(i==(j-n))? 1.0:0.0;
	}
    cout<<"Given matrix :\n";
	 for(i=0;i<n;i++)
	 {
	 	for(j=0;j<n;j++)
	 	   cout<<setw(10)<<ori[i][j];
	 	 cout<<endl;  
	 }
	  
   //pivot gauss
   for(i=0;i<n;i++)
    {
    	int maxRow=i;
    	for(k=i+1;k<n;k++)
    	 {
    	 	if(abs(mat[k][i])>(abs(mat[maxRow][i])))
    	 	maxRow=k;
		 }
		 
		if(maxRow != i)
		{
		  for(j=0;j<2*n;j++)
		  {
		    double temp =mat[i][j];
			mat[i][j]=mat[maxRow][j];
			mat[maxRow][j]=temp;
				
		  }	
		}
	  if(abs(mat[i][i])<1e-10)
	  {
	    cout<<"No inverse :";
		return 0;	
	  }	
	  
	 double pivot=mat[i][i];
	 for(j=0;j<2*n;j++)
	   mat[i][j]/=pivot;
	   
	for(k=0;k<n;k++)
	  {
	 	if(k != i)
	 	 {
	 	     double factor=mat[k][i];
			 for(j=0;j<2*n;j++)
			   mat[k][j] -= factor*mat[i][j];
		 }
	  } 
	}
	
	cout<<"Inverse matrix :\n";
	for(i=0;i<n;i++)
	{
	  for(j=n;j<2*n;j++)
	    {
	      cout<<setw(10)<<mat[i][j]<<" ";
	      in[i][j-n]=mat[i][j];
		}
		cout<<endl;
	}
	
	//verify
	for(i=0;i<n;i++)
	  {
	   	for(j=0;j<n;j++)
	   	   {
	   	     u[i][j]=0.0;
				for(k=0;k<n;k++)
				  u[i][j] +=ori[i][k]*in[k][j];	
		   }
	  }
	  
	 cout<<"Verified matrix :\n";
	 for(i=0;i<n;i++)
	 {
	 	for(j=0;j<n;j++)
	 	   cout<<setw(10)<<in[i][j];
	 	 cout<<endl;  
	 }
	  
	  
	
}