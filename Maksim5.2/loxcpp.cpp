#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void FindSum(double x, double eps, int& n, double& S);
void GetA(double x, double n, double& a);

int main() {
    double xp, xk, x, dx, eps, a, R, S;
    int n;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-----------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
        << setw(10) << "cos(x)" << " |"
        << setw(10) << "S" << " |"
        << setw(5) << "n" << " |" << endl;
    cout << "-----------------------------------------" << endl;

    x = xp;
    while (x <= xk) {

        FindSum(x, eps, n, S);
        cout << "|" << setw(7) << setprecision(2) << x << " |"
            << setw(10) << setprecision(5) << cos(x) << " |"
            << setw(10) << setprecision(5) << S << " |"
            << setw(5) << n << " |" << endl;

        x += dx;
    }
    cout << "-----------------------------------------" << endl;
    return 0;
}

void FindSum(double x, double eps, int& n, double& S) {
    n = 0;
    double a = 1;
    S = a;

    do {
        n++;
        GetA(x, n, a);
        S += a;
    } while (fabs(a) >= eps);
}

void GetA(double x, double n, double& a) {
    double R = -(x * x) / ((2 * n) * (2 * n - 1));
    a *= R;
}
