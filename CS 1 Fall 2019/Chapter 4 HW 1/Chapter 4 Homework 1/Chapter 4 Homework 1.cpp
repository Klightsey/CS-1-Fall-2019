// Chapter 4 Homework 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
	int length, width, area1, area2;

	cout << "Length of rectangle A?";
	cin >> length;
	cout << "Width of rectangle A?";
	cin >> width;
	area1 = length * width;
	cout << " Rectangle A area: " << area1 << " square inches " << endl;
	

	cout << "Length of rectangle B?";
	cin >> length;
	cout << "Width of Rectangle B?";
	cin >> width;
	area2 = length * width;
	cout << " Rectangle B area: " << area2 << " square inches " << endl;
	
	if (area1 >= area2)
		cout << "Rectangle A is LARGER than Rectangle B";
	if (area1 <= area2)
		cout << "Rectangle A is not LARGER than Rectangle B";




}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu