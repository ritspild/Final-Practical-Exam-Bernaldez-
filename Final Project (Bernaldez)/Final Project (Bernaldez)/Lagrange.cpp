#include "Header.h"
#include <iostream>

#include <iomanip>
#include <conio.h>
using namespace std;

void lagrange() {
    int maxOrder; // this variable called maxOrder to store a whole number.

    cout << "Interpolation using Newton's/Lagrange Interpolating Polynomial" << endl;
    cout << "Enter max order: ";
    cin >> maxOrder; // this is cin is to aslk the user of the maximum order


    int numPoints = maxOrder + 1; // Calculates how many data points we need. For example, if order = 3, we need 4 points kay since the 0 is counted as order
    cout << "Please input (" << numPoints << ") predefined data points:" << endl; // Tells the user exactly how many data points to enter.


    double* x = new double[numPoints];
    double* y = new double[numPoints];
    // Creates two lists (arrays) in memory — one for x values, one for y values. double means they can hold decimal numbers. 



    // Input data points
    for (int i = 0; i < numPoints; i++) { //A loop that repeats for each data point (0, 1, 2... up to numPoints-1).
        cout << "Data Point " << i + 1 << ": ";
        cin >> x[i] >> y[i];
    }

    double x_input;
    cout << "\nInput value of x to approximate y: ";
    cin >> x_input;  //Asks the user for what x value do you want to find y?
    //Stores their answer in x_input.


// Calculate for each order from 1 to maxOrder using Lagrange method
    for (int order = 1; order <= maxOrder; order++) { // Loop that runs the Lagrange calculation for each order  like 1st order, 2nd order, 3rd order, and many more
        double result = 0.0;

        for (int i = 0; i <= order; i++) { //Loop through each data point
            double term = y[i]; /// Start building the term for point i. Begin with its y value.

            for (int j = 0; j <= order; j++) {  // another inner loop that goes through all other data points to build the multiplier.
                if (j != i) { // Skip when j equals i since we don't multiply a point by itself sa Lagrange.
                    term *= (x_input - x[j]) / (x[i] - x[j]); // this how we multiply term by (x_input - x[j]) / (x[i] - x[j]). 
                    //This is the core of Lagrange interpolation where it creates sa weight for each data point.
                }
            }

            result += term;
        }

        cout << fixed << setprecision(6); // sympre to show exactly 6 decimal places
        cout << "Order " << order << ": f_" << order << "(" << x_input << ") = " << result << endl; // dri na eprint ang result for each order.
    }

    // Clean up
    delete[] x;
    delete[] y;



}