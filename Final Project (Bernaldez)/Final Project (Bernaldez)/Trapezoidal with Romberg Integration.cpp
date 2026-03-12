#include "Header.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <conio.h>
using namespace std;

// this is the formula of function 1: x^3
double f1(double x) {
    return x * x * x;
}

// this is the formula of function 2: (e^x)(ln x)
double f2(double x) {
    return exp(x) * log(x);
}

// Trapezoidal rule
double trapezoidal(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n; // formula of the h that calculates the width of each trapezoid. 
    double sum = (f(a) + f(b)) / 2; // formula that starts the sum with the first and last points. The formula divides them by 2 because they're only used once.

    for (int i = 1; i < n; i++) {  //Gi-add ang tanan middle points.
        //Ang matag middle point kay gi - share sa duha ka trapezoid, mao nga full gyud siya i - count(dili na siya i - divide by 2).
        sum += f(a + i * h);
    }

    return sum * h;
}

// Romberg method
double romberg(double (*f)(double), double a, double b, int maxK) {
    double r[10][10] = { 0 }; // Naghimo og 10×10 nga table nga puno og zero.

    // First approximation
    r[0][0] = trapezoidal(f, a, b, 1);

    cout << "\nRomberg Iterations:" << endl;
    cout << "k\tR(k,0)" << endl;
    cout << "0\t" << r[0][0] << endl;

    for (int k = 1; k <= maxK; k++) {  //Loop that runs from k=1 up to maxK. Each k doubles the number of trapezoids
        // Trapezoidal with 2^k intervals
        r[k][0] = trapezoidal(f, a, b, pow(2, k)); // Calculates a new trapezoidal estimate using 2^k trapezoids:

        cout << k << "\t" << r[k][0];

        // loop for fomula of Richardson extrapolation
        for (int j = 1; j <= k; j++) {
            r[k][j] = r[k][j - 1] + (r[k][j - 1] - r[k - 1][j - 1]) / (pow(4, j) - 1);
        }

        // Show convergence at this k
        cout << " - Converged at k = " << k << endl;
    }

    return r[maxK][maxK];
}

void Trapezoidal() {
    int choice, maxK;
    double lower, upper;

    cout << "Definite Integral Calculator (Trapezoidal with Romberg Method)" << endl;

    cout << "Select function to integrate:" << endl;
    cout << "[1] x^3" << endl;
    cout << "[2] (e^x)(ln x)" << endl;
    cout << "\nEnter your choice : ";
    cin >> choice;

    if (choice == 1) {
        cout << "\nSolving the area under the curve x^3" << endl;
        cout << "Enter lower limit: ";
        cin >> lower;
        cout << "Enter upper limit: ";
        cin >> upper;
        cout << "Enter maximum k value: ";
        cin >> maxK;

        double result = romberg(f1, lower, upper, maxK);
        cout << "\nIntegral/Area converged at k = " << maxK << endl;
        cout << "Area = " << fixed << setprecision(0) << result << " sq. units" << endl;
    }
    else if (choice == 2) {
        cout << "\nSolving the area under the curve (e^x)(ln x)" << endl;
        cout << "Enter lower limit: ";
        cin >> lower;
        cout << "Enter upper limit: ";
        cin >> upper;
        cout << "Enter maximum k value: ";
        cin >> maxK;

        double result = romberg(f2, lower, upper, maxK);
        cout << "\nIntegral/Area converged at k = " << maxK << endl;
        cout << "\nArea = " << fixed << setprecision(6) << result << " sq. units" << endl;
    }
    else {
        cout << "Invalid choice! Please run the program again." << endl;
    }


}