/* Toufiq Islam - 2310728141 */
//sorting array using user define function
#include <iostream>
using namespace std;

// Function to sort array
void sortArray(int a[], int n)
{
    int i, j, temp;

    for(i = 0; i < n - 1; i++)
    
        for(j = i + 1; j < n; j++)
        
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        
    
}

int main()
{
    int  n, i;//a[100],

    cout << "Enter total number of element: ";
    cin >> n;
    int a[n];
    cout << "Enter the array elements:\n";
    for(i = 0; i < n; i++)
        cin >> a[i];

    sortArray(a, n);

    cout << "\nSorted Array in ascending order : \n";
    for(i = 0; i < n; i++)
        cout << a[i] << " ";
    cout<<endl;    
    cout << "\nSorted Array in descending order : \n";
    for(i = n-1; i >= 0; i--)
        cout << a[i] << " ";    

    return 0;
}