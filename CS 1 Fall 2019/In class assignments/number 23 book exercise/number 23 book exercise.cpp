// number 23 book exercise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int choice;

	int A1, A2, A3;
	int Radius, length, width, base, height, area; 
	const float PI = 3.14159;
	const float r = Radius;
	

	cout << "\t\tGeometry Calculator\n\n"
		 << "1. Calculate the Area of a Circle\n"
		 << "2. Calculate the Area of a Rectangle\n"
		 << "3. Calculate the Area of a Triangle\n"
		 << "4. Quit\n\n"
		 << "Enter your Choice (1-4) ";
	cin >> choice;

	switch (choice)
	{
	case '1': cout << "What is the Radius of the Circle?\n";
		A1 = PI * r * r;
		cout << A1;
		break;
	case '2': cout << "What is the Length of the Rectangle?";
		cin >> length;
		cout << "What is the Width of the Rectangle?";
		cin >> width;
		A2 = length * width;
		cout << A2;
		break;
	case '3': cout << "What is the base of the Triangle?";
		cin >> base;
		cout << "What is the height of the Triangle?";
		cin >> height;
		A3 = base * height * .5;
		cout << A3;
		break;
	case '4': cout << "Quiting the program";
		break;
	}
				 
		
			  
	
	


	


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
