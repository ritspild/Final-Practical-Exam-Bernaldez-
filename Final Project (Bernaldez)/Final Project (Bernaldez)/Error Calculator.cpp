#include <iostream>
#include <cmath>
#include <iomanip>
#include "Header.h"

using namespace std;

void ErrorCalulator() {
    int m;
    double tv = 0.1;
    double av = 0.0;
    double ae = 0.0;
    double re = 0.0;

    cout << "Solve for Summation" << endl;
    cout << "Enter a value of m: ";

    cin >> m;

    for (int i = 1; i <= m; i++) {
        av = av + pow(2, -4 * i);
    }
    av = av * 1.5;
    ae = abs(tv - av);
    re = abs(tv - av) / tv;

    cout << fixed << setprecision(8);
    cout << "\nTrue Value: " << tv;
    cout << "\nApproximate Value: " << av;
    cout << "\nAbsolute Error: " << ae;
    cout << "\nRelative Error: " << re << endl;

}