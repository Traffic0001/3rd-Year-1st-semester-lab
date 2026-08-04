/* Toufiq Islam - 2310728141 */
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

    // Sort digits
    sortArray(a, i);

    // Largest number
    cout << "\nLargest number: ";

    for(j = i - 1; j >= 0; j--)
        cout << a[j];

    cout << endl;

    // Smallest number
 if(a[0] == 0)
   {
       for(j = 1; j < i; j++)
       {
          if(a[j] != 0)
          {
             // Manual swap
             int t = a[0];
             a[0] = a[j];
             a[j] = t;
             break;
          }
        }
   }

    cout << "\nSmallest number: ";
	for(j = 0; j < i; j++)
        cout << a[j];


    return 0;
}