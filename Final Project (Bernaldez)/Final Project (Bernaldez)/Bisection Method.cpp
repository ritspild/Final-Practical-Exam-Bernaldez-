#include <iomanip>
#include <iostream>
#include <cmath>
#include "Header.h"

using namespace std;

void Bisection() {
	double A, B, C, D;
	double x_pos, x_min;
	double TOL = 0.00001;

	cout << "\tBisection Method" << endl;
	cout << "Enter a value of A: ";
	system("color 01");
	cin >> A;
	cout << "Enter a value of B: ";
	system("color 02");
	cin >> B;
	cout << "Enter a value of C: ";
	system("color 03");
	cin >> C;
	cout << "Enter a value of D: ";
	system("color 04");
	cin >> D;

	cout << endl << A << "x^3 + " << B << "x^2 + " << C << "x + " << D << endl << endl;

	cout << "Enter a value of X k-positive: ";
	system("color 05");
	cin >> x_pos;
	cout << "Enter a value of X k-minus: ";
	system("color 06");
	cin >> x_min;

	double f_pos = A * pow(x_pos, 3) + B * pow(x_pos, 2) + C * x_pos + D;
	double f_min = A * pow(x_min, 3) + B * pow(x_min, 2) + C * x_min + D;

	if (f_min * f_pos > 0) {
		cout << "Error: No root in interval!\n";


	}

	cout << endl << "X k-positive: " << x_pos << "\t\tX k-minus: " << x_min << endl << endl;

	cout << "________________________________________________________________________________________________________________" << endl;
	cout << left << setw(5) << "K" << setw(10) << "|"
		<< setw(20) << "Xk-positve" << setw(10) << "|"
		<< setw(20) << "Xk-minus" << setw(10) << "|"
		<< setw(20) << "XK+1" << setw(10) << "|"
		<< setw(10) << "Error          ";
	cout << "________________________________________________________________________________________________________________" << endl;

	double xplus1, f_mid, function;
	int i = 0;
	while (true) {
		system("color b5");
		xplus1 = (x_pos + x_min) / 2;
		f_mid = A * pow(xplus1, 3) + B * pow(xplus1, 2) + C * xplus1 + D;

		function = fabs(x_pos - x_min) / 2;
		cout << left << setw(5) << i << setw(10) << "|"
			<< setw(20) << x_pos << setw(10) << "|"
			<< setw(20) << x_min << setw(10) << "|"
			<< setw(20) << xplus1 << setw(10);

		if (function < TOL) {
			cout << " True\n";
			break;

		}
		else {
			cout << " False\n";

		}

		if (f_min * f_mid < 0) {
			x_pos = xplus1;
			f_pos = f_mid;

		}
		else {
			x_min = xplus1;
			f_min = f_mid;

		}

		i++;
		if (i > 100) {
			cout << "\nMaximum iterations reached (100)!" << endl;
			break;
		}

	}

	cout << "=====================================================================================\n";
	cout << "\nFinal root: " << xplus1 << endl;
	cout << "Final error: " << function << endl;


}