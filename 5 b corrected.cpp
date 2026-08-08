// Toufiq Islam -2310728141
// Inverse Matrix using Gauss-Jordan with Partial Pivoting
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int n, i, j, k;
    cout << fixed << setprecision(4);

    cout << "Enter the order of the matrix: ";
    cin >> n;

    // Augmented matrix of size n x 2n
    double mat[n][2 * n];

    cout << "\nEnter the elements of matrix row-wise:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cin >> mat[i][j];

        // Augment with Identity Matrix [A | I]
        for (j = n; j < 2 * n; j++)
            mat[i][j] = (i == (j - n)) ? 1.0 : 0.0;
    }

    // GAUSS-JORDAN WITH PARTIAL PIVOTING
    for (i = 0; i < n; i++)
    {
        // 1. Partial Pivoting: find row with largest absolute element in column i
        int maxRow = i;
        for (k = i + 1; k < n; k++)
        {
            if (abs(mat[k][i]) > abs(mat[maxRow][i]))
                maxRow = k;
        }

        // 2. Swap rows across all 2n columns
        if (maxRow != i)
        {
            for (j = 0; j < 2 * n; j++)
            {
                double temp = mat[i][j];
                mat[i][j] = mat[maxRow][j];
                mat[maxRow][j] = temp;
            }
        }

        // 3. Singularity Check: if pivot is zero, inverse does not exist
        if (abs(mat[i][i]) < 1e-9)
        {
            cout << "\nMatrix is singular! Inverse does not exist.\n";
            return 0;
        }

        // 4. Normalize pivot row so pivot element becomes 1
        double pivot = mat[i][i];
        for (j = 0; j < 2 * n; j++)
            mat[i][j] /= pivot;

        // 5. Eliminate column i in ALL OTHER rows (k != i)
        for (k = 0; k < n; k++)
        {
            if (k != i)
            {
                double factor = mat[k][i];
                for (j = 0; j < 2 * n; j++)
                    mat[k][j] -= factor * mat[i][j];
            }
        }
    }

    // Display the inverse matrix (stored in columns n to 2n-1)
    cout << "\nThe Inverse Matrix (A^-1) is:\n";
    for (i = 0; i < n; i++)
    {
        for (j = n; j < 2 * n; j++)
            cout << setw(10) << mat[i][j] << " ";
        cout << endl;
    }

    return 0;
}