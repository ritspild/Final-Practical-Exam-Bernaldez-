#include <iostream>
#include <iomanip>
#include <cmath>
#include <conio.h>
#include "Header.h"

using namespace std;

void gaussianElimination(int n)
{
    double a[5][6];

    cout << "\nEnter coefficients:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Equation " << i + 1 << "(Ax + By + Cz = D): ";
        for (int j = 0; j <= n; j++)
        {
            cout << "\n";
            cin >> a[i][j];
        }
    }

    cout << "\nNormalize\n";


    for (int i = 0; i < n; i++)
    {
        double pivot = a[i][i];

        for (int j = 0; j <= n; j++)
            a[i][j] /= pivot;


        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c <= n; c++)
            {
                if (c == n)
                    cout << "\t|\t";
                cout << fixed << setprecision(2) << a[r][c] << "\t";
            }
            cout << endl;
        }

        cout << "\nEliminate\n";

        for (int k = i + 1; k < n; k++)
        {
            double factor = a[k][i];
            for (int j = 0; j <= n; j++)
                a[k][j] -= factor * a[i][j];
        }


        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c <= n; c++)
            {
                if (c == n)
                    cout << "\t|\t";
                cout << fixed << setprecision(2) << a[r][c] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }


    double x[5];
    for (int i = n - 1; i >= 0; i--)
    {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++)
            x[i] -= a[i][j] * x[j];
    }

    cout << "Results:\n";
    for (int i = 0; i < n; i++)
        cout << char('x' + i) << " = " << fixed << setprecision(0) << x[i] << endl;
}

void GaussianMethod ()
{
    int choice;
    cout << "\t\tGaussian Elimination\n";
    cout << "Solutions to System of Linear Equation\n";
    cout << "[1] Equations 2 Unknowns\n";
    cout << "[2] Equations 3 Unknowns\n";
    cout << "[3] Equations 4 Unknowns\n";
    cout << "[4] Equations 5 Unknowns\n";
    cout << "[0] Back\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1: gaussianElimination(2); break;
    case 2: gaussianElimination(3); break;
    case 3: gaussianElimination(4); break;
    case 4: gaussianElimination(5); break;
    case 0: return;
    default:
        cout << "Invalid choice.\n";
    }
  


}