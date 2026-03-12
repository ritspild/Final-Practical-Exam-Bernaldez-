#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector> // Required for dynamic coefficient storage
#include "Header.h"

using namespace std;

void Secant() {

    int Poly;
    cout << "\tSecant Method" << endl;
    cout << "Input a Degree of Polynomial: ";
    cin >> Poly;

    // Use a vector to store coefficients for any degree
    vector<double> coeff(Poly + 1);

    cout << "\n\tSolving root of a coefficient" << endl;
    // Input loop: coeff[0] is for x^Poly, coeff[Poly] is constant
    for (int i = 0; i <= Poly; i++) {
        cout << "Enter a coefficient for x^" << Poly - i << ": ";
        cin >> coeff[i];
    }

    double x_min, x_pos;
    cout << "\nEnter a value of XK-Minus (X0): ";
    cin >> x_min;
    cout << "Enter a value of XK-Positive (X1): ";
    cin >> x_pos;

    // Lambda function to calculate f(x) based on coefficients
    // Uses Horner's method or simple power summation
    auto f = [&](double x) {
        double result = 0;
        for (int i = 0; i <= Poly; i++) {
            result += coeff[i] * pow(x, Poly - i);
        }
        return result;
        };

    cout << "________________________________________________________________________________________________________________" << endl;
    cout << left << setw(5) << "K"
        << setw(15) << "| Xk-1"
        << setw(15) << "| f(Xk-1)"
        << setw(15) << "| Xk"
        << setw(15) << "| f(Xk)"
        << setw(15) << "| Xk+1"
        << setw(15) << "| Error" << endl;
    cout << "________________________________________________________________________________________________________________" << endl;

    double x_plus1;
    double error = 1.0; // Initial error value
    int k = 0;
    double tolerance = 1e-6; // Stop when error is very small

    // Start Iteration Loop
    while (error > tolerance && k < 50) { // Limit iterations to 50 to prevent infinite loops

        double f_min = f(x_min);
        double f_pos = f(x_pos);

        // Check for division by zero
        if (f_pos - f_min == 0) {
            cout << "Error: Division by zero encountered. Method fails here." << endl;
            return;
        }

        // Secant Formula
        x_plus1 = x_pos - (f_pos * (x_pos - x_min)) / (f_pos - f_min);

        // Calculate approximate error
        error = fabs(x_plus1 - x_pos);

        // Print Table Row
        cout << left << setw(5) << k
            << "| " << setw(13) << x_min
            << "| " << setw(13) << f_min
            << "| " << setw(13) << x_pos
            << "| " << setw(13) << f_pos
            << "| " << setw(13) << x_plus1
            << "| " << setw(13) << error << endl;

        // Update variables for next iteration
        x_min = x_pos;
        x_pos = x_plus1;
        k++;
    }

    cout << "________________________________________________________________________________________________________________" << endl;
    cout << "\nApproximate Root found: " << x_plus1 << endl;
}