/* Toufiq Islam - 2310728141 */
//sorting array using user-define function
#include<iostream>
using namespace std;

// User-defined function to sort array in ascending order
void sortArray(int a[], int n)
{
    int i, j, temp;
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main()
{
    long long n, temp;
    int a[20], i = 0, j;

    cout << "Enter a number: ";
    cin >> n;

    temp = n;


    // Store digits into array
    while(temp > 0)
    {
        a[i] = temp % 10;
        temp = temp / 10;
        i++;
    }

    // Sort digits in ascending order using user-defined function
    sortArray(a, i);

    cout << "\nLargest number: ";
    for(j = i - 1; j >= 0; j--)
        cout << a[j];
    
    
    // Find first non-zero digit index
    int nonZeroIndex = 0;
    for(j = 0; j < i; j++)
    {
        if(a[j] != 0)
        {
            nonZeroIndex = j;
            break;
        }
    }
  


    // Swap first element with first non-zero element
    swap(a[0], a[nonZeroIndex]);

    cout << "\nSmallest number: ";
    for(j = 0; j < i; j++)
        cout << a[j];

    return 0;
}