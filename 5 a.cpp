///* Toufiq Islam - 2310728141 */
//Find the dominant eigenvalue and corresponding eigenvector
//Assuming that the matrix has dominant eigenvalue
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    cout.precision(4);
    cout.setf(ios::fixed);
    int n,i,j;
    cout<<"\nEnter the order of the matrix:\n";        //Get the order of the square matrix
    cin>>n;
    double a[n][n],b[n],c[n],k,eps,y;            //declare arrays and other variables to be used
    
    
    cout<<"\nEnter the elements of matrix row-wise:\n";
    for (i=0;i<n;i++)                    //Get the elements of the matrix
        for (j=0;j<n;j++)
            cin>>a[i][j];
    
	cout<<"\nEnter the initial guess for the eigen-vector:\n";
    for (j=0;j<n;j++)                    //Get the iinitial guess for the eigen vector
        cin>>b[j];
   
    cout<<"\nEnter the accuracy desired:\n";       
    cin>>eps;
    k=b[0];                            //Assign some initial value to the eigen value, 'k'
  	do
    {
        y=k;           
        for (i=0;i<n;i++)                //Calculate axb where a is the matrix and b its eigen vector
        {   
            c[i]=0;
            for (j=0;j<n;j++)
                c[i]=c[i]+a[i][j]*b[j];        //After all the iterations axb=c
        }
        k=c[0];
        for (i=1;i<n;i++)
        {
        	if(abs(k)<abs(c[i]))
        		k=c[i];  //Find the largest element of c and assign it to k where k is the eigen value
		}
        for (i=0;i<n;i++)
            b[i]=c[i]/k;                //Calculate the new Eigen Vector
    }while(abs(k-y)>=eps);                
    cout<<"\n\nThe largest Eigenvalue is: "<<k<<endl;
    cout<<"\nAnd the corresponding Eigenvector is: \n";
    for (i=0;i<n;i++)
        cout<<b[i]<<endl;
    cout<<"\n";   
    return 0;
}