#include <iostream>
#include <cmath>

using namespace std;

void solveCubic(double a, double b, double c, double d)
 {
    if (a == 0) 
	{
        cout << "Not a cubic equation!\n";
        return;
    }

    // Convert to depressed cubic: t^3 + p*t + q = 0
    double shift = b / (3.0 * a);
    double p = (3.0 * a * c - b * b) / (3.0 * a * a);
    double q = (2.0 * b * b * b - 9.0 * a * b * c + 27.0 * a * a * d) / (27.0 * a * a * a);
    
    // Discriminant
    double D = (q * q) / 4.0 + (p * p * p) / 27.0;
    if (abs(D) < 1e-11) D = 0; // Fix floating-point precision error

    // Case 1: One real root, two complex roots
    if (D > 0) {
        double u = cbrt(-q / 2.0 + sqrt(D));
        double v = cbrt(-q / 2.0 - sqrt(D));
        
        double realPart = -(u + v) / 2.0 - shift;
        double imagPart = abs(u - v) * sqrt(3.0) / 2.0;

        cout << "Root 1: " << (u + v) - shift << "\n";
        cout << "Root 2: " << realPart << " + " << imagPart << "i\n";
        cout << "Root 3: " << realPart << " - " << imagPart << "i\n";
    } 
    // Case 2: Real roots with duplicates
    else if (D == 0) {
        double u = cbrt(-q / 2.0);
        cout << "Root 1: " << 2 * u - shift << "\n";
        cout << "Root 2: " << -u - shift << "\n";
        cout << "Root 3: " << -u - shift << "\n";
    } 
    // Case 3: Three distinct real roots
    else {
        double PI = acos(-1.0);
        double r = sqrt(-p * p * p / 27.0);
        double phi = acos(-q / (2.0 * r));
        double f = 2.0 * sqrt(-p / 3.0);

        cout << "Root 1: " << f * cos(phi / 3.0) - shift << "\n";
        cout << "Root 2: " << f * cos((phi + 2 * PI) / 3.0) - shift << "\n";
        cout << "Root 3: " << f * cos((phi + 4 * PI) / 3.0) - shift << "\n";
    }
}

int main() 
{
    double a, b, c, d;
    cout << "Enter coefficients (a b c d): ";
    if (cin >> a >> b >> c >> d)
	{
        solveCubic(a, b, c, d);
    }
    return 0;
}