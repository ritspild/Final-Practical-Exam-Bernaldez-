#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <thread>
#include "Header.h"

using namespace std;


void GaussSeidel() {
    int choice;
    double TOLERANCE = 0.00001;
    int MAX_ITERATIONS = 100;

    do {

        cout << "\n=====================================" << endl;
        cout << "      GAUSS-SEIDEL METHOD           ||" << endl;
        cout << "=====================================" << endl;
        cout << "[1] 2 Equations 2 Unknowns          ||" << endl;
        cout << "[2] 3 Equations 3 Unknowns          ||" << endl;
        cout << "[3] 4 Equations 4 Unknowns          ||" << endl;
        cout << "[4] 5 Equations 5 Unknowns          ||" << endl;
        cout << "[0] Back                            ||" << endl;
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


        double matrix[5][6] = { 0 };  // Max 5 equations, 6 columns


        for (int i = 0; i < n; i++) {
            cout << "Equation " << i + 1 << " (";
            for (int j = 0; j < n; j++) {
                char var;
                if (j == 0) var = 'Ax';
                else if (j == 1) var = 'By';
                else if (j == 2) var = 'Cz';
                else if (j == 3) var = '....';
                else var = '...';

                cout << var;
                if (j < n - 1) cout << " + ";
            }
            cout << " = D): ";



            for (int j = 0; j < n + 1; j++) {
                cin >> matrix[i][j];
            }
        }


        // partial pivoting 
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
            if (i == 0) var = 'Ax';
            else if (i == 1) var = 'By';
            else if (i == 2) var = 'Cz';
            else if (i == 3) var = '...';
            else var = '...';

            cout << "      " << var << "      ||";
        }
        for (int i = 0; i < n; i++) {
            char var;
            if (i == 0) var = 'Ax';
            else if (i == 1) var = 'By';
            else if (i == 2) var = 'Cz';
            else if (i == 3) var = '...';
            else var = '...';

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

            // Save current values
            for (int i = 0; i < n; i++) {
                x_old[i] = x[i];
            }

            // Calculate new values
            for (int i = 0; i < n; i++) {
                double sum = matrix[i][n];


                for (int j = 0; j < n; j++) {
                    if (j != i) {
                        sum -= matrix[i][j] * x[j];
                    }
                }


                x[i] = sum / matrix[i][i];


                error[i] = fabs(x[i] - x_old[i]);
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


        cout << "\nResults" << endl;
        cout << "--------" << endl;
        for (int i = 0; i < n; i++) {
            char var;
            if (i == 0) var = 'Ax';
            else if (i == 1) var = 'By';
            else if (i == 2) var = 'Cz';
            else if (i == 3) var = '...';
            else var = '...';

            cout << var << " = " << x[i] << endl;
        }

    } while (true);

    return ;
}