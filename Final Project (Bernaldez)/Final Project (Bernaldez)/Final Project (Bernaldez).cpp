#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cmath>
#include <math.h>
#include "Header.h"

using namespace std;

int main() {

    // Initialize option to -1 so it doesn't accidentally trigger case 0 (Exit)
    int option = -1;

back:
    cout << "NUMERICAL METHOD" << endl;
    cout << "\n\nMain Menu" << endl;
    cout << "[1] Error Calculator " << endl;
    cout << "[2] Root Calculator " << endl;
    cout << "[3] System of Linear Equation Calculation " << endl;
    cout << "[4] Interpolation " << endl;
    cout << "[5] Integral " << endl;
    cout << "[6] Derivative" << endl;
    cout << "[7] Differential Equations" << endl;

    cout << "\n[9] About" << endl;
    cout << "[0] Exit" << endl;

    cout << "Select Option: ";
    cin >> option;

    // Check if the input was a letter or invalid character
    if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(1000, '\n'); // Discard the invalid input
        option = -1; // Set option to a value that will trigger the 'default' case
    }

    system("cls");

    switch (option) {
    case 1: {
    error:
        cout << "Main Menu < Error Calculator " << endl;
  
        ErrorCalulator();
        cout << "\nPress <R> to enter another value .";
        cout << "\nPress <Enter> to go back to main menu.";

        char Error = _getch();
        if (Error == 13) {
            system("cls");
            main();
        }
        else if (Error == 'r' || Error == 'R') {
            system("cls");
            goto error;
        }
        else {
            cout << "\nIncorrect choice. Please try again!\n";
            system("pause");
            system("cls");
            goto error;
        }

        break;
    }
    case 2: {
    root:
        cout << "Main Menu < Root Calculator " << endl;
   

        // FIX: Change 'int' to 'char' so it can accept 'A' or 'B'
        char choice;

        cout << "\n\n[A] Secant Method" << endl;
        cout << "[B] Bisection Method" << endl;
        cout << "[0] Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        system("cls");

        if (choice == 'a' || choice == 'A') {
            cout << "Main Menu < Root Calculator < Secant Method" << endl;

        secant:
            Secant();
            cout << "\n\nPress <R> to enter another value .";
            cout << "\nPress <B> to go back to root calculation menu.";
            cout << "\nPress <Enter> to go back to main menu.";

            char Error = _getch();
            if (Error == 13) {
                system("cls");
                main();
            }
            else if (Error == 'r' || Error == 'R') {
                system("cls");
                goto secant;
            }
            else if (Error == 'b' || Error == 'B') {
                system("cls");
                goto root;
            }
            else {
                cout << "\nIncorrect choice. Please try again!\n";
                system("pause");
                system("cls");
                goto secant;
            }
        }
        else if (choice == 'b' || choice == 'B') {
            cout << "Main Menu < Root Calculator < Bisection Method" << endl;

        bisection:
            Bisection();

            cout << "\n\nPress <R> to enter another value .";
            cout << "\nPress <B> to go back to root calculation menu.";
            cout << "\nPress <Enter> to go back to main menu.";

            char Error = _getch();
            if (Error == 13) {
                system("cls");
                main();
            }
            else if (Error == 'r' || Error == 'R') {
                system("cls");
                goto bisection;
            }
            else if (Error == 'b' || Error == 'B') {
                system("cls");
                goto root;
            }
            else {
                cout << "\nIncorrect choice. Please try again!\n";
                system("pause");
                system("cls");
                goto bisection;
            }

        }
        else if (choice == '0') { // Compare char '0', not int 0
            system("cls");
            main();

        }
        else {
            cout << "\nIncorrect choice. Please try again!\n";
            system("pause");
            system("cls");
            goto root;

        }

        break;
    }
    case 3: {
    System:
        cout << "Main Menu < System of Linear Equation Calculation " << endl;
       
        char choice;

        cout << "\n\n[A] Gaussian Method" << endl;
        cout << "[B] Gauss-Seidel" << endl;
        cout << "[C] Jacobi" << endl;
        cout << "[0] Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        system("cls");

        if (choice == 'a' || choice == 'A') {
            cout << "Main Menu < System of Linear Equation Calculation < Gaussian Method" << endl;
            
            GaussianMethod:
            GaussianMethod();
            cout << "\n\nPress <R> to enter another value .";
            cout << "\nPress <B> to go back to System of Linear Equation Calculation menu.";
            cout << "\nPress <Enter> to go back to main menu.";

            char Error = _getch();
            if (Error == 13) {
                system("cls");
                main();
            }
            else if (Error == 'r' || Error == 'R') {
                system("cls");
                goto GaussianMethod;
            }
            else if (Error == 'b' || Error == 'B') {
                system("cls");
                goto System;
            }
            else {
                cout << "\nIncorrect choice. Please try again!\n";
                system("pause");
                system("cls");
                goto GaussianMethod;
            }
        }
        else if (choice == 'b' || choice == 'B') {
            cout << "Main Menu < System of Linear Equation Calculation < Gauss-Seidel" << endl;
            GaussSeidel();
            GaussSeidel:
           

            cout << "\n\nPress <R> to enter another value .";
            cout << "\nPress <B> to go back to System of Linear Equation Calculation menu.";
            cout << "\nPress <Enter> to go back to main menu.";

            char Error = _getch();
            if (Error == 13) {
                system("cls");
                main();
            }
            else if (Error == 'r' || Error == 'R') {
                system("cls");
                goto GaussSeidel;
            }
            else if (Error == 'b' || Error == 'B') {
                system("cls");
                goto System;
            }
            else {
                cout << "\nIncorrect choice. Please try again!\n";
                system("pause");
                system("cls");
                goto GaussSeidel;
            }

        }
        else if (choice == 'c' || choice == 'C') {
            cout << "Main Menu < System of Linear Equation Calculation < Jacobi" << endl;
           
        Jacobi:
            Jacobi();

            cout << "\n\nPress <R> to enter another value .";
            cout << "\nPress <B> to go back to System of Linear Equation Calculation menu.";
            cout << "\nPress <Enter> to go back to main menu.";

            char Error = _getch();
            if (Error == 13) {
                system("cls");
                main();
            }
            else if (Error == 'r' || Error == 'R') {
                system("cls");
                goto Jacobi;
            }
            else if (Error == 'b' || Error == 'B') {
                system("cls");
                goto System;
            }
            else {
                cout << "\nIncorrect choice. Please try again!\n";
                system("pause");
                system("cls");
                goto Jacobi;
            }

        }
        else if (choice == '0') {
            system("cls");
            main();

        }
        else {
            cout << "\nIncorrect choice. Please try again!\n";
            system("pause");
            system("cls");
            goto System;

        }

        break;
    }
    case 4: {
    Interpolation:
        cout << "Main Menu < Interpolation " << endl;
        char choice;
      
        cout << "\n\n[A] Lagrange/Newton’s Interpolation" << endl;
        cout << "[0] Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        system("cls");

        if (choice == 'a' || choice == 'A') {

            cout << "Main Menu < Interpolation < Lagrange/Newton’s Interpolation" << endl;
           
        Lagrange:
            lagrange();
            cout << "\n\nPress <R> to enter another value .";
            cout << "\nPress <B> to go back to Lagrange/Newton’s Interpolation menu.";
            cout << "\nPress <Enter> to go back to main menu.";

            char Error = _getch();
            if (Error == 13) {
                system("cls");
                main();
            }
            else if (Error == 'r' || Error == 'R') {
                system("cls");
                goto Lagrange;
            }
            else if (Error == 'b' || Error == 'B') {
                system("cls");
                goto Interpolation;
            }
            else {
                cout << "\nIncorrect choice. Please try again!\n";
                system("pause");
                system("cls");
                goto Lagrange;
            }
        }
        else if (choice == '0') { 
            system("cls");
            main();

        }
        else {
            cout << "\nIncorrect choice. Please try again!\n";
            system("pause");
            system("cls");
            goto Interpolation;

        }

        break;
    }
    case 5: {
        Definite:

        cout << "Main Menu < Definite  Integral " << endl;

        char choice;

        cout << "\n\n[A] Trapezoidal with Romberg Integration" << endl;
        cout << "[0] Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        system("cls");

        if (choice == 'a' || choice == 'A') {
            cout << "Main Menu < Definite Integral < Trapezoidal with Romberg Integration" << endl;
            
        Trapezoidal:
            Trapezoidal();
            cout << "\n\nPress <R> to enter another value .";
            cout << "\nPress <B> to go back to Trapezoidal with Romberg Integration menu.";
            cout << "\nPress <Enter> to go back to main menu.";

            char Error = _getch();
            if (Error == 13) {
                system("cls");
                main();
            }
            else if (Error == 'r' || Error == 'R') {
                system("cls");
                goto Trapezoidal;
            }
            else if (Error == 'b' || Error == 'B') {
                system("cls");
                goto Definite;
            }
            else {
                cout << "\nIncorrect choice. Please try again!\n";
                system("pause");
                system("cls");
                goto Trapezoidal;
            }
        }
        else if (choice == '0') {
            system("cls");
            main();

        }
        else {
            cout << "\nIncorrect choice. Please try again!\n";
            system("pause");
            system("cls");
            goto Definite;

        }

        break;
    }
    case 6: {
        Derivative:
        cout << "Main Menu < Definite Derivative " << endl;


        char choice;

        cout << "\n\n[A] Finite Divided Differences" << endl;
        cout << "[0] Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        system("cls");

        if (choice == 'a' || choice == 'A') {
            cout << "Main Menu < Definite Derivative < Finite Divided Differences" << endl;
            
        Finite:
            divided();
            cout << "\n\nPress <R> to enter another value .";
            cout << "\nPress <B> to go back to Definite Derivative menu.";
            cout << "\nPress <Enter> to go back to main menu.";

            char Error = _getch();
            if (Error == 13) {
                system("cls");
                main();
            }
            else if (Error == 'r' || Error == 'R') {
                system("cls");
                goto Finite;
            }
            else if (Error == 'b' || Error == 'B') {
                system("cls");
                goto Derivative;
            }
            else {
                cout << "\nIncorrect choice. Please try again!\n";
                system("pause");
                system("cls");
                goto Finite;
            }
        }
        else if (choice == '0') {
            system("cls");
            main();

        }
        else {
            cout << "\nIncorrect choice. Please try again!\n";
            system("pause");
            system("cls");
            goto Derivative;

        }
        break;
    }
    case 7: {
        Differential:
        cout << "Main Menu < Differential Equations " << endl;
        char choice;

        cout << "\n\n[A] First Order ODE (4th Order Runge-Kutta)" << endl;
        cout << "[0] Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        system("cls");

        if (choice == 'a' || choice == 'A') {
            cout << "Main Menu < Differential Equations < First Order ODE (4th Order Runge-Kutta)" << endl;
            
        First:
            first();
            cout << "\n\nPress <R> to enter another value .";
            cout << "\nPress <B> to go back to Differential Equations menu.";
            cout << "\nPress <Enter> to go back to main menu.";

            char Error = _getch();
            if (Error == 13) {
                system("cls");
                main();
            }
            else if (Error == 'r' || Error == 'R') {
                system("cls");
                goto First;
            }
            else if (Error == 'b' || Error == 'B') {
                system("cls");
                goto Differential;
            }
            else {
                cout << "\nIncorrect choice. Please try again!\n";
                system("pause");
                system("cls");
                goto First;
            }
        }
        else if (choice == '0') {
            system("cls");
            main();

        }
        else {
            cout << "\nIncorrect choice. Please try again!\n";
            system("pause");
            system("cls");
            goto Differential;

        }


        break;
    }
    case 9: {
    about:
        cout << "Main Menu < About " << endl;
        cout << "\n\n " << setw(50) << "A Program Presented to the faculty of the" << endl;
        cout << setw(45) << "College of Engineering Education" << endl;
        cout << setw(40) << "University of Mindanao" << endl;
        cout << setw(35) << "Davao city" << endl;
        cout << "\n\n " << setw(50) << "In partial Fulfillment of the Requirement in" << endl;
        cout << setw(45) << "CPE 222 - Numerical Methods" << endl;
        cout << "\n\n " << setw(45) << "Develop by Richfield Bernaldez" << endl;
        cout << setw(40) << "BS Computer Engineer" << endl;
        cout << setw(40) << "Course Code: 11764" << endl;

        cout << "\n\n\nPress <Enter> to go bak to main menu.";

        char about = _getch();
        if (about == 13) {
            system("cls");
            main();
        }
        else {
            cout << "\nIncorrect choice. Please try again!\n";
            system("pause");
            system("cls");
            goto about;
        }

        break;
    }
    case 0: {
        cout << "Main Menu < Exit " << endl;
        cout << "\n\nAre you sure you want to exit?" << endl;
        cout << "Press [Y] to Exit , Press [N] to go back to Main Menu " << endl;
        char key = _getch();
        if (key == 'y' || key == 'Y') {
            system("cls");
            exit(0);
        }
        else if (key == 'n' || key == 'N') {
            system("cls");
            main();
        }
        else {
            cout << "\nIncorrect choice. Please try again!\n";
            system("pause");
            system("cls");
            goto back;
        }
        break;
    }

    default: {
        cout << "Oops! That option isn't on the menu. Please try again." << endl;
        system("pause");
        system("cls");
        goto back;
    }

    }
    
}