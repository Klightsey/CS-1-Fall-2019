// Tip Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	float bill, tip, tax;
	float total;
	string your_name;
	string rest_name;

	cout << "Enter your first name: ";
	cin >> your_name;
	cout << endl;

	cout << "Enter the name of the restaurant: ";
	cin >> rest_name;
	cout << endl;

	cout << "Enter your total bill: " << '$';
	cin >> bill;
	cout << endl;

	cout << "Enter your tip as a decimal: ";
	cin >> tip;
	cout << endl;

	cout << "Enter the tax rate as a decimal: ";
	cin >> tax;
	cout << endl;

	total = bill * tip + bill * tax + bill;
	cout << your_name << " your total bill for " << rest_name << " is " << '$' << total;








}




