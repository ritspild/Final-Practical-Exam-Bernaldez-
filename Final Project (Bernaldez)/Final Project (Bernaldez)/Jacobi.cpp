#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <thread>
#include "Header.h"

using namespace std;


void Jacobi() {
    int choice;
    const double TOLERANCE = 0.00001;
    const int MAX_ITERATIONS = 100;

    do {

        cout << "\n=====================================" << endl;
        cout << "         JACOBI METHOD" << endl;
        cout << "=====================================" << endl;
        cout << "[1] 2 Equations 2 Unknowns" << endl;
        cout << "[2] 3 Equations 3 Unknowns" << endl;
        cout << "[3] 4 Equations 4 Unknowns" << endl;
        cout << "[4] 5 Equations 5 Unknowns" << endl;
        cout << "[0] back" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "=====================================" << endl;
        system("cls");



        if (choice == 0) {
            return;
        }


        if (choice < 1 || choice > 4) {
            cout << "Invalid choice! Please try again." << endl;
            continue;
        }


        int n = choice + 1;

        cout << "\n" << n << " Equations " << n << " Unknowns" << endl;


        double matrix[5][6] = { 0 };


        for (int i = 0; i < n; i++) {
            cout << "Equation " << i + 1 << " (";
            for (int j = 0; j < n; j++) {
                char var;
                if (j == 0) var = 'x';
                else if (j == 1) var = 'y';
                else if (j == 2) var = 'z';
                else if (j == 3) var = 'w';
                else var = 'v';

                cout << var;
                if (j < n - 1) cout << " + ";
            }
            cout << " = constant): ";


            for (int j = 0; j < n + 1; j++) {
                cin >> matrix[i][j];
            }
        }


     


        for (int i = 0; i < n; i++) {
            int maxRow = i;
            double maxVal = fabs(matrix[i][i]);

            for (int k = i + 1; k < n; k++) {
                if (fabs(matrix[k][i]) > maxVal) {
                    maxVal = fabs(matrix[k][i]);
                    maxRow = k;
                }
            }

            if (maxRow != i) {
                for (int j = 0; j < n + 1; j++) {
                    swap(matrix[i][j], matrix[maxRow][j]);
                }
            }
        }


        double x[5] = { 0 };
        double x_old[5] = { 0 };
        double x_new[5] = { 0 };
        double error[5] = { 0 };

        int iteration = 0;
        bool converged = false;
        char result = 'F';


        cout << fixed << setprecision(6);


        cout << "\n";
        cout << "------------------------------------------------------------------------------------------------------------------" << endl;


        cout << "||  k  ||";
        for (int i = 0; i < n; i++) {
            char var;
            if (i == 0) var = 'x';
            else if (i == 1) var = 'y';
            else if (i == 2) var = 'z';
            else if (i == 3) var = 'w';
            else var = 'v';

            cout << "      " << var << "      ||";
        }
        for (int i = 0; i < n; i++) {
            char var;
            if (i == 0) var = 'x';
            else if (i == 1) var = 'y';
            else if (i == 2) var = 'z';
            else if (i == 3) var = 'w';
            else var = 'v';

            cout << "     e_" << var << "    ||";
        }
        cout << " Result ||" << endl;

        cout << "------------------------------------------------------------------------------------------------------------------" << endl;


        cout << "||  " << iteration << "  ||";
        for (int i = 0; i < n; i++) {
            cout << " " << setw(10) << 0.000000 << " ||";
        }
        for (int i = 0; i < n; i++) {
            cout << " " << setw(10) << 0.000000 << " ||";
        }
        cout << "    F    ||" << endl;
        iteration++;


        while (!converged && iteration < MAX_ITERATIONS) {

            //Pag-save sa Current Values
            for (int i = 0; i < n; i++) {
                x_old[i] = x[i];
            }


            for (int i = 0; i < n; i++) {
                double sum = matrix[i][n];

                for (int j = 0; j < n; j++) {
                    if (j != i) { // Subtract all terms except the current variable
                        sum = sum - matrix[i][j] * x_old[j];
                    }
                }


                x_new[i] = sum / matrix[i][i]; // divide sa coefficient sa current variable


                error[i] = fabs(x_new[i] - x_old[i]);
            }


            for (int i = 0; i < n; i++) {
                x[i] = x_new[i]; // tig-update sa current values
            }


            cout << "||  " << iteration << "  ||";
            for (int i = 0; i < n; i++) {
                cout << " " << setw(10) << x[i] << " ||";
            }
            for (int i = 0; i < n; i++) {
                cout << " " << setw(10) << error[i] << " ||";
            }


            converged = true;
            for (int i = 0; i < n; i++) {
                if (error[i] >= TOLERANCE) {
                    converged = false;
                    break;
                }
            }

            result = (converged ? 'T' : 'F');
            cout << "    " << result << "    ||" << endl;

            iteration++;
        }

        cout << "------------------------------------------------------------------------------------------------------------------" << endl;


        cout << "\nResults (Jacobi Method)" << endl;
        cout << "-----------------------" << endl;
        for (int i = 0; i < n; i++) {
            char var;
            if (i == 0) var = 'x';
            else if (i == 1) var = 'y';
            else if (i == 2) var = 'z';
            else if (i == 3) var = 'w';
            else var = 'v';

            cout << var << " = " << x[i] << endl;
        }


       


    } while (true);

    return;
}