#include <iostream>
#include <iomanip>
#include <cmath>
#include <conio.h>
#include "Header.h"


using namespace std;

void first() {

    int choice;
main:
    cout << "\nDifferential Equations Calculator (4th Order Runge-Kutta)" << endl;
    cout << "Choose an ODE to Solve" << endl;
    cout << "[1] dy/dx = y + x" << endl;
    cout << "[2] dy/dx = y + x^2 + 2" << endl;
    cout << "[0] back" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    // Option 1: Solving dy/dx = y + x
    if (choice == 1) {
        double x, y, target_x;

        cout << "\nSolving the ODE dy/dx = y + x" << endl;
        cout << "Input an initial value of x: ";
        cin >> x;
        cout << "Input an initial value of y: ";
        cin >> y;
        cout << "Input a value of find y at x: ";
        cin >> target_x;

        // calculate h 
        double h = target_x - x;

        // runge-Kutta 4th Order Calculation
        // using the calculated h
        double k1 = h * (y + x);  // first order
        double k2 = h * ((y + k1 / 2) + (x + h / 2)); // second order
        double k3 = h * ((y + k2 / 2) + (x + h / 2)); // third order
        double k4 = h * ((y + k3) + (x + h)); // fourth order

        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6; // final formula to get the target y 

        cout << "\nResult:" << endl;
        cout << fixed << setprecision(6);
        cout << "y(" << target_x + h << ") = " << y << endl;

     
    }
    // Option 2: Solving dy/dx = y + x^2 + 2
    else if (choice == 2) {
        double x, y, target_x;

        cout << "\nSolving the ODE dy/dx = y + x^2 + 2" << endl;
        cout << "Input an initial value of x: ";
        cin >> x;
        cout << "Input an initial value of y: ";
        cin >> y;
        cout << "Input a value of find y at x: ";
        cin >> target_x;

        // calculate h 
        double h = target_x - x;

        // runge-Kutta 4th Order Calculation
        double k1 = h * (y + x * x + 2); //first order
        double k2 = h * ((y + k1 / 2) + pow(x + h / 2, 2) + 2); // second order
        double k3 = h * ((y + k2 / 2) + pow(x + h / 2, 2) + 2); // third order
        double k4 = h * ((y + k3) + pow(x + h, 2) + 2); // fourth order 

        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6; // final formula to get the target y

        cout << "\nResult:" << endl;
        cout << fixed << setprecision(6);
        cout << "y(" << target_x + h << ") = " << y << endl;

  
    }
    // Option 3: Exit
    else if (choice == 0) {
        cout << "Exiting the program. Goodbye!" << endl;
    }
    // Error handling
    else {
        cout << "Invalid choice. Please select 1, 2, or 3." << endl;
        system("cls");
        return ;
      
    }


}