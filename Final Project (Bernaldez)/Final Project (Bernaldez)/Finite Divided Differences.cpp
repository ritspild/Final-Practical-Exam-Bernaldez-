#include <iostream>
#include <iomanip>
#include <cmath>
#include <conio.h>
#include "Header.h"

using namespace std;

void divided() {
    diff:
    int choice;


    cout << "\nNumerical Differentiation" << endl;
    cout << "Choose a Finite Divided Difference " << endl;
    cout << "[1] (x^3)(ln x)" << endl;
    cout << "[2] (e^x)(cos x)" << endl;
    cout << "[0] back" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    //Option 1
    if (choice == 1) {
        double x, h;

        cout << "Solving the derivative/slope of the curve x^3 (ln x) at" << endl;
        cout << "Input x: ";
        cin >> x;
        cout << "Input h: ";
        cin >> h;


        double function = pow(x, 3) * log(x); // This is a calculation from the numebr that you input for x, which is a formula from option 1
        // this the formulas for Finite Divided Differences
        double forward = ((pow(x + h, 3) * log(x + h)) - function) / h; //formula for forward finite
        double backward = (function - (pow(x - h, 3) * log(x - h))) / h; //formula for backward finite
        double central = ((pow(x + h, 3) * log(x + h)) - (pow(x - h, 3) * log(x - h))) / (2 * h); // this is the fomula of the central that combine the forward and backward

        // Output results with 6 decimal places
        cout << "\nDerivative / Slope" << endl;
        cout << fixed << setprecision(6);
        cout << "Forward:  " << forward << endl;
        cout << "Backward: " << backward << endl;
        cout << "Central:  " << central << endl;

      

    }
    // Option 2
    else if (choice == 2) {
        double x, h;

        cout << "Solving the derivative/slope of the curve e^x (cos x) at" << endl;
        cout << "Input x: ";
        cin >> x;
        cout << "Input h: ";
        cin >> h;


        double fx = exp(x) * cos(x); // this is the equation of the option 2 
        // Formulas for Finite Divided Differences
        double forward = ((exp(x + h) * cos(x + h)) - fx) / h; //formula for forward finite
        double backward = (fx - (exp(x - h) * cos(x - h))) / h; //formula for forward finite
        double central = ((exp(x + h) * cos(x + h)) - (exp(x - h) * cos(x - h))) / (2 * h); //formula for forward finite

        // Output results with 6 decimal places
        cout << "\nDerivative / Slope" << endl;
        cout << fixed << setprecision(6);
        cout << "Forward:  " << forward << endl;
        cout << "Backward: " << backward << endl;
        cout << "Central:  " << central << endl;

  
    }
    // if the user choose the option 3 to Exit
    else if (choice == 0) {
        return;
    }
    //error message for invalid input
    else {
        cout << "Invalid choice. Please select 1, 2, or 3." << endl;
    
        system("pause");
        goto diff;
    }






}