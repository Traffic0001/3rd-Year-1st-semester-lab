//Toufiq Islam -2310728141
//minimum distance and maximum distance
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double disfun(double xl, double yl, double xr, double yr) 
{
    double xd = xl - xr;
    double yd = yl - yr;
    return sqrt(xd * xd + yd * yd);
}

int main()
{
    int i, j, n;
    cout << "\nEnter the number of points\n";
    cin >> n;
    
    if (n < 2)
    {
        cout << "\nThere should be at least two points\n";
        return 0;
    }

    double a[100][2]; // Fixed size so memory doesn't break
    cout << "\nEnter the points row-wise\n";
    for (i = 0; i < n; i++)
        for (j = 0; j < 2; j++)
            cin >> a[i][j]; 
    
    // First distance as starting point for min and max
    double min_d = disfun(a[0][0], a[0][1], a[1][0], a[1][1]);
    double max_d = min_d;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        { 
            double d = disfun(a[i][0], a[i][1], a[j][0], a[j][1]);
            
            
            cout << "P" << i+1 << " - P" << j+1<< " = " << d << endl;
            
            if (d < min_d) min_d = d;
            if (d > max_d) max_d = d;
        }
    }

    cout << "\nThe smallest distance is: " << min_d << endl;
    cout << "The largest distance is:  " << max_d << endl;

    return 0;
}